#include "JoystickAxisGreaterTrigger.h"

JoystickAxisGreaterThanTrigger::JoystickAxisGreaterThanTrigger(frc2::CommandJoystick* joystick, int axis, frc2::Command* command)
    : joystick_(joystick), axis_(axis), m_command(command) {}

bool JoystickAxisGreaterThanTrigger::Get(){
    if(joystick_->GetRawAxis(axis_) > 0){
        m_command -> Schedule();
        return true;
    }
    else{
        return false;
    }
}