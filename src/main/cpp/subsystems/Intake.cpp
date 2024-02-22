// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Intake.h"
#include <frc2/command/Commands.h>
#include <units/angle.h>
#include <units/voltage.h>

Intake::Intake() {
    
}

frc2::CommandPtr Intake::SysIdQuasistatic(frc2::sysid::Direction direction){
    return m_IntakesysIdRoutine.Quasistatic(direction);
}
frc2::CommandPtr Intake::SysIdDynamic(frc2::sysid::Direction direction){
    return m_IntakesysIdRoutine.Dynamic(direction);
}
