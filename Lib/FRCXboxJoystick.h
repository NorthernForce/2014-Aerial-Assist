#pragma once
#include <WPILib.h>
#include "../Robotmap.h"
#include "Joystick.h"
#include "SafeButton.h"
/*
 * @brief This class is the driver for the XBox Joystick
 * that we use at competition to control the robot.
 * All of the values returned by this class are 
 * already adjusted for the deadband in the controller itself.
 * 
 * This class also contains JoystickButtons for all of the 
 * buttons that are available on the XBox joystick itself. 
 * These buttons can be assigned by calling [stick].[button].WhenPressed().
 * 
 * @author Arthur Lockman
 */
class FRCXboxJoystick: public Joystick {
private:
    float Deadband;
    void CalculateDeadband();
	float DeadbandAdjust(float);
	float GetX(JoystickHand);
	float GetY(JoystickHand);
	
public:
	FRCXboxJoystick(int port);
	
	float GetLeftStickY();
	float GetLeftStickX();
	float GetRightStickY();
	float GetRightStickX();
	float GetTrigger();
	
	bool GetAButton();
	bool GetBButton();
	bool GetXButton();
	bool GetYButton();
	bool GetStartButton();
	bool GetBackButton();
	bool GetLeftBumper();
	bool GetRightBumper();
	
    SafeButton A;
    SafeButton B;
    SafeButton X;
    SafeButton Y;
    SafeButton Back;
    SafeButton Start;
    SafeButton LeftBumper;
    SafeButton RightBumper;
};
