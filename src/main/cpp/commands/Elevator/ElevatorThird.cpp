// #include "commands/Elevator/ElevatorThird.h"


// ElevatorThird::ElevatorThird(Elevator* subsystem)
//     : m_elevator(subsystem){
//         AddRequirements({subsystem});
//     }

// void ElevatorThird::Initialize(){
//     m_elevator-> extend(true);
//     m_elevator -> ResetElevatorEnc();
// }

// void ElevatorThird::Execute(){
//     m_elevator -> SetElevator(0.3);
// }

// void ElevatorThird::End(bool interrupted){
//     m_elevator -> SetElevator(0);
// }

// bool ElevatorThird::IsFinished(){
//     return m_elevator->GetElevator() > 170000;
// }