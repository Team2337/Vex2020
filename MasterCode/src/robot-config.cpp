#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftBackMotor = motor(PORT10, ratio18_1, false);
motor LeftFrontMotor = motor(PORT11, ratio18_1, false);
motor RightBackMotor = motor(PORT1, ratio18_1, false);
motor RightFrontMotor = motor(PORT9, ratio18_1, false);
motor LeftElevatorMotor = motor(PORT12, ratio18_1, false);
motor LeftArm = motor(PORT14, ratio18_1, false);
motor RightArm = motor(PORT15, ratio18_1, false);
controller Controller1 = controller(primary);
controller Controller2 = controller(partner);
motor RightElevatorMotor = motor(PORT13, ratio18_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}