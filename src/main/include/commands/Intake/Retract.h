#pragma once
#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Intake.h"

class Retract : public frc2::CommandHelper<frc2::CommandBase, Retract>{
    public: 
     Retract(Intake* subsytem);
     void Initialize() override;
     bool IsFinished() override;
    
    private:
     Intake* pchsIntake;

};