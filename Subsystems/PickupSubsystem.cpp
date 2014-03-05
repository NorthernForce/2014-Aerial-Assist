#include "PickupSubsystem.h"
#include "../Commands/SetIntake.hpp"
#include "../Robotmap.h"

PickupSubsystem::PickupSubsystem(): 
	Subsystem("PickupSubsystem"),
	m_PickupJag(kPickupJaguar),
	m_PickupCyls(kPickupModule, kPickupRelay, Relay::kBothDirections)
{
	m_PickupCyls.Set(Relay::kReverse);
}

void PickupSubsystem::InitDefaultCommand() {
	SetDefaultCommand(new SetIntake<RETRACTED | STOPPED>);
}

void PickupSubsystem::init() {
	//m_PickupJag.SetSafetyEnabled(false);
}

void PickupSubsystem::SetIntakePosition(Position dir) {
	switch(dir) {
	case EXTEND:
		m_PickupCyls.Set(Relay::kForward);
		break;
	case RETRACT:
		m_PickupCyls.Set(Relay::kReverse);
		break;
	}
}

void PickupSubsystem::SetIntakeSpeed(float speed) {
	m_PickupJag.Set(-speed);
}
