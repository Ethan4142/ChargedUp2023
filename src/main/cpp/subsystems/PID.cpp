// #include "subsystems/PID.h"

// PID::PID(double kP, double kI, double kD, double dT, double min, double max) :
//     _kp(kP),
//     _ki(kI),
//     _kd(kD),
//     _dt(dT),
//     _min(min),
//     _max(max),
//     _prevErr(0),
//     _integral(0)
//     {
//     }

// double PID::Calculate(double setpoint, double input){
//     double error = setpoint - input;

//     double Pout = _kp * error;

//     _integral += error * _dt;

//     double Iout = _ki * _integral;

//     double derivative = (error - _prevErr) / _dt;
//     double Dout = _kd * derivative;

//     double output = Pout + Iout + Dout;

//     if(output > _max){
//         output = _max;
//     }
//     else if( output < _min){
//         output = _min;
//     }

//     _prevErr = error;
//     return output;
// }