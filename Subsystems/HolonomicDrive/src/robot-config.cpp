#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftFrontMotor = motor(PORT1, ratio18_1, false);
motor RightFrontMotor = motor(PORT2, ratio18_1, false);
motor LeftBackMotor = motor(PORT3, ratio18_1, false);
motor RightBackMotor = motor(PORT4, ratio18_1, false);
motor ElevatorMotor = motor(PORT5, ratio18_1, false);
motor UpperLeftArm = motor(PORT6, ratio18_1, false);
motor LowerLeftArm = motor(PORT7, ratio18_1, false);
motor UpperRightArm = motor(PORT8, ratio18_1, false);
motor LowerRightArm = motor(PORT9, ratio18_1, false);
motor ShooterMotor = motor(PORT10, ratio18_1, false);
controller Controller1 = controller(primary);
controller Controller2 = controller(partner);

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