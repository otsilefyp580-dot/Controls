#ifndef PID_H
#define PID_H

class PID
{
    private:
        double kp;
        double ki;
        double kd;

        double integral = 0;
        double previousError = 0;


    public:

        //Constructor
        PID(double kp, double ki, double kd):kp(kp),ki(ki),kd(kd){}

        double update(double setpoint, double measured, double dt){
            double error = setpoint - measured;
            integral = integral + error * dt;
            double derivative = (error - previousError) / dt;

            previousError = error;

            return (kp * error) +(ki * integral) + (kd * derivative);
        }

        void rest(){
            previousError = 0;
            integral = 0;
        }


};
#endif