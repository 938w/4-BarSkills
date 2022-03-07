#include "route.h"
#include "vex.h"

using namespace vex;

// in inches
int Route::drivePos() {
  return ((rightMotorA.rotation(deg) + leftMotorA.rotation(deg))/2) * (12.57/360);
}

// using Drivetrain.isMoving() && Route.isDriving() to check whether the robot is stuck
bool Route::isDriving() {
  static int count = 0;
  static int last = 0;
  static int lastTarget = 0;

  int curr = drivePos();

  int target = _driveTarget;

  if(abs(last-curr) < 0.0419)
    count++;
  else
    count = 0;

  if(target != lastTarget)
    count = 0;

  lastTarget = target;
  last = curr;

  //not driving if we haven't moved
  if(count > 4)
    return false;
  else
    return true;
  return false;
}