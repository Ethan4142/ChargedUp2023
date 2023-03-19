// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.


#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/trajectory/constraint/DifferentialDriveKinematicsConstraint.h>
#include <units/acceleration.h>
#include <units/angle.h>
#include <units/length.h>
#include <units/time.h>
#include <units/velocity.h>
#include <units/voltage.h>
#include <numbers>

#pragma once
/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace DriveConstants{
    //---------------
    //Motor + Sensors
    //---------------
    constexpr int RgtFPort = 4;
    constexpr int RgtBPort = 8;
    constexpr int LftFPort = 0;
    constexpr int LftBPort = 5;

    constexpr int kLeftMotor1Port = 0;
    constexpr int kLeftMotor2Port = 1;
    constexpr int kRightMotor1Port = 2;
    constexpr int kRightMotor2Port = 3;

    constexpr int kLeftEncoderPorts[]{0, 1};
    constexpr int kRightEncoderPorts[]{2, 3};
    constexpr bool kLeftEncoderReversed = false;
    constexpr bool kRightEncoderReversed = true;

    constexpr int kEncoderCPR = 1024;
    constexpr double kWheelDiamIn = 6;
    //const double kEncoderDistancePerPulse = ((kWheelDiamIn * std::numbers::pi) / kEncoderCPR);
    constexpr bool kGyroReversed = true;
    constexpr int kPosition = 0;


    //-----------------------------
    //Characterization Values (Change later)
    //-----------------------------

    constexpr auto ks = 0.22_V;
    constexpr auto kv = 1.98 * 1_V * 1_s / 1_m;
    constexpr auto ka = 0.2 * 1_V * 1_s * 1_s / 1_m;

    constexpr double kP = 0.025;
    constexpr double kI = 0.0;
    constexpr double kD = 0.0;



    constexpr double kPDriveVel = 8.5;

    //-----------------
    //Voltage stuffs
    //-----------------
    constexpr int kPeakCurrentAmps = 15;
    constexpr int kPeakTImeMS = 0;
    constexpr int kContinCurrentAmps = 10;

    //-----------------
    //PID Stuffs
    //-----------------
    constexpr auto kTurnTolerance = 5_deg;
    constexpr auto kTurnRateTolerance = 10_deg_per_s;

    constexpr auto kMaxTurnRate = 100_deg_per_s;
    
    constexpr auto kDriveTolerance = 10;
    constexpr double kTargetDist = 0;

}

namespace IntakeConstants{
    //1 falcon 
    // 2 pistons (2/pair)
    //Sensor?? lol
    constexpr int IntakePort = 9;   //Adjust later
    constexpr int IntakeJointPorts [] = {0, 1};
    constexpr int IntakeMainPorts [] = {2, 3};

}

namespace ElevatorConstants{
    constexpr int rgtElevatorPort = 7;
    constexpr int lftElevatorPort = 6;
    constexpr int ExtensionPorts [] = {4, 5};
    constexpr int lowMagPort = 4;   //Change later (Ports for Hall effect sensors)
    constexpr int MidMagPort = 5;
    constexpr int HighMagPort = 6;

    constexpr double ElevatorkP = 0.0;
    constexpr double ElevatorkI = 0.0;
    constexpr double ElevatorkD = 0.0;
    constexpr double ElevatorkF = 0.0;

    constexpr int CruiseVel = 1500;
    constexpr int ElevatorAccl = 1500;

    constexpr int ElevatorDown = 0;
    constexpr int ElevatorPrep = 1000;
    constexpr int ElevatorScore2 = 123000;
    constexpr int ElevatorScore3 = 170000;
    
    
}

namespace SwivelConstants{
    constexpr int swivelPort = 10;
    constexpr int swivelEncPort [] = {8, 9};
        
    //Swivel Presets
    constexpr int down = 0;
    constexpr int prep = 1000;
    constexpr int feeder = 750;
    constexpr int score = 2100;

    constexpr double SwivelkP = 2.3;
    constexpr double SwivelkI = 0.0;
    constexpr double SwivelkD = 0.0;
    constexpr double SwivelkF = 0.0;

    constexpr int CruiseVel = 1000;
    constexpr int SwivelAccl = 1000;


}

namespace ManipulatorConstants{
    //1x 775
    //1 piston
    constexpr int manipulatorPort = 2;
    constexpr int manipulatorPistonPorts [] = {6, 7};

}
namespace OperatorConstants {

constexpr int kDriverControllerPort = 0;
constexpr int kOperatorPannelPort = 1;


}

namespace AutoConstants{
    
}