#include "subsystems/Swivel.h"
#include <frc/smartdashboard/SmartDashboard.h>
//#include <frc/shuffleboard/Shuffleboard.h>
#include <ctre/phoenix/motorcontrol/StatorCurrentLimitConfiguration.h>

using namespace SwivelConstants;

Swivel::Swivel(){
    swivelMotor.ConfigFactoryDefault();
    swivelMotor.SetInverted(true);
    swivelMotor.ConfigPeakCurrentLimit(0);

    swivelMotor.SelectProfileSlot(8, 0);
    swivelMotor.Config_kF(0, SwivelConstants::SwivelkF, 10);
    swivelMotor.Config_kP(0, SwivelConstants::SwivelkP, 10);
    swivelMotor.Config_kI(0,SwivelConstants::SwivelkI, 10);
    swivelMotor.Config_kD(0, SwivelConstants::SwivelkD, 10);

    swivelMotor.ConfigMotionCruiseVelocity(SwivelConstants::CruiseVel, 10);
    swivelMotor.ConfigMotionAcceleration(SwivelConstants::SwivelAccl, 10);
}

void Swivel::resetSwivel(){
    swivelMotor.SetSelectedSensorPosition(0, 0, 10);
}

void Swivel::setSwivel(int pow){
    swivelMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, pow);
}

frc2::CommandPtr Swivel::SwivelDownCommand(){
    //For picking up from the ground
    return RunOnce([this] {swivelMotor.Set(ctre::phoenix::motorcontrol::ControlMode::Position, SwivelConstants::down);})
    .WithName("Swivel Down Position");
}

frc2::CommandPtr Swivel::PrepSwivelCommand(){
    //Prep for pickup up from feeder station
    return RunOnce([this] {swivelMotor.Set(ctre::phoenix::motorcontrol::ControlMode::Position, SwivelConstants::prep);})
    .WithName("Swivel Prep Position");
}

frc2::CommandPtr Swivel::SwivelScoreCommand(){
    //Put in scoring position
    return RunOnce([this] {swivelMotor.Set(ctre::phoenix::motorcontrol::ControlMode::Position, SwivelConstants::score);})
    .WithName("Swivel Score Position");
}

frc2::CommandPtr Swivel::SwivelFwd(){
    return RunOnce([this] {swivelMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.5);})
    .WithName("swivel forward");
}

frc2::CommandPtr Swivel::SwivelBk(){    //Reverse
    return RunOnce([this] {swivelMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -0.5);})
    .WithName("Reverse swivel");
}

frc2::CommandPtr Swivel::SwivelStop(){
    return RunOnce([this] {swivelMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);})
    .WithName("stop swivel");
}

void Swivel::Periodic(){
    frc::SmartDashboard::PutNumber("Swivel Voltage", swivelMotor.GetSupplyCurrent());
    frc::SmartDashboard::PutNumber("Swivel Temp", swivelMotor.GetTemperature());
    frc::SmartDashboard::PutNumber("Swivel Enc", swivelMotor.GetSelectedSensorPosition());
}