#include "route.h"
#include "vex.h"

using namespace vex;

int Route::drivePos() {
  return (rightMotorA.rotation(deg) + leftMotorA.rotation(deg))/2;
}

bool Route::isDriving() {
  static int count = 0;
  static int last = 0;
  static int lastTarget = 0;

  int curr = drivePos();

  int target = 1;

  if(abs(last-curr) < 3)
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