#include "subsystems/Elevator.h"
//#include <frc/smartdashboard/SmartDashboard.h>
//#include <frc/shuffleboard/Shuffleboard.h>
using namespace ElevatorConstants;

Elevator::Elevator(){
    rgtElevator.ConfigFactoryDefault();
    lftElevator.ConfigFactoryDefault();
    rgtElevator.SetInverted(true);
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

frc2::CommandPtr Elevator::ElevatorFlipOut(){
    return RunOnce([this] {Extension.Set(frc::DoubleSolenoid::kReverse);})
    // .AlongWith(Run([this] {rgtElevator.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, .25);}))
    // .WithTimeout(2.0_s)
    // .AndThen(Run([this] {rgtElevator.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);}))
    .WithName("Flip Out");
}

frc2::CommandPtr Elevator::ElevatorRetract(){
    return RunOnce([this] {Extension.Set(frc::DoubleSolenoid::kForward);})
    .WithName("chink");
}

frc2::CommandPtr Elevator::ElevatorFwd(){
    return RunOnce([this] {rgtElevator.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.25);})
    .WithName("lol");
}

frc2::CommandPtr Elevator::ElevatorBk(){
    return RunOnce([this] {rgtElevator.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -0.25);})
    .WithName("Lamao");
}

frc2::CommandPtr Elevator::ElevatorStop(){
    return RunOnce([this] {rgtElevator.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);})
    .WithName("lame");
}

frc2::CommandPtr Elevator::ElevatorBreak(){
    return RunOnce([this] {rgtElevator.SetNeutralMode(ctre::phoenix::motorcontrol::Brake);})
    .AndThen(Run([this] {rgtElevator.Set(ctre::phoenix::motorcontrol::TalonFXControlMode::PercentOutput, 0);}))
    .WithName("u bozo");
}

frc2::CommandPtr Elevator::EleCoast(){
    return RunOnce([this] {rgtElevator.SetNeutralMode(ctre::phoenix::motorcontrol::Coast);})
    .WithName("dog");
}
// frc2::CommandPtr Elevator::ElevatorDownCommand(){
//     return RunOnce([this] {rgtElevator.Set(ctre::phoenix::motorcontrol::ControlMode::Position, ElevatorConstants::ElevatorDown);})
//     .WithName("Elevator Down");
// }

// frc2::CommandPtr Elevator::ElevatorPrepCommand(){
//     return RunOnce([this] {rgtElevator.Set(ctre::phoenix::motorcontrol::ControlMode::Position, ElevatorConstants::ElevatorDown);})
//     .WithName("Prep Elevator");
// }

// frc2::CommandPtr Elevator::ElevatorScore2Command(){
//     return RunOnce([this] {rgtElevator.Set(ctre::phoenix::motorcontrol::ControlMode::Position, ElevatorConstants::ElevatorScore2);})
//     .WithName("Elevator Score Position");
// }

// frc2::CommandPtr Elevator::ElevatorScore3Command(){
//     return RunOnce([this] {rgtElevator.Set(ctre::phoenix::motorcontrol::ControlMode::Position, ElevatorConstants::ElevatorScore3);})
//     .WithName("Elevator 3rd Stage Score");
// }