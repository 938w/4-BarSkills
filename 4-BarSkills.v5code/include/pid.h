#include "vex.h"

using namespace vex;

class pid {
  private:
    void linedrive (double distance, double dir, float velocity, double porportion, double slowdown);

  public:
    void drive (double distance, double dir, float velocity, double porportion, double slowdown);
};