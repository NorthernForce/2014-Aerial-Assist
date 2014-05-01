#include "MecanumDrive.h"
#include "Joystick.h"
#include <math.h>

MecanumDrive::MecanumDrive(CANJaguar& m_frontLeft, CANJaguar& m_backLeft, CANJaguar& m_frontRight, CANJaguar& m_backRight) :
	SubsystemWithCommand<DriveWithJoystick>("MecanumDrive"),
	RobotDrive(m_frontLeft, m_backLeft, m_frontRight, m_backRight),
	/*
	m_frontLeft(kFrontLeftJaguar),
	m_frontRight(kFrontRightJaguar),
	m_backLeft(kBackLeftJaguar),
	m_backRight(kBackRightJaguar),
	*/
	flipped(false),
	majorAxisOnly(false)
{
}

void MecanumDrive::Init() {
	SetExpiration(0.25);
	m_safetyHelper->Feed();
}

void MecanumDrive::Drive(double x, double y, double w) {

	m_safetyHelper->Feed();
	if(flipped) {
		x = -x;
		y = -y;
	}
	
	if(majorAxisOnly) {
		if(fabs(x) > fabs(y)) {
			y = 0;
		} else {
			x = 0;
		}
	}
	
	uint8_t syncGroup = 0x80;
	
	switch(m_driveMode) {
	case PERCENT_VBUS:
	case SPEED:
		MecanumDrive_Cartesian(x,y,w);
		break;
	case POSITION:
		y = -y;
		double wheelSpeeds[kMaxNumberOfMotors];
		wheelSpeeds[kFrontLeftMotor]  = ( x + y + w)*kRevsPerFoot;
		wheelSpeeds[kFrontRightMotor] = (-x + y - w)*kRevsPerFoot;
		wheelSpeeds[kRearLeftMotor]   = (-x + y + w)*kRevsPerFoot;
		wheelSpeeds[kRearRightMotor]  = ( x + y - w)*kRevsPerFoot;

		m_frontLeftMotor->Set(wheelSpeeds[kFrontLeftMotor] * m_invertedMotors[kFrontLeftMotor], syncGroup);
		m_frontRightMotor->Set(wheelSpeeds[kFrontRightMotor] * m_invertedMotors[kFrontRightMotor], syncGroup);
		m_rearLeftMotor->Set(wheelSpeeds[kRearLeftMotor] * m_invertedMotors[kRearLeftMotor], syncGroup);
		m_rearRightMotor->Set(wheelSpeeds[kRearRightMotor] * m_invertedMotors[kRearRightMotor], syncGroup);

		CANJaguar::UpdateSyncGroup(syncGroup);
			
		break;
	default:
		break;
	}
	
	n++;
	if(n%5 == 0) 
	{
		/*
		SmartDashboard::PutNumber("M4 Command", m_frontLeft.Get());
		SmartDashboard::PutNumber("M4 Output",  m_frontLeft.GetPosition());
		//SmartDashboard::PutNumber("M4 Voltage", m_frontLeft.GetOutputVoltage());
		//SmartDashboard::PutNumber("M4 VBus", m_frontLeft.GetBusVoltage());
		//SmartDashboard::PutBoolean("M4 Alive",  frontLeft_alive == 0);
		
		SmartDashboard::PutNumber("M2 Command", m_frontRight.Get());
		SmartDashboard::PutNumber("M2 Output",  m_frontRight.GetPosition());
		//SmartDashboard::PutNumber("M2 Voltage", m_frontRight.GetOutputVoltage());
		//SmartDashboard::PutNumber("M2 VBus", m_frontRight.GetBusVoltage());
		//SmartDashboard::PutBoolean("M2 Alive",  frontRight_alive == 0);
		
		SmartDashboard::PutNumber("M3 Command", m_backLeft.Get());
		SmartDashboard::PutNumber("M3 Output",  m_backLeft.GetPosition());
		//SmartDashboard::PutNumber("M3 Voltage", m_backLeft.GetOutputVoltage());
		//SmartDashboard::PutNumber("M3 VBus", m_backLeft.GetBusVoltage());	
		//SmartDashboard::PutBoolean("M3 Alive",  backLeft_alive == 0);
		
		SmartDashboard::PutNumber("M1 Command", m_backRight.Get());
		SmartDashboard::PutNumber("M1 Output",  m_backRight.GetPosition());
		//SmartDashboard::PutNumber("M1 Voltage", m_backRight.GetOutputVoltage());
		//SmartDashboard::PutNumber("M1 VBus", m_backRight.GetBusVoltage());
		//SmartDashboard::PutBoolean("M1 Alive",  backRight_alive == 0);
		*/
		/*
		SmartDashboard::PutNumber("M1 Pos", m_backRight.GetPosition());
		SmartDashboard::PutNumber("M2 Pos", m_frontRight.GetPosition());
		SmartDashboard::PutNumber("M3 Pos", m_backLeft.GetPosition());
		SmartDashboard::PutNumber("M4 Pos", m_frontLeft.GetPosition());
		*/
	}
}

void MecanumDrive::SetDriveMode(DriveMode mode) {
	double P,I,D;
	
	switch(mode) {
	case PERCENT_VBUS:
		SetInvertedMotor(RobotDrive::kFrontLeftMotor,   true);
		SetInvertedMotor(RobotDrive::kFrontRightMotor, false);
		SetInvertedMotor(RobotDrive::kRearLeftMotor,    true);
		SetInvertedMotor(RobotDrive::kRearRightMotor,  false);	    
		// Output values for kPercentVbus mode are -1..1, so
		// max output should be 1.0
		SetMaxOutput(1.0);
		// Disable encoder control.
		((CANJaguar*)m_frontLeftMotor)->DisableControl();
		((CANJaguar*)m_rearLeftMotor)->DisableControl();
		((CANJaguar*)m_frontRightMotor)->DisableControl();
		((CANJaguar*)m_rearRightMotor)->DisableControl();
		// Change mode to kPercentVbus.
		((CANJaguar*)m_frontLeftMotor)->ChangeControlMode(CANJaguar::kPercentVbus);
		((CANJaguar*)m_rearLeftMotor)->ChangeControlMode(CANJaguar::kPercentVbus);
		((CANJaguar*)m_frontRightMotor)->ChangeControlMode(CANJaguar::kPercentVbus);
		((CANJaguar*)m_rearRightMotor)->ChangeControlMode(CANJaguar::kPercentVbus);
		break;
	case SPEED:
		// When encoders are enabled, all motors must be inverted from
		// what they normaly would be.
		SetInvertedMotor(RobotDrive::kFrontLeftMotor, false);
		SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
		SetInvertedMotor(RobotDrive::kRearLeftMotor,  false);
		SetInvertedMotor(RobotDrive::kRearRightMotor,  true);
				
		SetMaxOutput(kMaxDriveRPM);
		
		// Disable encoders, if alread enabled.
		// Not sure this is necessary.
		((CANJaguar*)m_frontLeftMotor)->DisableControl();
		((CANJaguar*)m_rearLeftMotor)->DisableControl();
		((CANJaguar*)m_frontRightMotor)->DisableControl();
		((CANJaguar*)m_rearRightMotor)->DisableControl();
				
		// Max voltage should be 12V (Robot has 12V battery).
		((CANJaguar*)m_frontLeftMotor)->ConfigMaxOutputVoltage(kMaxDriveVoltage);
		((CANJaguar*)m_rearLeftMotor)->ConfigMaxOutputVoltage(kMaxDriveVoltage);
		((CANJaguar*)m_frontRightMotor)->ConfigMaxOutputVoltage(kMaxDriveVoltage);
		((CANJaguar*)m_rearRightMotor)->ConfigMaxOutputVoltage(kMaxDriveVoltage);
				
		// To use the encoders, we need to be in either
		// speed mode or position mode. For driving the 
		// robot, speed mode makes more sense.
		((CANJaguar*)m_frontLeftMotor)->ChangeControlMode(CANJaguar::kSpeed);
		((CANJaguar*)m_rearLeftMotor)->ChangeControlMode(CANJaguar::kSpeed);
		((CANJaguar*)m_frontRightMotor)->ChangeControlMode(CANJaguar::kSpeed);
		((CANJaguar*)m_rearRightMotor)->ChangeControlMode(CANJaguar::kSpeed);
		// Fetch PID gains from the smart dashboard.
		P = 0.5;
		I = 0.01;
		D = 0.0;
		((CANJaguar*)m_frontLeftMotor)->SetPID(-P, -I, -D);
		((CANJaguar*)m_rearLeftMotor)->SetPID(-P, -I, -D);
		((CANJaguar*)m_frontRightMotor)->SetPID(-P, -I, -D);
		((CANJaguar*)m_rearRightMotor)->SetPID(-P, -I, -D);
				
		((CANJaguar*)m_frontLeftMotor)->SetSpeedReference(CANJaguar::kSpeedRef_QuadEncoder);
		((CANJaguar*)m_rearLeftMotor)->SetSpeedReference(CANJaguar::kSpeedRef_QuadEncoder);
		((CANJaguar*)m_frontRightMotor)->SetSpeedReference(CANJaguar::kSpeedRef_QuadEncoder);
		((CANJaguar*)m_rearRightMotor)->SetSpeedReference(CANJaguar::kSpeedRef_QuadEncoder);
					
		// Set encoder pulses per rev
		((CANJaguar*)m_frontLeftMotor)->ConfigEncoderCodesPerRev(kEncoderPulsesPerRev);
		((CANJaguar*)m_rearLeftMotor)->ConfigEncoderCodesPerRev(kEncoderPulsesPerRev);
		((CANJaguar*)m_frontRightMotor)->ConfigEncoderCodesPerRev(kEncoderPulsesPerRev);
		((CANJaguar*)m_rearRightMotor)->ConfigEncoderCodesPerRev(kEncoderPulsesPerRev);
		// Enable encoder control with the parameters above.
		((CANJaguar*)m_frontLeftMotor)->EnableControl();
		((CANJaguar*)m_rearLeftMotor)->EnableControl();
		((CANJaguar*)m_frontRightMotor)->EnableControl();
		((CANJaguar*)m_rearRightMotor)->EnableControl();
		break;
	case POSITION:
		// When encoders are enabled, all motors must be inverted from
		// what they normaly would be.
		SetInvertedMotor(RobotDrive::kFrontLeftMotor, false);
		SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
		SetInvertedMotor(RobotDrive::kRearLeftMotor,  false);
		SetInvertedMotor(RobotDrive::kRearRightMotor,  true);
			
		// Disable encoders, if alread enabled.
		// Not sure this is necessary.
		((CANJaguar*)m_frontLeftMotor)->DisableControl();
		((CANJaguar*)m_rearLeftMotor)->DisableControl();
		((CANJaguar*)m_frontRightMotor)->DisableControl();
		((CANJaguar*)m_rearRightMotor)->DisableControl();
			
		// Max voltage should be 12V (Robot has 12V battery).
		((CANJaguar*)m_frontLeftMotor)->ConfigMaxOutputVoltage(kMaxDriveVoltage);
		((CANJaguar*)m_rearLeftMotor)->ConfigMaxOutputVoltage(kMaxDriveVoltage);
		((CANJaguar*)m_frontRightMotor)->ConfigMaxOutputVoltage(kMaxDriveVoltage);
		((CANJaguar*)m_rearRightMotor)->ConfigMaxOutputVoltage(kMaxDriveVoltage);
		
		// To use the encoders, we need to be in either
		// speed mode or position mode. For driving the 
		// robot, speed mode makes more sense.
		((CANJaguar*)m_frontLeftMotor)->ChangeControlMode(CANJaguar::kPosition);
		((CANJaguar*)m_rearLeftMotor)->ChangeControlMode(CANJaguar::kPosition);
		((CANJaguar*)m_frontRightMotor)->ChangeControlMode(CANJaguar::kPosition);
		((CANJaguar*)m_rearRightMotor)->ChangeControlMode(CANJaguar::kPosition);
		// Fetch PID gains from the smart dashboard.
		//P = SmartDashboard::GetNumber("Drive P");
		//I = SmartDashboard::GetNumber("Drive I");
		//D = SmartDashboard::GetNumber("Drive D");
		P = 220.0;
		I = 0.01;
		D = 0.0;
		((CANJaguar*)m_frontLeftMotor)->SetPID(-P, -I, -D);
		((CANJaguar*)m_rearLeftMotor)->SetPID(-P, -I, -D);
		((CANJaguar*)m_frontRightMotor)->SetPID(-P, -I, -D);
		((CANJaguar*)m_rearRightMotor)->SetPID(-P, -I, -D);
		
		((CANJaguar*)m_frontLeftMotor)->SetPositionReference(CANJaguar::kPosRef_QuadEncoder);
		((CANJaguar*)m_rearLeftMotor)->SetPositionReference(CANJaguar::kPosRef_QuadEncoder);
		((CANJaguar*)m_frontRightMotor)->SetPositionReference(CANJaguar::kPosRef_QuadEncoder);
		((CANJaguar*)m_rearRightMotor)->SetPositionReference(CANJaguar::kPosRef_QuadEncoder);
			
		// Set encoder pulses per rev
		((CANJaguar*)m_frontLeftMotor)->ConfigEncoderCodesPerRev(kEncoderPulsesPerRev);
		((CANJaguar*)m_rearLeftMotor)->ConfigEncoderCodesPerRev(kEncoderPulsesPerRev);
		((CANJaguar*)m_frontRightMotor)->ConfigEncoderCodesPerRev(kEncoderPulsesPerRev);
		((CANJaguar*)m_rearRightMotor)->ConfigEncoderCodesPerRev(kEncoderPulsesPerRev);
		// Enable encoder control with the parameters above.
		((CANJaguar*)m_frontLeftMotor)->EnableControl();
		((CANJaguar*)m_rearLeftMotor)->EnableControl();
		((CANJaguar*)m_frontRightMotor)->EnableControl();
		((CANJaguar*)m_rearRightMotor)->EnableControl();
			
		break;
	default:
		break;
	}
	
	m_driveMode = mode;
}

void MecanumDrive::SetSafetyEnabled(bool enabled) { RobotDrive::SetSafetyEnabled(enabled); }
void MecanumDrive::Flip() { flipped = !flipped; }
void MecanumDrive::SetMajorAxisMode(bool on) { majorAxisOnly = on; }

double MecanumDrive::GetYVel() {
	switch(m_driveMode) {
	case SPEED:
	case POSITION:
		return (((CANJaguar*)m_frontLeftMotor)->GetSpeed() - ((CANJaguar*)m_frontRightMotor)->GetSpeed() + ((CANJaguar*)m_rearLeftMotor)->GetSpeed() - ((CANJaguar*)m_rearRightMotor)->GetSpeed()) / 4.0 / kMaxDriveRPM;
	default:
		return (-((CANJaguar*)m_frontLeftMotor)->GetOutputVoltage() + ((CANJaguar*)m_frontRightMotor)->GetOutputVoltage() - ((CANJaguar*)m_rearLeftMotor)->GetOutputVoltage() + ((CANJaguar*)m_rearRightMotor)->GetOutputVoltage()) / 4.0 / kMaxDriveVoltage;
	}
}

void MecanumDrive::Feed() {
	m_safetyHelper->Feed();
}
