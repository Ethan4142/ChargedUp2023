#include "subsystems/Swivel.h"
//#include <frc/smartdashboard/SmartDashboard.h>
//#include <frc/shuffleboard/Shuffleboard.h>
#include <ctre/phoenix/motorcontrol/StatorCurrentLimitConfiguration.h>

using namespace SwivelConstants;

Swivel::Swivel(){
    swivelMotor.ConfigFactoryDefault();
    swivelMotor.SetInverted(false);
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

frc2::CommandPtr Swivel::SwivelDownCommand(){
    return RunOnce([this] {swivelMotor.Set(ctre::phoenix::motorcontrol::ControlMode::Position, SwivelConstants::down);})
    .WithName("Swivel Down Position");
}

frc2::CommandPtr Swivel::PrepSwivelCommand(){
    return RunOnce([this] {swivelMotor.Set(ctre::phoenix::motorcontrol::ControlMode::Position, SwivelConstants::prep);})
    .WithName("Swivel Prep Position");
}

frc2::CommandPtr Swivel::SwivelScoreCommand(){
    return RunOnce([this] {swivelMotor.Set(ctre::phoenix::motorcontrol::ControlMode::Position, SwivelConstants::score);})
    .WithName("Swivel Score Position");
}