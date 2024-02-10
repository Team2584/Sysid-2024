// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Flywheel.h"
#include <frc2/command/Commands.h>
#include <units/angle.h>
#include <units/voltage.h>

Flywheel::Flywheel() {
  
}

frc2::CommandPtr Flywheel::SysIdQuasistatic(frc2::sysid::Direction direction){
    return m_sysIdRoutine.Quasistatic(direction);
}
frc2::CommandPtr Flywheel::SysIdDynamic(frc2::sysid::Direction direction){
    return m_sysIdRoutine.Dynamic(direction);
}
