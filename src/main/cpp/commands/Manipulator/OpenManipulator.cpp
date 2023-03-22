// #include "commands/Manipulator/OpenManipulator.h"

// OpenManipulator::OpenManipulator(Manipulator* subsystem)
//     : m_manipulator(subsystem){
//         AddRequirements({subsystem});
// }

// void OpenManipulator::Initialize(){

// }

// void OpenManipulator::Execute(){
//     m_manipulator->open(true);
//     m_manipulator->setManipulator(-0.35);
// }

// void OpenManipulator::End(bool interrupted){
//     m_manipulator->open(false);
//     m_manipulator->setManipulator(0);
// }

// bool OpenManipulator::IsFinished(){
//     if(m_manipulator->getStatus() == true){
//         return true;
//     }
//     else{
//         return false;
//     }
// }