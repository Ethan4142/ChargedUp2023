#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <frc2/command/WaitCommand.h>
#include <Constants.h>
#include <ctre/phoenix/motorcontrol/can/TalonFX.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonFX.h>
#include <ctre/phoenix/motorcontrol/GroupMotorControllers.h>
#include <ctre/phoenix/motorcontrol/ControlMode.h>
#include <ctre/phoenix/motorcontrol/IMotorController.h>
#include <frc/Encoder.h>
#include <frc/DoubleSolenoid.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/DigitalInput.h>

using namespace ElevatorConstants;

class Elevator : public frc2::SubsystemBase{
    public:
        Elevator();
        void SetElevator(int pow);
        bool AtHome();
        bool AtSecond();
        bool AtThird();
        //Basic functionality testing commands
        [[nodiscard]] frc2::CommandPtr ElevatorFlipOut();
        [[nodsicard]] frc2::CommandPtr ElevatorRetract();
        [[nodiscard]] frc2::CommandPtr ElevatorFwd();
        [[nodiscard]] frc2::CommandPtr ElevatorBk();
        [[nodiscard]] frc2::CommandPtr ElevatorStop();
        [[nodiscard]] frc2::CommandPtr ElevatorBreak();
        [[nodsicard]] frc2::CommandPtr EleCoast();
        //Automation commands (move elevator to 3 different pos)
        [[nodiscard]] frc2::CommandPtr MoveElevatorHome();
        [[nodiscard]] frc2::CommandPtr MoveElevatorSecond();
        [[nodiscard]] frc2::CommandPtr MoveElevatorThird();

    private:
        ctre::phoenix::motorcontrol::can::WPI_TalonFX rgtElevator{ElevatorConstants::rgtElevatorPort};
        ctre::phoenix::motorcontrol::can::WPI_TalonFX lftElevator{ElevatorConstants::lftElevatorPort};
        ctre::phoenix::motorcontrol::GroupMotorControllers ElevatorMotors;
        frc::DigitalInput Home{ElevatorConstants::lowMagPort};
        frc::DigitalInput SecondStage{ElevatorConstants::MidMagPort};
        frc::DigitalInput ThirdStage{ElevatorConstants::HighMagPort};
        
        //frc::MotorControllerGroup ElevatorMotors{rgtElevator, lftElevator};
        //frc::Encoder ElevatorEncoder{ElevatorConstants::ElevatorEncPorts[0], ElevatorConstants::ElevatorEncPorts[1]};
        frc::DoubleSolenoid Extension{frc::PneumaticsModuleType::REVPH, 10, 14};
};