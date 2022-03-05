#include "route1.h"
#include "vex.h"

using namespace vex;

void Route1::run() {

  Brain.Screen.print("route 1");

  Mobile.Screen.print(Inertial.heading());
  // Set Velocity
  leftMotorA.setVelocity(100, percent);
  leftMotorB.setVelocity(100, percent);
  rightMotorA.setVelocity(100, percent);
  rightMotorB.setVelocity(100, percent);
  // Lower fork lift
  ForkLift.spinFor(reverse, 1100, degrees, 100, rpm);
  // Drive to blue goal
  Drivetrain.driveFor(forward, 16, inches, 140, rpm);
  Drivetrain.stop();
  // Pick up
  ForkLift.spinFor(forward, 500, degrees, 100, rpm);
  // Turn 90 degrees to face neutral goal
  Drivetrain.turnFor(left, 270, degrees, 100, rpm);
  // Activate clamp
  Clamp.set(true);
  // Drive to neutral goal
  Drivetrain.driveFor(reverse, 20, inches, 175, rpm);
  // Clamp neutral
  Clamp.set(false);
}