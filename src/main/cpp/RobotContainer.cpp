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
  frc::Shuffleboard::GetTab("Intake").Add(pchsIntake);

  // frc::Shuffleboard::GetTab("Intake").Add(pchsIntake);
  ConfigureBindings();
  
  pchsDrive.SetDefaultCommand(Teleop(
    &pchsDrive, [this] {return m_driverController.GetLeftY();},
    [this] {return -m_driverController.GetRightX();}));

  //pchsElevator.SetDefaultCommand(Elevator::ElevatorStop());
}

void RobotContainer::ConfigureBindings() {
    //m_loop.Bind(pchsIntake.mainIntake.Set(frc::DoubleSolenoid::kForward));
    
    m_operatorPannel.Button(1).OnTrue(pchsIntake.IntakeCommand());
    //Retract intake + stop
    m_operatorPannel.Button(2).OnTrue(pchsIntake.RetractCommand());//Swivel Fwd

    m_operatorPannel.Button(3).OnTrue(pchsIntake.FeederStation());

    m_operatorPannel.Button(4).OnTrue(pchsSwivel.SwivelFwd());
    m_operatorPannel.Button(4).OnFalse(pchsSwivel.SwivelStop());

    m_operatorPannel.Button(5).OnTrue(pchsSwivel.SwivelBk());
    m_operatorPannel.Button(5).OnFalse(pchsSwivel.SwivelStop());

    m_operatorPannel.Button(7).OnTrue(pchsElevator.ElevatorFwd());
    m_operatorPannel.Button(7).OnFalse(pchsElevator.ElevatorStop());

    m_operatorPannel.Button(8).OnTrue(pchsElevator.ElevatorBk());
    m_operatorPannel.Button(8).OnFalse(pchsElevator.ElevatorStop());

    m_operatorPannel.Button(9).OnTrue(pchsManipulator.IntakeCubeCommand());
    m_operatorPannel.Button(9).OnFalse(pchsManipulator.StopCubeCommand());

    m_driverController.LeftTrigger().OnTrue(pchsManipulator.ScoreCommand());
    m_driverController.LeftTrigger().OnFalse(pchsManipulator.StopCubeCommand());
    m_driverController.A().OnTrue(pchsElevator.ElevatorFlipOut());

    m_driverController.B().OnTrue(pchsElevator.ElevatorRetract());
    
    //m_operatorPannel.Button(9).OnTrue(pchsSwivel.ZeroSwivel());


}

// frc2::Command* RobotContainer::GetAutonomousCommand() {
//   // An example command will be run in autonomous
  
//   //return m_chooser.GetSelected();
// }
