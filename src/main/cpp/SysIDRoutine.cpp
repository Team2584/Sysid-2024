#include "SysIDRoutine.h"
#include "Constants.h"
#include <frc2/command/Command.h>
#include <frc2/command/sysid/SysIdRoutine.h>

SysIdRoutineBot::SysIdRoutineBot() {
  ConfigureBindings();
}

void SysIdRoutineBot::ConfigureBindings() {
  // Using bumpers as a modifier and combining it with the buttons so that we
  // can have both sets of bindings at once
  (m_driverController.A() && m_driverController.RightBumper())
      .WhileTrue(m_elevator.SysIdQuasistatic(frc2::sysid::Direction::kForward));
  (m_driverController.B() && m_driverController.RightBumper())
      .WhileTrue(m_elevator.SysIdQuasistatic(frc2::sysid::Direction::kReverse));
  (m_driverController.X() && m_driverController.RightBumper())
      .WhileTrue(m_elevator.SysIdDynamic(frc2::sysid::Direction::kForward));
  (m_driverController.Y() && m_driverController.RightBumper())
      .WhileTrue(m_elevator.SysIdDynamic(frc2::sysid::Direction::kReverse));

  (m_driverController.A() && m_driverController.LeftBumper())
      .WhileTrue(m_flywheel.AnglerSysIdQuasistatic(frc2::sysid::Direction::kForward));
  (m_driverController.B() && m_driverController.LeftBumper())
      .WhileTrue(m_flywheel.AnglerSysIdQuasistatic(frc2::sysid::Direction::kReverse));
  (m_driverController.X() && m_driverController.LeftBumper())
      .WhileTrue(m_flywheel.AnglerSysIdDynamic(frc2::sysid::Direction::kForward));
  (m_driverController.Y() && m_driverController.LeftBumper())
      .WhileTrue(m_flywheel.AnglerSysIdDynamic(frc2::sysid::Direction::kReverse));

  (m_driverController.A() && m_driverController.RightTrigger())
      .WhileTrue(m_flywheel.SysIdQuasistatic(frc2::sysid::Direction::kForward));
  (m_driverController.B() && m_driverController.RightTrigger())
      .WhileTrue(m_flywheel.SysIdQuasistatic(frc2::sysid::Direction::kReverse));
  (m_driverController.X() && m_driverController.RightTrigger())
      .WhileTrue(m_flywheel.SysIdDynamic(frc2::sysid::Direction::kForward));
  (m_driverController.Y() && m_driverController.RightTrigger())
      .WhileTrue(m_flywheel.SysIdDynamic(frc2::sysid::Direction::kReverse));

    
}
