/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include <iostream>

#include "Arm.h"
#include "../RobotMap.h"
#include "ctre/Phoenix.h"

Arm::Arm() : Subsystem("Arm"), arm(new TalonSRX(ARM_MOTOR_PORT)) {
	arm->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Absolute, 0, 10);
}

void Arm::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new MoveArm());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
TalonSRX* Arm::getArm() {
	return arm;
}

void Arm::moveArm(double speed) {
	arm->Set(ControlMode::PercentOutput, speed);
}

void Arm::resetEncoder() {

}

double Arm::getRelativePosition() {
	double relative = arm->GetSensorCollection().GetQuadraturePosition()/4096 * 10;//4096 ticks per rev, 10 inch circumference
	std::cout << relative << std::endl;
	return relative;
}
