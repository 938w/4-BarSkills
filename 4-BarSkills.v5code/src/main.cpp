/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\sidhu                                            */
/*    Created:      Mon Feb 28 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 3, 15, 4, 20 
// FourBar              motor         10              
// ForkLift             motor         5               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

class pid {
  private:
    void linedrive (double distance, double dir, float velocity, double porportion, double slowdown) {
      //higher porportion causes the pid "reacting" turning amount to be higher
      //lower porportion causes the pid "reacting" turning amount to be lower
      //velocity changes base speed
      //just set dir to 0
      //slowdown is the decellaration multiplier, higher it is the more it slows down.
      Inertial.resetHeading();
      Inertial.resetRotation();
      if (velocity > 0) {
        //driving forward
        while (((LeftDriveSmart.rotation(rotationUnits::deg)+RightDriveSmart.rotation(rotationUnits::deg))/2)*12.57/3100 < distance) {
          //getting closer
          if(((LeftDriveSmart.rotation(rotationUnits::deg)+RightDriveSmart.rotation(rotationUnits::deg))/2)*12.57/3100 > (distance-6)) {

            //actual pid
            double out = distance-(((LeftDriveSmart.rotation(rotationUnits::deg)+RightDriveSmart.rotation(rotationUnits::deg))/2)*12.57/3100);
            LeftDriveSmart.spin(reverse, (velocity-out*slowdown)-(dir-(Inertial.yaw()*porportion)), vex::velocityUnits::pct);
            RightDriveSmart.spin(reverse, (velocity-out*slowdown)+(dir-(Inertial.yaw()*porportion)), vex::velocityUnits::pct);
          } else {
            //normal
            //actual pid
            LeftDriveSmart.spin(reverse, (velocity-(dir-(Inertial.yaw())*porportion)), vex::velocityUnits::pct);
            RightDriveSmart.spin(reverse, (velocity+(dir-(Inertial.yaw())*porportion)), vex::velocityUnits::pct);
          }
        }
      } else {
        //driving backwards
        while (((LeftDriveSmart.rotation(rotationUnits::deg)+RightDriveSmart.rotation(rotationUnits::deg))/2)*12.57/3100 > distance) {
          //getting closer 
          if(((LeftDriveSmart.rotation(rotationUnits::deg)+RightDriveSmart.rotation(rotationUnits::deg))/2)*12.57/3100 < (distance+6)) {
            //actual pid
            double out = distance-(((LeftDriveSmart.rotation(rotationUnits::deg)+RightDriveSmart.rotation(rotationUnits::deg))/2)*12.57/3100);
            LeftDriveSmart.spin(reverse, (velocity-out*slowdown)+(dir-(Inertial.yaw()*porportion)), vex::velocityUnits::pct);
            RightDriveSmart.spin(reverse, (velocity-out*slowdown)-(dir-(Inertial.yaw()*porportion)), vex::velocityUnits::pct);
          } else{
            //normal
            //actual pid
            LeftDriveSmart.spin(reverse, (velocity+(dir-(Inertial.yaw())*porportion)), vex::velocityUnits::pct);
            RightDriveSmart.spin(reverse, (velocity-(dir-(Inertial.yaw())*porportion)), vex::velocityUnits::pct);
          }
        }
      }
      LeftDriveSmart.stop(brakeType::brake);
      RightDriveSmart.stop(brakeType::brake);
    }
  public:
    void drive (double distance, double dir, float velocity, double porportion, double slowdown) {
      linedrive(distance,dir,velocity,porportion,slowdown);
    }
};
pid PID;
int main() {
  // // Initializing Robot Configuration. DO NOT REMOVE!
 vexcodeInit();
  Mobile.Screen.print(Inertial.heading());
  //Set Velocity
  leftMotorA.setVelocity(100, percent);
  leftMotorB.setVelocity(100, percent);
  rightMotorA.setVelocity(100, percent);
  rightMotorB.setVelocity(100, percent);
  //Lower fork lift
  ForkLift.spinFor(reverse, 1100, degrees, 100, rpm); 
  // Drive to blue goal
  Drivetrain.driveFor(forward, 16, inches, 140, rpm);
  Drivetrain.stop();
  //Pick up
  ForkLift.spinFor(forward, 500, degrees, 100, rpm); 
  //Turn 90 degrees to face neutral goal
  Drivetrain.turnFor(left, 270, degrees, 100, rpm);
  //Activate clamp
  Clamp.set(true); 
  //Drive to neutral goal
  Drivetrain.driveFor(reverse, 20, inches, 175, rpm);
  //Clamp neutral
  Clamp.set(false); 


  

  


}