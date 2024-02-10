// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#ifndef FLYWHEEL_H
#define FLYWHEEL_H
#include <frc/Encoder.h>
#include <frc/RobotController.h>
#include <frc/controller/PIDController.h>
#include <frc/controller/SimpleMotorFeedforward.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/sysid/SysIdRoutine.h>
#include <frc2/command/CommandPtr.h>
#include <rev/CANSparkMax.h>
#include "Constants.h"

class Flywheel : public frc2::SubsystemBase {
 public:
  Flywheel();
  frc2::CommandPtr SysIdQuasistatic(frc2::sysid::Direction direction);
  frc2::CommandPtr SysIdDynamic(frc2::sysid::Direction direction);

  private:
    rev::CANSparkMax m_AnglingMotor{Constants::kFlywheelAnglingMotor, rev::CANSparkMax::MotorType::kBrushless};
    rev::SparkAbsoluteEncoder *magEncoder;
    frc2::sysid::SysIdRoutine m_sysIdRoutine{
      frc2::sysid::Config{std::nullopt, std::nullopt, std::nullopt, std::nullopt},
      frc2::sysid::Mechanism{
          [this](units::volt_t driveVoltage) {
            m_AnglingMotor.SetVoltage(driveVoltage);},
          [this](frc::sysid::SysIdRoutineLog* log) {
            log->Motor("")
                .voltage(m_AnglingMotor.Get() * frc::RobotController::GetBatteryVoltage())
                .position(units::turn_t{magEncoder->GetPosition()})
                .velocity(units::turns_per_second_t{magEncoder->GetVelocity()});
          },
          this}};

};
#endif