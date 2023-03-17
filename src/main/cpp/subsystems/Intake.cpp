#include "subsystems/Intake.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/DoubleSolenoid.h>
#include <ctre/Phoenix.h>
#include <ctre/phoenix/motorcontrol/SupplyCurrentLimitConfiguration.h>
#include <frc2/command/WaitCommand.h>
#include <frc2/command/CommandPtr.h>
using namespace IntakeConstants;

Intake::Intake()
  : IntakeMotor{9}{
    IntakeMotor.ConfigStatorCurrentLimit(StatorCurrentLimitConfiguration(true, 10, 15, 10));
    IntakeMotor.ConfigSupplyCurrentLimit(SupplyCurrentLimitConfiguration(true, 10, 15, 0.5));
    IntakeMotor.SetInverted(true);
  }

  
void Intake::moveMain(){
  mainIntake.Set(frc::DoubleSolenoid::kForward);
}
void Intake::reverseMain(){
  mainIntake.Set(frc::DoubleSolenoid::kReverse);
}

void Intake::moveSmall(){
  intakeJoint.Set(frc::DoubleSolenoid::kForward);
}
void Intake::reverseSmall(){
  intakeJoint.Set(frc::DoubleSolenoid::kReverse);
}

void Intake::setIntakeMotor(int pow){
  IntakeMotor.Set(ctre::phoenix::motorcontrol::TalonFXControlMode::PercentOutput, pow);
}

frc2::CommandPtr Intake::IntakeCommand() {
  return RunOnce([this] {intakeJoint.Set(frc::DoubleSolenoid::kForward);})
      .AndThen(Run([this] {mainIntake.Set(frc::DoubleSolenoid::kForward);
      IntakeMotor.Set(ctre::phoenix::motorcontrol::TalonFXControlMode::PercentOutput, 0.25);}))
      //.AndThen(Run([this] { IntakeMotor.Set(ctre::phoenix::motorcontrol::TalonFXControlMode::PercentOutput, 0.25); }))
      .WithName("Intake");
}

frc2::CommandPtr Intake::OuttakeCommand(){
    return RunOnce([this] { intakeJoint.Set(frc::DoubleSolenoid::kForward);})
    .AndThen(Run([this] {mainIntake.Set(frc::DoubleSolenoid::kForward);}))
    .AndThen(Run([this] { IntakeMotor.Set(ctre::phoenix::motorcontrol::TalonFXControlMode::PercentOutput, -0.5);}))
    .WithName("Outtake");
}

frc2::CommandPtr Intake::RetractCommand() {
  //  return RunOnce([this] {
  //          IntakeMotor.Disable();
  //          intakeJoint.Set(frc::DoubleSolenoid::kReverse);
  //          frc2::WaitCommand(2_s);
  //          mainIntake.Set(frc::DoubleSolenoid::kReverse);
  //        })
  //     .WithName("Retract");
  return RunOnce([this] {IntakeMotor.Disable();
          mainIntake.Set(frc::DoubleSolenoid::kReverse);})
          .AndThen(Run([this] {intakeJoint.Set(frc::DoubleSolenoid::kReverse);}))
          .WithName("Retract");
}

frc2::CommandPtr Intake::RetractSmall(){
  return Run([this] {intakeJoint.Set(frc::DoubleSolenoid::kReverse);})
  .WithName("lol");
}