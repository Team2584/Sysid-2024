// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#ifndef CONSTANTS_H
#define CONSTANTS_H
/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

#define FLYWHEEL_MAG_ENCODER_OFFSET -0.1525;

namespace Constants {

inline constexpr int kDriverControllerPort = 0;
inline constexpr int kElevatorMotorUpDownPort = 25;
inline constexpr int kFlywheelMotor1 = 15;
inline constexpr int kFlywheelMotor2 = 16;
inline constexpr int kFlywheelAnglingMotor = 20;
inline constexpr int kIntakeAnglingMotor = 30;

inline constexpr int kFLTop = 21;
inline constexpr int kFLbottom = 22;







}  // namespace OperatorConstants
#endif