#include "subsystems/Intake.h"
//#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/DoubleSolenoid.h>
#include <ctre/Phoenix.h>
#include <ctre/phoenix/motorcontrol/SupplyCurrentLimitConfiguration.h>
using namespace IntakeConstants;

Intake::Intake()
  : IntakeMotor{IntakeConstants::IntakePort}{
    IntakeMotor.ConfigStatorCurrentLimit(StatorCurrentLimitConfiguration(true, 20, 15, 10));
    IntakeMotor.ConfigSupplyCurrentLimit(SupplyCurrentLimitConfiguration(true, 10, 15, 0.5));
  }
frc2::CommandPtr Intake::IntakeCommand() {
  return RunOnce([this] { intakeJoint.Set(frc::DoubleSolenoid::kForward); })
      .AndThen(Run([this] {mainIntake.Set(frc::DoubleSolenoid::kForward);}))
      .AndThen(Run([this] { IntakeMotor.Set(ctre::phoenix::motorcontrol::TalonFXControlMode::PercentOutput, 1); }))
      .WithName("Intake");
}

frc2::CommandPtr Intake::OuttakeCommand(){
    return RunOnce([this] { intakeJoint.Set(frc::DoubleSolenoid::kForward);})
    .AndThen(Run([this] {mainIntake.Set(frc::DoubleSolenoid::kForward);}))
    .AndThen(Run([this] { IntakeMotor.Set(ctre::phoenix::motorcontrol::TalonFXControlMode::PercentOutput, -1);}))
    .WithName("Outtake");
}

frc2::CommandPtr Intake::RetractCommand() {
  return RunOnce([this] {
           IntakeMotor.Disable();
           intakeJoint.Set(frc::DoubleSolenoid::kReverse);
           mainIntake.Set(frc::DoubleSolenoid::kReverse);
         })
      .WithName("Retract");
}