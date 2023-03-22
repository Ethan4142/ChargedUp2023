#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/FunctionalCommand.h>
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
#include <functional>

using namespace ElevatorConstants;

class Elevator : public frc2::SubsystemBase{
    public:
        Elevator();
        std::function<bool()> IsHome;
        void SetElevator(int pow);
        void ResetElevatorEnc();
        void MoveElevator(int dist);
        int GetElevator();
        bool AtHome();
        bool AtSecond();
        bool AtThird();
        void Periodic();

        void extend(bool yes);
        
        //std::function <bool()> isHome = AtHome();

        
        //[[nodiscard]] frc2::FunctionalCommand MoveThird();
        //Basic functionality testing commands
        [[nodiscard]] frc2::FunctionalCommand MoveThird();
        [[nodiscard]] frc2::CommandPtr ElevatorFlipOut();
        [[nodiscard]] frc2::CommandPtr ElevatorRetract();
        [[nodiscard]] frc2::CommandPtr ElevatorFwd();
        [[nodiscard]] frc2::CommandPtr ElevatorBk();
        [[nodiscard]] frc2::CommandPtr ElevatorStop();
        [[nodiscard]] frc2::CommandPtr ElevatorBreak();
        [[nodiscard]] frc2::CommandPtr EleCoast();
        [[nodiscard]] frc2::CommandPtr EleTest(std::function<bool()> home);
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
        
        //frc::MotorControllerGroup ElevatorMotors{rgtElevator, lftElevator};
        //frc::Encoder ElevatorEncoder{ElevatorConstants::ElevatorEncPorts[0], ElevatorConstants::ElevatorEncPorts[1]};
        frc::DoubleSolenoid Extension{frc::PneumaticsModuleType::REVPH, 10, 14};
};