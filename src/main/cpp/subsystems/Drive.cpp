#include "subsystems/Drive.h"
//#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/geometry/Rotation2d.h>
#include <frc/kinematics/DifferentialDriveWheelSpeeds.h>
#include <ctre/Phoenix.h>
#include <ctre/phoenix/motorcontrol/SupplyCurrentLimitConfiguration.h>
#include "subsystems/PID.h"
using namespace DriveConstants;


Drive::Drive()
    :
    m_RgtF{RgtFPort},
    m_LftF{LftFPort},
    m_RgtB{RgtBPort},
    m_LftB{LftBPort},
    m_rightEncoder{kRightEncoderPorts[0], kRightEncoderPorts[1]},
    m_leftEncoder{kLeftEncoderPorts[0], kLeftEncoderPorts[1]}{
        m_RgtF.SetInverted(true);
        m_LftF.SetInverted(true);
        m_LftB.SetInverted(true);   //uhh
        m_RgtB.SetInverted(true);
        m_RgtB.Follow(m_RgtF);
        m_LftB.Follow(m_LftF);
        m_RgtF.ConfigStatorCurrentLimit(StatorCurrentLimitConfiguration(true, 20, 25, 1.0));
        m_RgtF.ConfigSupplyCurrentLimit(SupplyCurrentLimitConfiguration(true, 10, 15, 0.5));
        //PID DrivePID(0.0, 0.0, 0.0, 100, -1, 1);

    }

void Drive::Periodic(){
    // Drive::Log();
}

void Drive::Arcade(double x, double y){
    m_drive.ArcadeDrive(-x, y);
}


void Drive::SetDrive(double Rgt, double Lft){
    m_RgtF.Set(ctre::phoenix::motorcontrol::TalonFXControlMode::PercentOutput, Rgt);
    m_LftF.Set(ctre::phoenix::motorcontrol::TalonFXControlMode::PercentOutput, Lft);
    //m_RgtB.Set(ctre::phoenix::motorcontrol::TalonFXControlMode::PercentOutput, Rgt);
    //m_LftB.Set(ctre::phoenix::motorcontrol::TalonFXControlMode::PercentOutput, Lft);
}

units::degree_t Drive::GetHeading(){
    return units::degree_t{std::remainder(m_gyro.GetAngle(), 360) *
                                    (kGyroReversed ? -1.0 : 1.0)};
}

units::meter_t Drive::GetAverageEncoder(){
    return units::meter_t{(m_RgtF.GetSelectedSensorPosition() + m_LftF.GetSelectedSensorPosition()) / 2};
}