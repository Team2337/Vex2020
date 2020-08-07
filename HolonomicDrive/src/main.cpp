/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\mfran                                            */
/*    Created:      Thu Aug 06 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// frontLeft            motor         1               
// frontRight           motor         2               
// backLeft             motor         3               
// backRight            motor         4               
// Controller1          controller                    
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

  // Prevents drifting
  int limiter = 10;

  while (1) {
    if(abs(Controller1.Axis1.position(percent)) < limiter){
      if(abs(Controller1.Axis3.position(percent)) > limiter && abs(Controller1.Axis4.position(percent)) < limiter + 1){
        //Move forwards/backwards
        frontLeft.setVelocity(Controller1.Axis3.position(percent), percent);
        frontRight.setVelocity(Controller1.Axis3.position(percent), percent);
        backLeft.setVelocity(-Controller1.Axis3.position(percent), percent);
        backRight.setVelocity(-Controller1.Axis3.position(percent), percent);
      }
      if(abs(Controller1.Axis3.position(percent)) < limiter + 1 && abs(Controller1.Axis4.position(percent)) > limiter){
        //Move left/right
        frontLeft.setVelocity(Controller1.Axis3.position(percent), percent);
        frontRight.setVelocity(-Controller1.Axis3.position(percent), percent);
        backLeft.setVelocity(Controller1.Axis3.position(percent), percent);
        backRight.setVelocity(-Controller1.Axis3.position(percent), percent);
      }
      if((Controller1.Axis3.position(percent) > limiter && Controller1.Axis4.position(percent) > limiter) || (Controller1.Axis3.position(percent) < -limiter && Controller1.Axis4.position(percent) < -limiter)){
        //Move diagonally (up and right or down and left)
        frontLeft.setVelocity(Controller1.Axis3.position(percent), percent);
        backLeft.setVelocity(Controller1.Axis3.position(percent), percent);
      }
      if((Controller1.Axis3.position(percent) > limiter && Controller1.Axis4.position(percent) < -limiter) || (Controller1.Axis3.position(percent) < -limiter && Controller1.Axis4.position(percent) > limiter)){
        //Move diagonally (up and left or down and right)
        frontLeft.setVelocity(Controller1.Axis3.position(percent), percent);
        backLeft.setVelocity(Controller1.Axis3.position(percent), percent);
      }
    } else {
      frontLeft.setVelocity(Controller1.Axis1.position(percent), percent);
      frontRight.setVelocity(Controller1.Axis1.position(percent), percent);
      backLeft.setVelocity(Controller1.Axis1.position(percent), percent);
      backRight.setVelocity(Controller1.Axis1.position(percent), percent);
    }
    

    wait(limiter, msec); // Sleep the task for a short amount of time to prevent wasted resources.
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
