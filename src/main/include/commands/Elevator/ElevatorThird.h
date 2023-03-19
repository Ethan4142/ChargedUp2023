#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Elevator.h"

class ElevatorThird : public frc2::CommandHelper<frc2::CommandBase, ElevatorThird>{
    public:
     ElevatorThird(Elevator* subsystem);

     void Initialize();
     void Execute();
     bool IsFinished();
    
    private:
     Elevator* pchs_Elevator;
};