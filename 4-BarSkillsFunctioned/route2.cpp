
#include "route2.h"
#include "logging.h"
#include "pid.h"
#include "vex.h"
#include <cmath>

using namespace vex;
/*
void DrivetrainFunctions(std::string dir, double moveval, int rpmval) {
  if (dir == "reverse") {
    Drivetrain.driveFor(reverse, moveval, inches, rpmval, rpm);
  }
  if (dir == "forward") {
    Drivetrain.driveFor(reverse, moveval, inches, rpmval, rpm);
  }
  if (dir == "left") {
    Drivetrain.turnFor(left, moveval, degrees, rpmval, rpm);
  }
  if (dir == "right") {
    Drivetrain.turnFor(right, moveval, degrees, rpmval, rpm);
  }
}
void ClampRealease(std::string realease) {
  if (realease == "Clamp") {
    Clamp.set(false);
  }
  if (realease == "UnClamp") {
    Clamp.set(true);
  }
}


void MoveBothBars(std::string type, std::string dir, double degree, double rpmval) {
  if (type == "FourBar") {
    if (dir == "down") {
      FourBar.spinFor(reverse, degree, degrees, rpmval, rpm);
    }
    if (dir == "up")
    FourBar.spinFor(forward, degree, degrees, rpmval, rpm);
  }
  if (type == "ForkLift") {
    if (dir == "up") {
      ForkLift.spinFor(forward, degree, degrees, rpmval, rpm);
    }
    if (dir == "down") {
      ForkLift.spinFor(reverse, degree, degrees, rpmval, rpm); 
    }
  }
}
*/
void Route2::run() {
  Mobile.Screen.print(Inertial.yaw());

  timer t1;
  timer t2;
  Logger logger("route2");
  logger.log("start the run");
  pid PID;
  t2.reset();
  Brain.Screen.print("route 2");

  // Set Velocity
  leftMotorA.setVelocity(100, percent);
  leftMotorB.setVelocity(100, percent);
  rightMotorA.setVelocity(100, percent);
  rightMotorB.setVelocity(100, percent);
  // Lower fork lift

  ForkLift.spinFor(reverse, 530, degrees, 100, rpm);
  ForkLift.spinFor(forward, 10, degrees, false);
  // Drive to blue goal
  Drivetrain.driveFor(forward, 16, inches, 140, rpm);
  Drivetrain.stop();
  // Pick up
  ForkLift.spinFor(forward, 350, degrees, 100, rpm);
  // drive backwards a little bit
  // Drivetrain.driveFor(reverse, 16, inches, 120, rpm);
  PID.drive(-16.5, 0, -100, 1);
  // Turn 90 degrees to face neutral goal
  Drivetrain.turnToHeading(108, degrees, 100, rpm);

  // Activate clamp
  Clamp.set(true);

  // Drive to neutral goal
  // Drivetrain.driveFor(reverse, 50, inches, 80, rpm);
  PID.drive(-50, Inertial.yaw(), -100, 1);

  Drivetrain.stop(brake);

  // Clamp neutral
  Clamp.set(false);
  wait(0.8, sec);
  // go to platform
  FourBar.spinFor(forward, 770, degrees, 100, rpm, false);
  Drivetrain.turnFor(right, 13, degrees);
  wait(0.2, sec);
  // Drivetrain.driveFor(reverse, 54, inches, 100,rpm);
  PID.drive(-54, Inertial.yaw(), -100, 1);
  FourBar.spinFor(reverse, 75, degrees, false);
  // Turn so goal is closer to the platforms center of gravity
  // Drivetrain.turnFor(right, 25, degrees);
  // Lower fourbar so goal doesn't tip over while dropping

  FourBar.spinFor(reverse, 240, degrees);
  // faster
  double headingwhere = Inertial.heading();
  LeftDriveSmart.rotateFor(reverse, 60, degrees, 160, rpm, false);
  RightDriveSmart.rotateFor(forward, 60, degrees, 160, rpm);
  Clamp.set(true);
  Drivetrain.turnToHeading(headingwhere, degrees);

  // Release
  // Clamp.set(true);
  // getbluegoal
  // Drivetrain.turnFor(right, 13, degrees);
  t1.reset();
  // placebluegoal and move forward while loweringfourbar
  ForkLift.spinFor(reverse, 360, degrees, 70, rpm, false);
  Drivetrain.driveFor(forward, 10, inches, 120, rpm);
  FourBar.spinFor(reverse, 520, degrees, false);
  Drivetrain.driveFor(forward, 17, inches, 120, rpm);
  Drivetrain.stop(brake);
  wait(0.3, sec);
  // moveback
  Drivetrain.driveFor(reverse, 16, inches, 175, rpm);
  Drivetrain.turnFor(180, degrees, 100, rpm);
  // moveforward

  PID.drive(-21, Inertial.yaw(), -80, 1);
  Mobile.Screen.newLine();
  Mobile.Screen.print(t1.time(sec));
  // clamp
  Clamp.set(false);
  FourBar.spinFor(forward, 200, degrees);
  // turn to red
  Drivetrain.turnToHeading(-130, degrees, 150, rpm);
  Mobile.Screen.newLine();
  Mobile.Screen.print(Inertial.yaw());
  // drive to red
  ForkLift.spinFor(reverse, 15, degrees, false);
  // Drivetrain.driveFor(forward, 30, inches, 80, rpm);
  PID.drive(34.5, Inertial.yaw(), 100, 0.9);
  // pick up red
  ForkLift.spinFor(forward, 350, degrees, 100, rpm, false);
  wait(0.5, sec);
  FourBar.spinFor(forward, 460, degrees, 100, rpm, false);
  // Drivetrain.driveFor(reverse, 26, inches, 100, rpm);
  PID.drive(-27.5, Inertial.yaw(), -100, 1);
  // turn to ramp

  Drivetrain.turnToHeading(140, degrees, 200, rpm);
  // go to ramp
  // Drivetrain.driveFor(reverse, 50, inches, 100, rpm);
  PID.drive(-38, Inertial.yaw(), -75, 1);
  FourBar.spinFor(reverse, 90, degrees, 100, rpm);
  // turn to ramp
  LeftDriveSmart.rotateFor(reverse, 80, degrees, 160, rpm, false);
  RightDriveSmart.rotateFor(forward, 80, degrees, 160, rpm);
  Drivetrain.driveFor(reverse, 4, inches);
  Clamp.set(true);
  wait(0.2, sec);

  // drive out

  Drivetrain.turnToHeading(90, degrees, 100, rpm);
  FourBar.spinTo(0, degrees, 100, rpm, false);
  // Drivetrain.driveFor(forward, 10, inches, 180, rpm);

  // push middle goal
  Drivetrain.driveFor(forward, 58, inches, 120, rpm);
  // PID.drive(68, Inertial.yaw(), 70, 1.2);
  // turn to neutral

  Drivetrain.turnToHeading(200, degrees, 160, rpm);

  // go to neutral
  // Drivetrain.driveFor(reverse, 40, inches, 160, rpm);
  PID.drive(-43, Inertial.yaw(), -100, 1);
  // p
  Clamp.set(false);
  // turnaround
  wait(0.4, sec);
  FourBar.spinFor(forward, 670, degrees, false);

  Drivetrain.turnToHeading(-65, degrees, 140, rpm);

  PID.drive(-44, Inertial.yaw(), -100, 1);

  // Drivetrain.turnFor(right, 15, degrees);
  LeftDriveSmart.rotateFor(forward, 90, degrees, 160, rpm, false);
  RightDriveSmart.rotateFor(reverse, 90, degrees, 160, rpm);
  // Lower fourbar
  FourBar.spinFor(reverse, 150, degrees, 100, rpm, false);
  Drivetrain.driveFor(reverse, 3.5, inches, 200, rpm);
  // release
  Clamp.set(true);
  wait(0.5, sec);
  Drivetrain.driveFor(forward, 4, inches, 200, rpm);
  LeftDriveSmart.rotateFor(forward, 120, degrees, 160, rpm, false);
  RightDriveSmart.rotateFor(reverse, 120, degrees, 160, rpm);
  /*
  // drive

  ForkLift.spinFor(reverse, 360, degrees, 70, rpm, false);
  Drivetrain.driveFor(forward, 10, inches, 120, rpm);
  FourBar.spinTo(0, degrees, false);
  Drivetrain.driveFor(forward, 16, inches, 120, rpm);
  Drivetrain.stop(brake);
  wait(0.3, sec);
  // moveback
  Drivetrain.driveFor(reverse, 12, inches, 175, rpm);
  Drivetrain.turnFor(180, degrees, 100, rpm);
  // moveforward

  PID.drive(-17, Inertial.yaw(), -80, 1);
  Mobile.Screen.newLine();
  Mobile.Screen.print(t1.time(sec));
  Clamp.set(false);
  // liftup and turnaround
  FourBar.spinFor(forward, 520, degrees, false);
  wait(0.4, sec);
  Drivetrain.turnToHeading(-60, degrees);
  Drivetrain.driveFor(reverse, 33, inches, 200, rpm);
  Clamp.set(true);
  */

  Mobile.Screen.newLine();
  Mobile.Screen.print("L");
  Mobile.Screen.print(t2.time(sec));
  Mobile.rumble(".-.-");

  logger.log("end the run");
}