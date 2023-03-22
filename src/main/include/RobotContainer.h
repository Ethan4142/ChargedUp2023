// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>
#include <frc2/command/button/CommandJoystick.h>

#include <frc/XboxController.h>
#include <frc/Joystick.h>
#include <frc/controller/PIDController.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/Command.h>
#include <frc2/command/Commands.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/Subsystem.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/button/Trigger.h>

#include "Constants.h"
#include "commands/Autos.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/Drive.h"
#include "subsystems/Elevator.h"
#include "subsystems/Intake.h"
#include "subsystems/Swivel.h"
#include "subsystems/Manipulator.h"
#include "commands/Elevator/ElevatorThird.h"
#include "JoystickAxisGreaterTrigger.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and trigger mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();
  frc2::CommandPtr GetAutonomousCommand();
  bool isGreater();
  std::function<bool()> up;
  //std::function<bool()> up;
  [[nodiscard]] frc2::CommandPtr testAuto();

  //frc2::Command* GetAutonomousCommand();
  
 private:
  // Replace with CommandPS4Controller or CommandJoystick if needed
  frc2::CommandXboxController m_driverController{
      OperatorConstants::kDriverControllerPort};
  frc2::CommandJoystick m_operatorPannel{
    OperatorConstants::kOperatorPannelPort};
  
  // frc::Joystick operatorPanel{
  //   OperatorConstants::kOperatorPannelPort};
  
  bool gndIn;
  bool subIn;
  bool inBck;
  bool manIn;
  bool flipOut;
  bool flipIn;
  
  // The robot's subsystems are defined here...
  ExampleSubsystem m_subsystem;
  Drive pchsDrive;
  Elevator pchsElevator;  
  Intake pchsIntake;
  Manipulator pchsManipulator;
  Swivel pchsSwivel;
  

  frc2::CommandPtr m_simpleAuto = autos::SimpleAuto(&pchsDrive);

  frc::SendableChooser<frc2::Command*> m_chooser;

  void ConfigureBindings();
};

//std::function<bool()> elevHome(){RobotContainer::pchsElevator::getHome()};
