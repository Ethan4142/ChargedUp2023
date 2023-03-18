#include "subsystems/Manipulator.h"
#include "frc2/command/CommandPtr.h"
#include <ctre/Phoenix.h>
#include <ctre/phoenix/motorcontrol/SupplyCurrentLimitConfiguration.h>
using namespace ManipulatorConstants;

Manipulator::Manipulator()
    : ManipulatorMotor{manipulatorPort}{
        ManipulatorMotor.SetInverted(false);
        ManipulatorMotor.ConfigStatorCurrentLimit(StatorCurrentLimitConfiguration(true, 10, 15, 10));
        ManipulatorMotor.ConfigSupplyCurrentLimit(SupplyCurrentLimitConfiguration(true, 10, 15, 0.5));
    }

void Manipulator::setManipulator(int pow){
    ManipulatorMotor.Set(ctre::phoenix::motorcontrol::TalonFXControlMode::PercentOutput, pow);
}

frc2::CommandPtr Manipulator::IntakeConeCommand(){
    return RunOnce([this] {ManipulatorJoint.Set(frc::DoubleSolenoid::kReverse);})
    .AndThen(Run([this] {ManipulatorMotor.Set(ctre::phoenix::motorcontrol::TalonFXControlMode::PercentOutput, 0.25);}))
    .WithName("Cone");
}

frc2::CommandPtr Manipulator::IntakeCubeCommand(){
    return RunOnce([this] {ManipulatorJoint.Set(frc::DoubleSolenoid::kForward);})   //Change or smth idk
    .AndThen(Run([this] {ManipulatorMotor.Set(ctre::phoenix::motorcontrol::TalonFXControlMode::PercentOutput, 0.25);}))
    .WithName("Cube");

}

frc2::CommandPtr Manipulator::ScoreCommand(){
    return RunOnce([this] { ManipulatorJoint.Set(frc::DoubleSolenoid::kForward);})
    .AndThen(Run([this] {ManipulatorMotor.Set(ctre::phoenix::motorcontrol::TalonFXControlMode::PercentOutput, -0.25);}))
    .WithName("Spit Cone");
}

frc2::CommandPtr Manipulator::StopConeCommand(){
    return RunOnce([this] {ManipulatorMotor.Set(ctre::phoenix::motorcontrol::TalonFXControlMode::PercentOutput, 0);
    ManipulatorJoint.Set(frc::DoubleSolenoid::kReverse);})
    .WithName("Stop cone");
}
frc2::CommandPtr Manipulator::StopCubeCommand(){
    return RunOnce([this] {ManipulatorMotor.Set(ctre::phoenix::motorcontrol::TalonFXControlMode::PercentOutput, 0);})
    .WithName("Stop Cube");
}
