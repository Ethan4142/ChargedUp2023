#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include "Constants.h"
#include <ctre/phoenix/motorcontrol/can/TalonFX.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonFX.h>
#include <ctre/phoenix/motorcontrol/GroupMotorControllers.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include <ctre/phoenix/motorcontrol/ControlMode.h>
#include "rev/CANSparkMax.h"
#include <frc/DoubleSolenoid.h>

class Manipulator : public frc2::SubsystemBase{
    public:
     Manipulator();

     
     bool isIn();

     void setManipulator(int pow);


     [[nodiscard]] frc2::CommandPtr IntakeConeCommand();

     [[nodiscard]] frc2::CommandPtr IntakeCubeCommand();

     [[nodiscard]] frc2::CommandPtr ScoreCommand();

     [[nodiscard]] frc2::CommandPtr StopConeCommand();
     
     [[nodiscard]] frc2::CommandPtr StopCubeCommand();
     

    private:
     ctre::phoenix::motorcontrol::can::WPI_TalonFX ManipulatorMotor;
     frc::DoubleSolenoid ManipulatorJoint{frc::PneumaticsModuleType::REVPH, 11, 15};
};