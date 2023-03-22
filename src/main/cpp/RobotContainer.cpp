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
#include <frc2/command/CommandPtr.h>
#include <frc2/command/Subsystem.h>
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/RamseteCommand.h>
#include <frc2/command/WaitUntilCommand.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/Joystick.h>
#include <functional>
#include "commands/Autos.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableValue.h"

//#include "commands/TurnTo.h"
//#include "commands/ExampleCommand.h"
#include "commands/Teleop.h"
#include "commands/Elevator/ElevatorThird.h"



RobotContainer::RobotContainer() {
  std::shared_ptr<nt::NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
  
  m_chooser.SetDefaultOption("simple Auto", m_simpleAuto.get());
  frc::Shuffleboard::GetTab("autonomous").Add(m_chooser);

  frc::Shuffleboard::GetTab("Intake").Add(pchsIntake);
  frc::Shuffleboard::GetTab("Elevator").Add(pchsElevator);

  // frc::Shuffleboard::GetTab("Intake").Add(pchsIntake);
  ConfigureBindings();
  
  pchsDrive.SetDefaultCommand(Teleop(
    &pchsDrive, [this] {return m_driverController.GetLeftY();},
    [this] {return -m_driverController.GetRightX();}));

  //pchsElevator.SetDefaultCommand(Elevator::ElevatorStop());
}

bool RobotContainer::isGreater(){
  if(RobotContainer::m_operatorPannel.GetRawAxis(1) > 0){
    return true;
  }
  else{
    return false;
  }
}
void RobotContainer::ConfigureBindings() {
    
    //frc2::Trigger UpAxis(isGreater(1));

    //SWIVEL
          ///OLD STUFF
    m_operatorPannel.Button(2).OnTrue(pchsSwivel.SwivelScoreCommand());//Swivel Fwd
    m_operatorPannel.Button(2).OnFalse(pchsSwivel.SwivelStop());

    // m_operatorPannel.Button(3).OnTrue(pchsSwivel.FeederSwivel()); //Feeder 
    // m_operatorPannel.Button(3).OnFalse(pchsSwivel.SwivelStop());

    m_operatorPannel.Button(5).OnTrue(pchsSwivel.PrepSwivelCommand());
    m_operatorPannel.Button(5).OnFalse(pchsSwivel.SwivelStop());

    m_operatorPannel.Button(8).OnTrue(pchsSwivel.SwivelDownCommand());
    m_operatorPannel.Button(8).OnFalse(pchsSwivel.SwivelStop());

    m_driverController.A().OnTrue(pchsSwivel.ZeroSwivel());
    
    m_driverController.B().OnTrue(pchsDrive.BrakeDrive());
    m_driverController.Y().OnTrue(pchsDrive.CoastDrive());

    //m_driverController.X().OnTrue(pchsElevator.EleTest(pchsElevator.AtHome()));
  
    //ELEVATOR NEW STUFF
    m_operatorPannel.Button(1).OnTrue(pchsElevator.MoveElevatorThird());
    m_operatorPannel.Button(1).OnFalse(pchsElevator.ElevatorStop());

    m_operatorPannel.Button(4).OnTrue(pchsElevator.MoveElevatorSecond());
    m_operatorPannel.Button(4).OnFalse(pchsElevator.ElevatorBreak());

    
    m_operatorPannel.Button(7).OnTrue(pchsElevator.MoveElevatorHome());
    m_operatorPannel.Button(7).OnFalse(pchsElevator.ElevatorBreak());//Ethan added for elevator brake
    

    //MANIPULATOR

    m_operatorPannel.Button(9).OnTrue(pchsManipulator.ScoreCommand());
    m_operatorPannel.Button(9).OnFalse(pchsManipulator.StopConeCommand());

    m_operatorPannel.Button(10).OnTrue(pchsIntake.FeederStation());
    
    m_operatorPannel.Button(11).OnTrue(pchsManipulator.IntakeCubeCommand());
    m_operatorPannel.Button(11).OnFalse(pchsManipulator.StopConeCommand());

    m_operatorPannel.Button(12).OnTrue(pchsIntake.IntakeCommand());
    
    m_operatorPannel.Button(13).OnTrue(pchsIntake.RetractCommand());

    //CODY CONTROLS
    m_driverController.LeftTrigger().OnTrue(pchsElevator.ElevatorFlipOut());

    m_driverController.RightTrigger().OnTrue(pchsElevator.ElevatorRetract());

    m_driverController.LeftBumper().OnTrue(pchsIntake.LowGoal().AlongWith(pchsManipulator.ScoreCommand()));
    m_driverController.LeftBumper().OnFalse(pchsIntake.RetractCommand().AlongWith(pchsManipulator.StopConeCommand()));
    //END LOL
    m_operatorPannel.Button(3).OnTrue(pchsManipulator.IntakeCubeCommand());
    m_operatorPannel.Button(3).OnFalse(pchsManipulator.StopConeCommand());
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // Runs the chosen command in autonomous
  return autos::SimpleAuto(&pchsDrive);
}
