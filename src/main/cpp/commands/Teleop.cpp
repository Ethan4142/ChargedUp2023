#include "commands/Teleop.h"

#include "Robot.h"

Teleop::Teleop(Drive* subsystem,
                std::function<double()> y,
                std::function<double()> x)
    : pchs_Drive{subsystem},
      m_y{std::move(y)},
      m_x{std::move(x)} {
        AddRequirements({subsystem});
      }

void Teleop::Initialize(){
    //
}

void Teleop::Execute(){
    
    pchs_Drive->Arcade(m_y(), m_x());   //Test This if not reverse it back to normal
}

bool Teleop::IsFinished(){
    return false;
}

void Teleop::End(){
    pchs_Drive->SetDrive(0,0);
}

