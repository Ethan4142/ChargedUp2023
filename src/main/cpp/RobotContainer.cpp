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
    &pchsDrive, [this] {return -m_driverController.GetLeftY();},
    [this] {return m_driverController.GetRightX();}));

  //pchsElevator.SetDefaultCommand(Elevator::ElevatorStop());
}

void RobotContainer::ConfigureBindings() {
    //Extend intake and run 
    m_driverController.LeftBumper().OnTrue(pchsIntake.IntakeCommand());
    
    //Retract intake + stop
    m_driverController.RightBumper().OnTrue(pchsIntake.RetractCommand());//Swivel Fwd
    m_driverController.A().OnTrue(pchsSwivel.SwivelFwd());
    m_driverController.A().OnFalse(pchsSwivel.SwivelStop());
    
    //Swivel Back
    m_driverController.B().WhileTrue(pchsSwivel.SwivelBk());
    m_driverController.B().OnFalse(pchsSwivel.SwivelStop());
    
    //Pick up cone
    m_operatorPannel.Button(1).OnTrue(pchsManipulator.IntakeConeCommand());
    m_operatorPannel.Button(1).OnFalse(pchsManipulator.StopConeCommand());

    //Intake Cube
    m_driverController.X().OnTrue(pchsManipulator.IntakeCubeCommand());
    m_driverController.X().OnFalse(pchsManipulator.StopCubeCommand());
    
    //Outtake cone
    m_operatorPannel.Button(2).OnTrue(pchsManipulator.OuttakeConeCommand());
    m_operatorPannel.Button(2).OnFalse(pchsManipulator.StopConeCommand());

    m_operatorPannel.Button(3).OnTrue(pchsManipulator.OuttakeCubeCommand());
    m_operatorPannel.Button(3).OnFalse(pchsManipulator.StopCubeCommand());
    
    m_operatorPannel.Button(4).OnTrue(pchsElevator.ElevatorFwd());
    m_operatorPannel.Button(4).OnFalse(pchsElevator.ElevatorBreak());

    m_operatorPannel.Button(5).OnTrue(pchsElevator.ElevatorBk());
    m_operatorPannel.Button(5).OnFalse(pchsElevator.ElevatorBreak());

    m_operatorPannel.Button(7).OnTrue(pchsElevator.EleCoast());

    m_operatorPannel.Button(8).OnTrue(pchsElevator.ElevatorFlipOut());

    //m_operatorPannel.Button(9).OnTrue(pchsElevator.ElevatorRetract());

    m_operatorPannel.Button(9).OnTrue(pchsDrive.TestDrive());
    m_operatorPannel.Button(9).OnFalse(pchsDrive.StopDrive());


}

// frc2::Command* RobotContainer::GetAutonomousCommand() {
//   // An example command will be run in autonomous
  
//   //return m_chooser.GetSelected();
// }
