#pragma once
#ifndef SYSIDROUTINE_H
#define SYSIDROUTINE_H

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>

#include "Constants.h"
#include "subsystems/Elevator.h"
#include "subsystems/Flywheel.h"
#include "subsystems/Intake.h"

class SysIdRoutineBot {
 public:
  SysIdRoutineBot();

  frc2::CommandPtr GetAutonomousCommand();

 private:
  void ConfigureBindings();
  frc2::CommandXboxController m_driverController{
      Constants::kDriverControllerPort};
  Elevator m_elevator;
  Flywheel m_flywheel;
  Intake m_intake;
};
#endif