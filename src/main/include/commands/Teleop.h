#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Drive.h"

class Teleop 
    : public frc2::CommandHelper<frc2::CommandBase, Teleop> {
  public:
   explicit Teleop(Drive* subsystem, std::function<double()> y,
                  std::function<double()> x);

   void Initialize();
   void Execute() override;

   bool IsFinished();

   void End();

  private:
   Drive* pchs_Drive;
   std::function<double()> m_y;
   std::function<double()> m_x;
};