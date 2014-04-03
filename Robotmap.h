#pragma once

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// #define LEFTMOTOR 1
// #define RIGHTMOTOR 2

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// #define RANGE_FINDER_PORT 1
// #define RANGE_FINDER_MODULE 1

 /*
  * @brief The button ports on the XBox Joystick, as interpreted by the cRIO.
  */

static const int kBallDataPort = 1726;

enum XBoxJoystickButtonPort
{
	kXBoxButtonA = 1,
	kXBoxButtonB = 2,
	kXBoxButtonX = 3,
	kXBoxButtonY = 4,
	kXBoxButtonLeft = 5,
	kXBoxButtonRight = 6,
	kXBoxButtonBack = 7,
	kXBoxButtonStart = 8,
	kXBoxButtonLeftJoystick = 9,
	kXBoxButtonRightJoystick = 10,
};

/*
 * @brief The button ports on the Attack 3 Joystick.
 */
enum Attack3JoystickPort
{
 	kAttackJoystickButtonTrigger = 1, 
 	kAttackJoystickButton2 = 2,
 	kAttackJoystickButton3 = 3,
 	kAttackJoystickButton4 = 4,
 	kAttackJoystickButton5 = 5,
 	kAttackJoystickButton6 = 6,
 	kAttackJoystickButton7 = 7,
 	kAttackJoystickButton8 = 8,
 	kAttackJoystickButton9 = 9,
 	kAttackJoystickButton10 = 10,
 	kAttackJoystickButton11 = 11,
	kAttackJoystickButton12 = 12,
};

enum JagCANAdress {
	
	kBackRightJaguar = 14,
	kFrontRightJaguar = 12,
	kBackLeftJaguar = 13,
	kFrontLeftJaguar = 11,
	kPickupJaguar = 15,
	
//	kBackRightJaguar = 8,
//	kFrontRightJaguar = 6,
//	kBackLeftJaguar = 7,
//	kFrontLeftJaguar = 5,
//	kPickupJaguar = 9,
};

enum JoystickPort {
    kDriverStickPort = 1,
    kManipulatorStickPort = 2,
};

enum RelayPort {
	kCompressorModule = 1,
	kCompressorRelay = 1,
	kShooterModule = 1,
	kShooterRelay = 3,
	kPickupModule = 1,
	kPickupRelay = 2,
};

enum DigitalIOPort {
	kCompressorSwitchModule = 1,
	kCompressorSwitch = 1,
	k_targetingUltrasonicSerialMode = 3,
	k_targetingUltrasonicOn = 2,
};

enum AnalogIOPort
{
	//k_MaxbotixUltrasonic = 1,
	k_targetingUltrasonic = 2,
	k_pressureChannel = 3,
};

enum SolenoidPort {
	kPickupSolenoid = 1,
};

static const float kDeadbandLimit = 0.01;
static const float kMaxDriveVoltage = 12.0;
static const float kMaxDriveRPM = 475.0;
static const float kRevsPerFoot = 12.0/(2.0*3.14159*3.0); /* 12in / (1ft * 2.0pi r(in)) */
static const int kEncoderPulsesPerRev = 256;
