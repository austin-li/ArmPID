/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include <cmath>

#include "ArmTop.h"
#include "Robot.h"

ArmTop::ArmTop(double _kP, double _kI, double _kD, double _setPoint): kP(_kP), kI(_kI), kD(_kD), setPoint(_setPoint), error(100) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::arm);
}

// Called just before this Command runs the first time
void ArmTop::Initialize() {
	Robot::arm->resetEncoder();
}

// Called repeatedly when this Command is scheduled to run
void ArmTop::Execute() {
	double position = Robot::arm->getRelativePosition();

	error = setPoint - position;

	integral += error;

	double derivative = prevError;
	prevError = error;

	double power = error * kP + integral * kI + derivative * kD;
	Robot::arm->moveArm(power);
}

// Make this return true when this Command no longer needs to run execute()
bool ArmTop::IsFinished() {
	return abs(error) < 2;
}

// Called once after isFinished returns true
void ArmTop::End() {
	Robot::arm->moveArm(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmTop::Interrupted() {

}
