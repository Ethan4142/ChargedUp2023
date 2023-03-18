#include "subsystems/Drive.h"
//#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/geometry/Rotation2d.h>
#include <frc/kinematics/DifferentialDriveWheelSpeeds.h>
#include <ctre/Phoenix.h>
#include <ctre/phoenix/motorcontrol/SupplyCurrentLimitConfiguration.h>
#include "subsystems/PID.h"
#include <frc/smartdashboard/SmartDashboard.h>
using namespace DriveConstants;


Drive::Drive()
    :
    m_RgtF{RgtFPort},
    m_LftF{LftFPort},
    m_RgtB{RgtBPort},
    m_LftB{LftBPort}{
    //m_rightEncoder{2, 3, false,k4X},
    //m_leftEncoder{0, 1, k4X}{
        m_RgtF.SetInverted(true);
        m_LftF.SetInverted(false);
        m_LftB.SetInverted(false);   //uhh
        m_RgtB.SetInverted(true);
        m_RgtB.Follow(m_RgtF);
        m_LftB.Follow(m_LftF);
        //m_RgtF.ConfigStatorCurrentLimit(StatorCurrentLimitConfiguration(true, 20, 25, 1.0));
        //m_RgtF.ConfigSupplyCurrentLimit(SupplyCurrentLimitConfiguration(true, 20, 15, 0.5));
        //PID DrivePID(0.0, 0.0, 0.0, 100, -1, 1);

    }

// void Drive::Periodic(){
// }

void Drive::Arcade(double x, double y){
    m_drive.ArcadeDrive(-x, y);
}


void Drive::SetDrive(double Rgt, double Lft){
    m_RgtF.Set(ctre::phoenix::motorcontrol::TalonFXControlMode::PercentOutput, Rgt);
    m_LftF.Set(ctre::phoenix::motorcontrol::TalonFXControlMode::PercentOutput, Lft);
    m_RgtB.Set(ctre::phoenix::motorcontrol::TalonFXControlMode::Follower, 3);
    m_LftB.Set(ctre::phoenix::motorcontrol::TalonFXControlMode::Follower, 0);
}

frc2::CommandPtr Drive::TestDrive(){
    return Run([this] {m_RgtF.SetNeutralMode(ctre::phoenix::motorcontrol::Brake);
                       m_LftF.SetNeutralMode(ctre::phoenix::motorcontrol::Brake);//Ethan added setting neutral mode to brake
        /*Drive::SetDrive(0.5, 0.5);*/})
    .WithName("Test Drive");
}
frc2::CommandPtr Drive::TestDriveOff(){
    return Run([this]{m_RgtF.SetNeutralMode(ctre::phoenix::motorcontrol::Brake);
                      m_LftF.SetNeutralMode(ctre::phoenix::motorcontrol::Brake);})
    .WithName("TestDriveOff");
}
frc2::CommandPtr Drive::StopDrive(){
    return Run([this] {Drive::SetDrive(0, 0);})
    .WithName("Stop Drive");
}
void Drive::Periodic(){
    frc::SmartDashboard::PutNumber("Drive Volts", m_RgtF.GetSupplyCurrent());
    frc::SmartDashboard::PutNumber("Drive Temp", m_RgtF.GetTemperature());
}
units::degree_t Drive::GetHeading(){
    return units::degree_t{std::remainder(m_gyro.GetAngle(), 360) *
                                    (kGyroReversed ? -1.0 : 1.0)};
}

// units::meter_t Drive::GetAverageEncoder(){
//     return units::meter_t{(m_RgtF.GetSelectedSensorPosition() + m_LftF.GetSelectedSensorPosition()) / 2};
// }