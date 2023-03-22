#pragma once

#include <frc2/command/Command.h>
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

#include <frc/ADXRS450_Gyro.h>
#include <frc/Encoder.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc/controller/SimpleMotorFeedforward.h>
#include <frc/trajectory/TrapezoidProfile.h>
#include <frc2/command/PIDSubsystem.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/Compressor.h>
#include <units/length.h>
#include <units/angle.h>
#include "subsystems/PID.h"


class Drive : public frc2::SubsystemBase{
    public:
     Drive();

     void Log();

     void Reset();
     
     int GetAverageEncoder();
     frc::Encoder& GetLftEncoder();

     frc::Encoder& GetRgtEncoder();

     double getHeading();
     
     void SetMaxOutput(double max);

     units::degree_t GetHeading();

     units::degree_t GetPitch();
     
     [[nodiscard]] frc2::CommandPtr TestDrive();
     [[nodiscard]] frc2::CommandPtr StopDrive();
     [[nodiscard]] frc2::CommandPtr TestDriveOff();
     [[nodiscard]] frc2::CommandPtr BrakeDrive();
     [[nodiscard]] frc2::CommandPtr CoastDrive();
     
     double GetTurnRate();
     void SetDrive(double Rgt, double Lft);

     void Arcade(double x, double y);
     
     void Periodic();

     bool atSetpoint();
     
     bool isTilted();

     bool isLevel();
     [[nodiscard]] frc2::CommandPtr DriveDistanceCommand(int distance,
                                                      double speed);

    private:
 
    ctre::phoenix::motorcontrol::can::WPI_TalonFX m_RgtF;
    ctre::phoenix::motorcontrol::can::WPI_TalonFX m_LftF;
    ctre::phoenix::motorcontrol::can::WPI_TalonFX m_RgtB;
    ctre::phoenix::motorcontrol::can::WPI_TalonFX m_LftB;

    // frc::Encoder m_rightEncoder;
    // frc::Encoder m_leftEncoder;

    //frc::SimpleMotorFeedforward<units::meters> m_feedforward;
    // frc::MotorControllerGroup m_rightMotors {m_RgtF, m_RgtB};
    // frc::MotorControllerGroup m_leftMotors {m_LftF, m_LftB};

    frc::DifferentialDrive m_drive{m_LftF, m_RgtF};
    
    frc::ADXRS450_Gyro m_gyro;
    //frc::Compressor phCompressor{6, frc::PneumaticsModuleType::REVPH};
    
};