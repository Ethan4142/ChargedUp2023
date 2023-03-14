#include "subsystems/Elevator.h"
//#include <frc/smartdashboard/SmartDashboard.h>
//#include <frc/shuffleboard/Shuffleboard.h>
using namespace ElevatorConstants;

Elevator::Elevator(){
    rgtElevator.ConfigFactoryDefault();
    lftElevator.ConfigFactoryDefault();
    lftElevator.SetInverted(true);
    lftElevator.Follow(rgtElevator);
    
    rgtElevator.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::CTRE_MagEncoder_Relative,1, 10);
    rgtElevator.ConfigMotionCruiseVelocity(1500, 100);
    rgtElevator.ConfigMotionAcceleration(100, 10);

    rgtElevator.SelectProfileSlot(1,0);
    rgtElevator.Config_kF(1, ElevatorConstants::ElevatorkF);
    rgtElevator.Config_kP(1, ElevatorConstants::ElevatorkP);
    rgtElevator.Config_kI(1, ElevatorConstants::ElevatorkI);
    rgtElevator.Config_kD(1, ElevatorConstants::ElevatorkD);

}


double Elevator::getElevatorPose(){
    return rgtElevator.GetSelectedSensorPosition(1);
}

void Elevator::resetElevator(){
    rgtElevator.SetSelectedSensorPosition(0, 1, 10);
}

frc2::CommandPtr Elevator::ElevatorDownCommand(){
    return RunOnce([this] {rgtElevator.Set(ctre::phoenix::motorcontrol::ControlMode::Position, ElevatorConstants::ElevatorDown);})
    .WithName("Elevator Down");
}

frc2::CommandPtr Elevator::ElevatorPrepCommand(){
    return RunOnce([this] {rgtElevator.Set(ctre::phoenix::motorcontrol::ControlMode::Position, ElevatorConstants::ElevatorDown);})
    .WithName("Prep Elevator");
}

frc2::CommandPtr Elevator::ElevatorScoreCommand(){
    return RunOnce([this] {rgtElevator.Set(ctre::phoenix::motorcontrol::ControlMode::Position, ElevatorConstants::ElevatorScore);})
    .WithName("Elevator Score Position");
}