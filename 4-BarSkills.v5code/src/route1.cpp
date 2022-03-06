#include "route1.h"
#include "vex.h"

using namespace vex;
timer t1;
void Route1::run() {

  Brain.Screen.print("route 1");
  Brain.Screen.print("att2");
  Mobile.Screen.print(Inertial.heading());
  //Set Velocity
  leftMotorA.setVelocity(100, percent);
  leftMotorB.setVelocity(100, percent);
  rightMotorA.setVelocity(100, percent);
  rightMotorB.setVelocity(100, percent);
  //Lower fork lift
  ForkLift.spinFor(reverse, 550, degrees, 100, rpm); 
  // Drive to blue goal
  Drivetrain.driveFor(forward, 15.5, inches, 140, rpm);
  Drivetrain.stop();
  //Pick up
  ForkLift.spinFor(forward, 350, degrees, 100, rpm); 
  //drive backwards a little bit
  Drivetrain.driveFor(reverse, 16, inches, 140, rpm);
  //Turn 90 degrees to face neutral goal
  Drivetrain.turnToHeading(108, degrees, 100, rpm);
  //Activate clamp
  Clamp.set(true); 
  
  //Drive to neutral goal
  Drivetrain.driveFor(reverse, 50, inches, 100, rpm);
  
  Drivetrain.stop(brake);
  wait(0.2, sec);
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
  //Release
  Clamp.set(true); 
  //getbluegoal
  t1.reset();
    ForkLift.spinFor(reverse, 340, degrees, 100 ,rpm, false);
    Drivetrain.driveFor(forward, 10, inches, 200, rpm);
    FourBar.spinFor(reverse, 500, degrees, false);
    Drivetrain.driveFor(forward, 10, inches, 175, rpm);
    Drivetrain.stop(brake);
    wait(0.2, sec);
    Drivetrain.driveFor(reverse, 10, inches, 175, rpm);
    Drivetrain.turnFor(180, degrees, 170, rpm);
    Drivetrain.driveFor(reverse, 12, inches, 175, rpm); 
    Mobile.Screen.newLine();
    Mobile.Screen.print(t1.time(sec));

  //clamp
  Clamp.set(false);
  FourBar.spinFor(forward, 200, degrees);
  //turn to red
  Drivetrain.turnToHeading(-160, degrees, 150, rpm);
  //drive to red
  Drivetrain.driveFor(forward, 20, inches, 175, rpm);
  //pic up red
  ForkLift.spinFor(forward, 350, degrees, 100, rpm, false);
  wait(0.5, sec);
  Drivetrain.driveFor(reverse, 20, inches, 100, rpm);




  
}