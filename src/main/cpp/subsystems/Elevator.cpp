#include "subsystems/Elevator.h"
#include <frc/smartdashboard/SmartDashboard.h>
//#include <frc/shuffleboard/Shuffleboard.h>
#include <functional>
using namespace ElevatorConstants;




Elevator::Elevator(){
    //IsHome (AtHome);
    rgtElevator.ConfigFactoryDefault();
    lftElevator.ConfigFactoryDefault();
    rgtElevator.SetInverted(true);
    lftElevator.Follow(rgtElevator);
}
void Elevator::ResetElevatorEnc(){
    rgtElevator.SetSelectedSensorPosition(0, 0, 10);
}
void Elevator::SetElevator(int pow){
    rgtElevator.Set(ctre::phoenix::motorcontrol::TalonFXControlMode::PercentOutput, pow);
    // lftElevator.Set(ctre::phoenix::motorcontrol::TalonFXControlMode::Follower, 7);
}

int Elevator::GetElevator(){
    return (rgtElevator.GetSelectedSensorPosition());
}

void Elevator::extend(bool yes){
    if(yes){
        Elevator::Extension.Set(frc::DoubleSolenoid::kReverse);
    }
    else{
        Elevator::Extension.Set(frc::DoubleSolenoid::kForward);
    }
}
void Elevator::MoveElevator(int dist){
    Elevator::SetElevator(0.5);
    if(Elevator::GetElevator() > dist){
        Elevator::SetElevator(0);
    }
}
bool Elevator::AtHome(){
    if(Elevator::Home.Get() == 0){
        return true;
    }
    else{
        return false;
    }
}
bool Elevator::AtSecond(){
    if(Elevator::SecondStage.Get() == 1){
        return true;
    }
    else{
        return false;
    }
}

bool Elevator::AtThird(){
    if(Elevator::rgtElevator.GetSelectedSensorPosition() >= 100){
        return true;
    }
    else{
        return false;
    }
}
void Elevator::Periodic(){
    frc::SmartDashboard::PutNumber("Eleveator Enc", rgtElevator.GetSelectedSensorPosition());
    frc::SmartDashboard::PutNumber("Lft Elevator Enc", lftElevator.GetSelectedSensorPosition());
    frc::SmartDashboard::PutBoolean("low mag", Home.Get());
}


frc2::CommandPtr Elevator::ElevatorFlipOut(){
    return RunOnce([this] {Extension.Set(frc::DoubleSolenoid::kReverse);})
    // .AlongWith(Run([this] {rgtElevator.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, .25);}))
    // .WithTimeout(2.0_s)
    // .AndThen(Run([this] {rgtElevator.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);}))
    .WithName("Flip Out");
}

frc2::CommandPtr Elevator::EleTest(std::function<bool()> home){
    return Run([this] {rgtElevator.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -0.2);})
    .Until(home)
    .WithName("Ele Test");
}

frc2::CommandPtr Elevator::ElevatorRetract(){
    return RunOnce([this] {Extension.Set(frc::DoubleSolenoid::kForward);})
    .WithName("Retract Elevator");
}

frc2::CommandPtr Elevator::ElevatorFwd(){
    return Run([this] {rgtElevator.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.3);})
    .WithName("Move Elevator Forward");
}

frc2::CommandPtr Elevator::ElevatorBk(){
    return RunOnce([this] {rgtElevator.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -0.3);})
    .WithName("elevator");
}

frc2::CommandPtr Elevator::ElevatorStop(){
    return RunOnce([this] {rgtElevator.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);})
    .WithName("Stop Elevator");
}

frc2::CommandPtr Elevator::ElevatorBreak(){
    return RunOnce([this] {rgtElevator.SetNeutralMode(ctre::phoenix::motorcontrol::Brake);})
    .AndThen(Run([this] {rgtElevator.Set(ctre::phoenix::motorcontrol::TalonFXControlMode::PercentOutput, 0);}))
    .WithName("u bozo");
}

frc2::CommandPtr Elevator::EleCoast(){
    return RunOnce([this] {rgtElevator.SetNeutralMode(ctre::phoenix::motorcontrol::Coast);})
    .WithName("coast");
}

frc2::CommandPtr Elevator::MoveElevatorHome(){
    return Run([this] {if(AtHome()){
                            rgtElevator.SetNeutralMode(ctre::phoenix::motorcontrol::Brake);
                            Elevator::ResetElevatorEnc();
                            rgtElevator.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);   
                            }
                        else{
                            rgtElevator.Set(ctre::phoenix::motorcontrol::TalonFXControlMode::PercentOutput, -0.47);
                        }})
    //.Unless(IsHome)
   .WithName("Home");
    
}

frc2::CommandPtr Elevator::MoveElevatorThird(){
    return RunOnce([this] {
                        if(Elevator::GetElevator() > ElevatorConstants::ElevatorScore3){
                            rgtElevator.SetNeutralMode(ctre::phoenix::motorcontrol::Brake);
                            //ResetElevatorEnc();
                            rgtElevator.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
                        }
                        else{
                            rgtElevator.Set(ctre::phoenix::motorcontrol::TalonFXControlMode::PercentOutput, 0.5);
                        }})
                        .WithName("Move to Third");
}

frc2::CommandPtr Elevator::MoveElevatorSecond(){
    return Run([this] {
                        if(Elevator::GetElevator() > ElevatorConstants::ElevatorScore2){
                            rgtElevator.SetNeutralMode(ctre::phoenix::motorcontrol::Brake);
                            rgtElevator.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
                        }
                        else{
                            rgtElevator.Set(ctre::phoenix::motorcontrol::TalonFXControlMode::PercentOutput, 0.5);
                        }})
                        .WithName("elevator second");
}
// }
// frc2::CommandPtr Elevator::MoveElevatorHome(){
//     return RunOnce([this] {Elevator::SetElevator(0.5);})
//     .Until(Elevator::Home.Get() == true);
// }