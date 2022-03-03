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
/*class pid {
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
        while (((LeftDriveSmart.rotation(rotationUnits::deg)+RightDriveSmart.rotation(rotationUnits::deg))/2)*12.57/360 < distance) {
          //getting closer
          if(((LeftDriveSmart.rotation(rotationUnits::deg)+RightDriveSmart.rotation(rotationUnits::deg))/2)*12.57/360 > (distance-6)) {

            //actual pid
            double out = distance-(((LeftDriveSmart.rotation(rotationUnits::deg)+RightDriveSmart.rotation(rotationUnits::deg))/2)*12.57/360);
            LeftDriveSmart.spin(vex::directionType::fwd, (velocity-out*slowdown)-(dir-(Inertial.yaw()*porportion)), vex::velocityUnits::pct);
            RightDriveSmart.spin(vex::directionType::fwd, (velocity-out*slowdown)+(dir-(Inertial.yaw()*porportion)), vex::velocityUnits::pct);
          } else {
            //normal
            //actual pid
            LeftDriveSmart.spin(vex::directionType::fwd, (velocity-(dir-(Inertial.yaw())*porportion)), vex::velocityUnits::pct);
            RightDriveSmart.spin(vex::directionType::fwd, (velocity+(dir-(Inertial.yaw())*porportion)), vex::velocityUnits::pct);
          }
        }
      } else {
        //driving backwards
        while (((LeftDriveSmart.rotation(rotationUnits::deg)+RightDriveSmart.rotation(rotationUnits::deg))/2)*12.57/360 > distance) {
          //getting closer 
          if(((LeftDriveSmart.rotation(rotationUnits::deg)+RightDriveSmart.rotation(rotationUnits::deg))/2)*12.57/360 < (distance+6)) {
            //actual pid
            double out = distance-(((LeftDriveSmart.rotation(rotationUnits::deg)+RightDriveSmart.rotation(rotationUnits::deg))/2)*12.57/360);
            LeftDriveSmart.spin(vex::directionType::fwd, (velocity-out*slowdown)+(dir-(Inertial.yaw()*porportion)), vex::velocityUnits::pct);
            RightDriveSmart.spin(vex::directionType::fwd, (velocity-out*slowdown)-(dir-(Inertial.yaw()*porportion)), vex::velocityUnits::pct);
          } else{
            //normal
            //actual pid
            LeftDriveSmart.spin(vex::directionType::fwd, (velocity+(dir-(Inertial.yaw())*porportion)), vex::velocityUnits::pct);
            RightDriveSmart.spin(vex::directionType::fwd, (velocity-(dir-(Inertial.yaw())*porportion)), vex::velocityUnits::pct);
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
*/
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  //Activate Clamp (move up)
  Clamp.set(true); 
  //Drive to neutral goal ahead
  Drivetrain.driveFor(forward, 55, inches);
  //wait so goal doesn't bounce away
  //Clamp goal
  Clamp.set(false);
  //Lift the goal slightly (only slightly to prevent excessive tipping)
  FourBar.spinFor(300, degrees, 100, rpm);
  //Move forward more
  Drivetrain.driveFor(forward, 15, inches); 
  //Turn to platform  
  //Drivetrain.turnFor(30, degrees, 200, rpm);
  Drivetrain.stop();
  


}