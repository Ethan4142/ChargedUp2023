#pragma once

#include "Constants.h"
#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include <ctre/phoenix/motorcontrol/ControlMode.h>
#include <frc/Encoder.h>

using namespace SwivelConstants;

class Swivel : public frc2::SubsystemBase{
    public:
     Swivel();
     
     void resetSwivel();
     
     [[nodiscard]] frc2::CommandPtr SwivelDownCommand();

     [[nodiscard]] frc2::CommandPtr PrepSwivelCommand();

     [[nodiscard]] frc2::CommandPtr SwivelScoreCommand();

    
    private:
     ctre::phoenix::motorcontrol::can::WPI_TalonSRX swivelMotor{SwivelConstants::swivelPort};
     frc::Encoder SwivelEncoder{SwivelConstants::swivelEncPort[0], SwivelConstants::swivelEncPort[1]};


};
