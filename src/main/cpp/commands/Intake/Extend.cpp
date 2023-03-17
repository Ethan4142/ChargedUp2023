#include "commands/Intake/Extend.h"

Extend::Extend(Intake* subsystem) : pchs_Intake(subsystem){
    AddRequirements(subsystem);
}

void Extend::Initialize(){
    pchs_Intake->moveMain();
}

bool Extend::IsFinished(){
    return false;
}