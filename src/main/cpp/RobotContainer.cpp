// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <utility>

#include <frc2/command/button/Trigger.h>
#include <frc/controller/PIDController.h>
#include <frc/controller/RamseteController.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc/trajectory/constraint/DifferentialDriveVoltageConstraint.h>
#include <frc2/command/Commands.h>
#include <frc2/command/RamseteCommand.h>
#include <frc2/command/button/JoystickButton.h>

#include "commands/Autos.h"
//#include "commands/TurnTo.h"
//#include "commands/ExampleCommand.h"
#include "commands/Teleop.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here
  // Configure the button bindings

  // m_chooser.SetDefaultOption("Simple Auto", m_simpleAuto.get());
  // m_chooser.AddOption("Complex Auto", m_NiceAuto.get());
  // //Add Auto to dash
  // frc::Shuffleboard::GetTab("Autonomous").Add(m_chooser);
  
  //Add subsystems to dash
  // frc::Shuffleboard::GetTab("DriveTrain").Add(pchsDrive);
  // frc::Shuffleboard::GetTab("Intake").Add(pchsIntake);


  //Log Shuffle events for commands
  //Make per whatever u want
  //Will probably only do it for scoring commands
//   frc2::CommandScheduler::GetInstance().OnCommandInitialize(
//       [](const frc2::Command& command) {
//         frc::Shuffleboard::AddEventMarker(
//             "Command initialized", command.GetName(),
//             frc::ShuffleboardEventImportance::kNormal);
//       });
  ConfigureBindings();
  
  pchsDrive.SetDefaultCommand(Teleop(
    &pchsDrive, [this] {return -m_driverController.GetLeftY();},
    [this] {return m_driverController.GetRightX();}));
}

void RobotContainer::ConfigureBindings() {
    //Extend intake and run 
    m_driverController.LeftBumper().OnTrue(pchsIntake.IntakeCommand());
    //Retract intake + stop
    m_driverController.RightBumper().OnTrue(pchsIntake.RetractCommand());
    
    //Outtake 
    m_driverController.LeftTrigger().OnTrue(pchsIntake.OuttakeCommand());
}

// frc2::Command* RobotContainer::GetAutonomousCommand() {
//   // An example command will be run in autonomous
  
//   //return m_chooser.GetSelected();
// }
