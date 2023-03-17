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

using namespace ElevatorConstants;

class Elevator : public frc2::SubsystemBase{
    public:
        Elevator();
        double getElevatorPose();
        void resetElevator();
        void SetElevator();

        [[nodiscard]] frc2::CommandPtr ElevatorFlipOut();
        [[nodsicard]] frc2::CommandPtr ElevatorRetract();
        [[nodiscard]] frc2::CommandPtr ElevatorFwd();
        [[nodiscard]] frc2::CommandPtr ElevatorBk();
        [[nodiscard]] frc2::CommandPtr ElevatorStop();
        [[nodiscard]] frc2::CommandPtr ElevatorBreak();
        [[nodsicard]] frc2::CommandPtr EleCoast();
        // [[nodiscard]] frc2::CommandPtr ElevatorDownCommand();
        // [[nodiscard]] frc2::CommandPtr ElevatorPrepCommand();
        // [[nodiscard]] frc2::CommandPtr ElevatorScore2Command();
        // [[nodiscard]] frc2::CommandPtr ElevatorScore3Command();

    private:
        ctre::phoenix::motorcontrol::can::WPI_TalonFX rgtElevator{ElevatorConstants::rgtElevatorPort};
        ctre::phoenix::motorcontrol::can::WPI_TalonFX lftElevator{ElevatorConstants::lftElevatorPort};
        ctre::phoenix::motorcontrol::GroupMotorControllers ElevatorMotors;

        
        
        //frc::MotorControllerGroup ElevatorMotors{rgtElevator, lftElevator};
        //frc::Encoder ElevatorEncoder{ElevatorConstants::ElevatorEncPorts[0], ElevatorConstants::ElevatorEncPorts[1]};
        frc::DoubleSolenoid Extension{frc::PneumaticsModuleType::REVPH, 10, 14};
};