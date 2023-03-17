#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Intake.h"

class Extend : public frc2::CommandHelper<frc2::CommandBase, Extend>{
    public:
     Extend(Intake* subsystem);

     void Initialize() override;

     bool IsFinished() override;
    
    private:
     Intake* pchs_Intake;
};