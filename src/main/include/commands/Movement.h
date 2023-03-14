#pragma once 
#include <frc2/command/CommandHelper.h>
#include "subsystems/Drive.h"
#include "subsystems/PID.h"

// class Movement : public frc2::CommandHelper<frc2::CommandBase, Movement>{
//     public:
//     Movement(Drive* subsytem, double dist, double speed);

//     void Initialize();

//     void Execute() override;

//     bool IsFinished();

//     void End();

//     private:
//      Drive* pchs_Drive;
//      double dist;
//      double speed;
// };