#include "vex.h"

using namespace vex;

class pid {
private:
  void linedrive(double distance, double dir, double velocity,
                 double porportion);

public:
  void drive(double distance, double dir, double velocity, double porportion);
};