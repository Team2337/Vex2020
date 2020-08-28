/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\mfran                                            */
/*    Created:      Thu Aug 27 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LeftArm              motor         14              
// RightArm             motor         15              
// Controller2          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

competition Competition;

// define your global instances of motors and other devices here

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

void usercontrol(void) {
  // User control code here, inside the loop

  //Constant for speed
  int armVel = 50;

  while (1) {
    if(Controller2.ButtonL1.pressing() && !Controller2.ButtonL2.pressing()){
      LeftArm.setVelocity(armVel, percent);
      RightArm.setVelocity(armVel, percent);
    } else if(Controller2.ButtonL2.pressing() && !Controller2.ButtonL1.pressing()){
      LeftArm.setVelocity(-armVel, percent);
      RightArm.setVelocity(-armVel, percent);
    } else {
      LeftArm.setVelocity(0, percent);
    }
    

    wait(5, msec); // Sleep the task for a short amount of time to prevent wasted resources.
  }
}
//axis 1 and 4: left/right
//axis 2 and 3: up/down

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
