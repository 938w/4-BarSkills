
#include "route1.h"
#include "logging.h"
#include "vex.h"
#include "pid.h"
#include <cmath>

using namespace vex;
timer t1;
void Route1::run() {
  Logger logger("rout 1");
  logger.log("start the run");
  pid PID;

  Brain.Screen.print("route 1");
 
  Mobile.Screen.print(Inertial.heading());
  //Set Velocity
  leftMotorA.setVelocity(100, percent);
  leftMotorB.setVelocity(100, percent);
  rightMotorA.setVelocity(100, percent);
  rightMotorB.setVelocity(100, percent);
  //Lower fork lift
  
  ForkLift.spinFor(reverse, 530, degrees, 100, rpm); 
  ForkLift.spinFor(forward, 10, degrees, false);
  // Drive to blue goal
  Drivetrain.driveFor(forward, 15.5, inches, 140, rpm);
  Drivetrain.stop();
  //Pick up
  ForkLift.spinFor(forward, 350, degrees, 100, rpm); 
  //drive backwards a little bit
  Drivetrain.driveFor(reverse, 16, inches, 120, rpm);
  //Turn 90 degrees to face neutral goal
  Drivetrain.turnToHeading(108, degrees, 100, rpm);
  //Activate clamp
  Clamp.set(true); 
  
  //Drive to neutral goal
  Drivetrain.driveFor(reverse, 50, inches, 80, rpm);
  
  Drivetrain.stop(brake);
  wait(0.8, sec);
  //Clamp neutral
  Clamp.set(false); 
  //go to platform
  FourBar.spinFor(forward, 770, degrees, 100, rpm, false);
  Drivetrain.turnFor(right, 10, degrees);
  wait(0.2, sec);
  Drivetrain.driveFor(reverse, 54, inches, 100,rpm);
  FourBar.spinFor(reverse, 75, degrees, false);
  //Turn so goal is closer to the platforms center of gravity
  //Drivetrain.turnFor(right, 25, degrees); 
  //Lower fourbar so goal doesn't tip over while dropping
  
  FourBar.spinFor(reverse, 240, degrees); 
  Drivetrain.turnFor(left, 15, degrees);

  //Release
  Clamp.set(true); 
  //getbluegoal  
  Drivetrain.turnFor(right, 15, degrees);
  t1.reset();
  //placebluegoal and move forward while loweringfourbar
    ForkLift.spinFor(reverse, 355, degrees, 70, rpm, false);
    Drivetrain.driveFor(forward, 10, inches, 120, rpm);
    FourBar.spinFor(reverse, 520, degrees, false);
    Drivetrain.driveFor(forward, 17, inches, 120, rpm);
    Drivetrain.stop(brake);
    wait(0.3, sec);
    //moveback
    Drivetrain.driveFor(reverse, 15, inches, 175, rpm);
    Drivetrain.turnFor(185, degrees, 100, rpm);
    //moveforward
    PID.drive(-17, (Inertial.yaw()*-1), 80, 1);
    Mobile.Screen.newLine();
    Mobile.Screen.print(t1.time(sec));

  //clamp
  Clamp.set(false);
  FourBar.spinFor(forward, 200, degrees);
  //turn to red
  Drivetrain.turnToHeading(-130, degrees, 150, rpm);
  //drive to red
  Drivetrain.driveFor(forward, 30, inches, 80, rpm);
  //pic up red
  ForkLift.spinFor(forward, 350, degrees, 100, rpm, false);
  wait(0.5, sec);
  FourBar.spinFor(forward, 600, degrees, 100, rpm, false);
  Drivetrain.driveFor(reverse, 26, inches, 100, rpm);
  //turn to ramp
  Drivetrain.turnToHeading(130, degrees, 200, rpm);
  //go to ramp
  Drivetrain.driveFor(reverse, 30, inches, 100, rpm);
  //turna bitmore
  Drivetrain.turnToHeading(140, degrees, 200, rpm);
  
  //go a bit more
  Drivetrain.driveFor(reverse, 13, inches);
  FourBar.spinFor(reverse, 250, degrees);
  //turn to ramp
  Drivetrain.turnToHeading(110, degrees, 100, rpm);
  Clamp.set(true);
  wait(0.5, sec);
  //drive out
  
  Drivetrain.turnToHeading(90, degrees, 100, rpm);
  Drivetrain.driveFor(forward, 10, inches, 180, rpm);
  FourBar.spinTo(0, degrees, 100, rpm, false);
  //Drivetrain.driveFor(forward, 50, inches, 160, rpm);
  PID.drive(60, 90, 90, 1);
  //turn to neutral
  Drivetrain.turnToHeading(130, degrees, 160, rpm);
  //go to neutral
  Drivetrain.driveFor(reverse, 40, inches, 160, rpm);
  //p
  Clamp.set(false);
  //turnaround
  wait(0.7, sec);
  FourBar.spinFor(forward, 150, degrees, false);
  Drivetrain.turnToHeading(-40, degrees, 140, rpm);
  FourBar.spinFor(forward, 520, degrees, false);
  Drivetrain.driveFor(reverse, 50, inches);
  Drivetrain.turnToHeading(-90, degrees, 100, rpm);
  Drivetrain.driveFor(reverse, 20, inches, 100, rpm);
  //release
  Clamp.set(true);
  wait(0.7, sec);
  //drive
  Drivetrain.driveFor(forward, 20, inches);
  logger.log("end the run");
}