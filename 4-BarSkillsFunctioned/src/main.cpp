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

#include "pid.h"
#include "route1.h"
#include "route2.h"
#include "vex.h"
#include "logging.h"

using namespace vex;         

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Route2 route2;
  route2.run();
}
