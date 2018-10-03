/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include <WPILib.h>
#include "RobotMap.h"

#include "Commands/ArmTop.h"

OI::OI(): leftStick(new Joystick(LEFT_JOYSTICK_PORT)),
		rightStick(new Joystick(RIGHT_JOYSTICK_PORT)),
		armStick(new Joystick(ARM_JOYSTICK_PORT)),
		armTop(new JoystickButton(armStick, 1)) {
	// Process operator interface input here.
	armTop->WhenPressed(new ArmTop(0.1, 0, 0, 1000));
}

Joystick* OI::getLeft() {
	return leftStick;
}

Joystick* OI::getRight() {
	return rightStick;
}

Joystick* OI::getArm() {
	return armStick;
}
