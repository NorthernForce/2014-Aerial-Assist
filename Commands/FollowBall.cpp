#include "FollowBall.h"
#include "../Main.h"
#include <cmath>

FollowBall::FollowBall()
{
    Requires(&Main::getDrive());
    Requires(&Main::getBall());
}

void FollowBall::Initialize() {
	Main::getBall().reset();
	Main::getBall().StartFeedback();
	printf("Following Ball...\n");
}

void FollowBall::Execute() {
	float x,y,w;
	Main::getBall().getVel(&x,&y,&w);
    
    //Send joystick values to SmartDashboard
    SmartDashboard::PutNumber("Left Stick X Value: ", x); 
    SmartDashboard::PutNumber("Left Stick Y Value: ", y);
    SmartDashboard::PutNumber("Right Stick X Value: ", w);
    
    // Send command to drive subsystem
	//Main::getDrive().DriveMecanum(x, y, w);
    Main::getDrive().Drive(x, y, w);
    //Main::getDrive().DriveMecanum(0,0,0);
}

bool FollowBall::IsFinished() {
	return false;
}

void FollowBall::End() {
	Main::getBall().StopFeedback();
}

void FollowBall::Interrupted() {
	End();
}
