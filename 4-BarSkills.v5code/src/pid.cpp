#include "pid.h"
#include <cmath>

using namespace std;

void pid::linedrive(double distance, double dir, double velocity, double porportion) {
   //higher porportion causes the pid "reacting" turning amount to be higher
      //lower porportion causes the pid "reacting" turning amount to be lower
      //velocity changes base speed
      //just set dir to 0
      Inertial.resetHeading();
      Inertial.resetRotation();
      LeftDriveSmart.resetRotation();
      RightDriveSmart.resetRotation();

      double lastOut = 0;
      int count = 0;

      if (velocity > 0) {
        //driving forward
        while (((LeftDriveSmart.rotation(rotationUnits::deg)+RightDriveSmart.rotation(rotationUnits::deg))/2)*12.57/360 < distance) {
          // getting closer
          // always slow down when there is 1 rotation
          if(((LeftDriveSmart.rotation(rotationUnits::deg)+RightDriveSmart.rotation(rotationUnits::deg))/2)*12.57/360 > (distance - 12.57*2)) {
           
            // actual pid
            // disstance to the target
            double out = distance-(((LeftDriveSmart.rotation(rotationUnits::deg)+RightDriveSmart.rotation(rotationUnits::deg))/2)*12.57/360);

            // 10 rpm with 20 mesc = 0.419inches
            if (abs(lastOut - out) < 0.0419) {             
              count++;
            }

            if (count > 4) {
              Mobile.Screen.print("exit");
              break;
            }
            
            lastOut = out;

            // new velocity slow until 10%
            // every step 10 percent within 20ms
            double newVelocity = velocity * (out / (12.57*2));
            if (newVelocity < 10) newVelocity = 10;

            double error = (dir-(Inertial.yaw()*porportion));

            LeftDriveSmart.spin(vex::directionType::fwd, newVelocity+error, vex::velocityUnits::pct);
            RightDriveSmart.spin(vex::directionType::fwd, newVelocity-error, vex::velocityUnits::pct);
          } else {
            //actual pid     
            LeftDriveSmart.spin(vex::directionType::fwd, (velocity+(dir-(Inertial.yaw())*porportion)), vex::velocityUnits::pct);
            RightDriveSmart.spin(vex::directionType::fwd, (velocity-(dir-(Inertial.yaw())*porportion)), vex::velocityUnits::pct);
          }
          wait(20, msec);
        }

      } else {
        //driving backwards
        while (((LeftDriveSmart.rotation(rotationUnits::deg)+RightDriveSmart.rotation(rotationUnits::deg))/2)*12.57/360 > distance) {
          //getting closer 
          if(((LeftDriveSmart.rotation(rotationUnits::deg)+RightDriveSmart.rotation(rotationUnits::deg))/2)*12.57/360 < (distance+12.57*2)) {
        
            //actual pid
            double out = distance-(((LeftDriveSmart.rotation(rotationUnits::deg)+RightDriveSmart.rotation(rotationUnits::deg))/2)*12.57/360);

            // 10 rpm with 20 mesc = 0.419inches 
            if (abs(lastOut - out) < 0.0419) {             
              count++;
            }

            if (count > 4) {
              Mobile.Screen.print("exit");
              break;
            }
            
            lastOut = out;
            // new velocity slow until 10%
            // every step 10 percent within 20ms
            float newVelocity = -1 * velocity * (out / (12.57*2));
            if (newVelocity > -10) newVelocity = -10;

            LeftDriveSmart.spin(vex::directionType::fwd, newVelocity+(dir-(Inertial.yaw()*porportion)), vex::velocityUnits::pct);
            RightDriveSmart.spin(vex::directionType::fwd, newVelocity-(dir-(Inertial.yaw()*porportion)), vex::velocityUnits::pct);
          } else{
            //actual pid
            LeftDriveSmart.spin(vex::directionType::fwd, (velocity+(dir-(Inertial.yaw())*porportion)), vex::velocityUnits::pct);
            RightDriveSmart.spin(vex::directionType::fwd, (velocity-(dir-(Inertial.yaw())*porportion)), vex::velocityUnits::pct);
          }

          wait(20, msec);
        }
      }
      LeftDriveSmart.stop(brakeType::brake);
      RightDriveSmart.stop(brakeType::brake);
}

void pid::drive(double distance, double dir, double velocity, double porportion) {
  linedrive(distance, dir, velocity, porportion);
}