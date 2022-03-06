#include "route1.h"
#include "vex.h"
#include "pid.h"
pid PID;
using namespace vex;
timer t1;
void Route1::run() {
  
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
  wait(0.5, sec);
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
    Drivetrain.driveFor(reverse, 17, inches, 100, rpm);
    Mobile.Screen.newLine();
    Mobile.Screen.print(t1.time(sec));

  //clamp
  Clamp.set(false);
  FourBar.spinFor(forward, 200, degrees);
  //turn to red
  Drivetrain.turnToHeading(-130, degrees, 150, rpm);
  //drive to red
  Drivetrain.driveFor(forward, 29, inches, 80, rpm);
  //pic up red
  ForkLift.spinFor(forward, 350, degrees, 100, rpm, false);
  wait(0.5, sec);
  FourBar.spinFor(forward, 600, degrees, 100, rpm, false);
  Drivetrain.driveFor(reverse, 25, inches, 100, rpm);
  //turn to ramp
  Drivetrain.turnToHeading(130, degrees);
  //go to ramp
  Drivetrain.driveFor(reverse, 30, inches, 100, rpm);
  //turna bitmore
  Drivetrain.turnToHeading(140, degrees);
  
  //go a bit more
  Drivetrain.driveFor(reverse, 13, inches);
  FourBar.spinFor(reverse, 250, degrees);
  //turn to ramp
  Drivetrain.turnToHeading(110, degrees, 100, rpm);
  Clamp.set(true);
  wait(0.5, sec);
  //dirve out
  Drivetrain.turnToHeading(90, degrees, 100, rpm);
  Drivetrain.driveFor(forward, 10, inches, 160, rpm);
  FourBar.spinTo(0, degrees, 100, rpm);
  Drivetrain.driveFor(forward, 50, inches, 160, rpm);
  //turn to neutral
  Drivetrain.turnToHeading(130, degrees);
  //go to neutral
  Drivetrain.driveFor(reverse, 40, inches, 160, rpm);
  //
  Clamp.set(false);


  
}