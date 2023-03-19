#ifndef JOYSTICK_AXIS_GREATER_THAN_TRIGGER
#define JOYSTICK_AXIS_GREATER_THAN_TRIGGER

#include <frc/Joystick.h>
#include <frc2/command/button/CommandJoystick.h>
#include <frc2/command/Command.h>
#include <frc2/command/button/Trigger.h>

class JoystickAxisGreaterThanTrigger : public frc2::Trigger {
    public:
     JoystickAxisGreaterThanTrigger(frc2::CommandJoystick* joystick, int axis, frc2::Command* command);
     bool Get();

    private:
     frc::Joystick* joystick_;
     int axis_;
     frc2::Command* m_command;
};


#endif
