#pragma once

class PID
{
public:
    PID(double kP, double kI, double kD, double dT, double min, double max);

   double Calculate(double setpoint, double input);

private:
    double _max;
    double _min;
    double _kp;
    double _ki;
    double _kd;
    double _error;
    double _prevErr;
    double _delta;
    double _integral;
    double _dt;


    

};
