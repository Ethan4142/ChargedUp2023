#include "commands/Elevator/ElevatorThird.h"

ElevatorThird::ElevatorThird(Elevator* subsystem) : pchs_Elevator(subsystem){
    AddRequirements(subsystem);
}

void ElevatorThird::Initialize(){
    pchs_Elevator->ResetElevatorEnc();
    pchs_Elevator->SetElevator(0.5);

}

void ElevatorThird::Execute(){
    
}

bool ElevatorThird::IsFinished(){
    if(pchs_Elevator->GetElevator() >= 500){
        return true;
    }
    else{
        return false;
    }
}