#include "pid.h"

void pid::linedrive(double distance, double dir, float velocity, double porportion,
               double slowdown) {
  // higher porportion causes the pid "reacting" turning amount to be higher
  // lower porportion causes the pid "reacting" turning amount to be lower
  // velocity changes base speed
  // just set dir to 0
  // slowdown is the decellaration multiplier, higher it is the more it slows
  // down.
  Inertial.resetHeading();
  Inertial.resetRotation();
  if (velocity > 0) {
    // driving forward
    while (((LeftDriveSmart.rotation(rotationUnits::deg) +
             RightDriveSmart.rotation(rotationUnits::deg)) /
            2) *
               12.57 / 3100 <
           distance) {
      // getting closer
      if (((LeftDriveSmart.rotation(rotationUnits::deg) +
            RightDriveSmart.rotation(rotationUnits::deg)) /
           2) *
              12.57 / 3100 >
          (distance - 6)) {

        // actual pid
        double out =
            distance - (((LeftDriveSmart.rotation(rotationUnits::deg) +
                          RightDriveSmart.rotation(rotationUnits::deg)) /
                         2) *
                        12.57 / 3100);
        LeftDriveSmart.spin(reverse,
                            (velocity - out * slowdown) -
                                (dir - (Inertial.yaw() * porportion)),
                            vex::velocityUnits::pct);
        RightDriveSmart.spin(reverse,
                             (velocity - out * slowdown) +
                                 (dir - (Inertial.yaw() * porportion)),
                             vex::velocityUnits::pct);
      } else {
        // normal
        // actual pid
        LeftDriveSmart.spin(reverse,
                            (velocity - (dir - (Inertial.yaw()) * porportion)),
                            vex::velocityUnits::pct);
        RightDriveSmart.spin(reverse,
                             (velocity + (dir - (Inertial.yaw()) * porportion)),
                             vex::velocityUnits::pct);
      }
    }
  } else {
    // driving backwards
    while (((LeftDriveSmart.rotation(rotationUnits::deg) +
             RightDriveSmart.rotation(rotationUnits::deg)) /
            2) *
               12.57 / 3100 >
           distance) {
      // getting closer
      if (((LeftDriveSmart.rotation(rotationUnits::deg) +
            RightDriveSmart.rotation(rotationUnits::deg)) /
           2) *
              12.57 / 3100 <
          (distance + 6)) {
        // actual pid
        double out =
            distance - (((LeftDriveSmart.rotation(rotationUnits::deg) +
                          RightDriveSmart.rotation(rotationUnits::deg)) /
                         2) *
                        12.57 / 3100);
        LeftDriveSmart.spin(reverse,
                            (velocity - out * slowdown) +
                                (dir - (Inertial.yaw() * porportion)),
                            vex::velocityUnits::pct);
        RightDriveSmart.spin(reverse,
                             (velocity - out * slowdown) -
                                 (dir - (Inertial.yaw() * porportion)),
                             vex::velocityUnits::pct);
      } else {
        // normal
        // actual pid
        LeftDriveSmart.spin(reverse,
                            (velocity + (dir - (Inertial.yaw()) * porportion)),
                            vex::velocityUnits::pct);
        RightDriveSmart.spin(reverse,
                             (velocity - (dir - (Inertial.yaw()) * porportion)),
                             vex::velocityUnits::pct);
      }
    }
  }
  LeftDriveSmart.stop(brakeType::brake);
  RightDriveSmart.stop(brakeType::brake);
}

void pid::drive(double distance, double dir, float velocity, double porportion,
                double slowdown) {
  linedrive(distance, dir, velocity, porportion, slowdown);
}