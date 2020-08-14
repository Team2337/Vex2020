/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Zayd A. , Michael F. , Nicholas S. , Owen P.              */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Team 2337B Code                                           */
/*    Last Updated:  8/6/2020                                                 */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftBackMotor        motor         1               
// LeftFrontMotor       motor         2               
// RightBackMotor       motor         3               
// RightFrontMotor      motor         4               
// ElevatorMotor        motor         5               
// UpperLeftArm         motor         6               
// LowerLeftArm         motor         7               
// UpperRightArm        motor         8               
// LowerRightArm        motor         9               
// Controller1          controller                    
// Controller2          controller                    
// ShooterMotor         motor         10              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop

  // Prevents drifting
  int limiter = 10;

  while (1) {
    if(abs(Controller1.Axis1.position(percent)) < limiter){
      if(abs(Controller1.Axis3.position(percent)) > limiter && abs(Controller1.Axis4.position(percent)) < limiter + 1){
        //Move forwards/backwards
        LeftFrontMotor.setVelocity(Controller1.Axis3.position(percent), percent);
        RightFrontMotor.setVelocity(Controller1.Axis3.position(percent), percent);
        LeftBackMotor.setVelocity(-Controller1.Axis3.position(percent), percent);
        RightBackMotor.setVelocity(-Controller1.Axis3.position(percent), percent);
      }
      if(abs(Controller1.Axis3.position(percent)) < limiter + 1 && abs(Controller1.Axis4.position(percent)) > limiter){
        //Move left/right
        LeftFrontMotor.setVelocity(Controller1.Axis3.position(percent), percent);
        RightFrontMotor.setVelocity(-Controller1.Axis3.position(percent), percent);
        LeftBackMotor.setVelocity(Controller1.Axis3.position(percent), percent);
        RightBackMotor.setVelocity(-Controller1.Axis3.position(percent), percent);
      }
      if((Controller1.Axis3.position(percent) > limiter && Controller1.Axis4.position(percent) > limiter) || (Controller1.Axis3.position(percent) < -limiter && Controller1.Axis4.position(percent) < -limiter)){
        //Move diagonally (up and right or down and left)
        LeftFrontMotor.setVelocity(Controller1.Axis3.position(percent), percent);
        LeftBackMotor.setVelocity(Controller1.Axis3.position(percent), percent);
      }
      if((Controller1.Axis3.position(percent) > limiter && Controller1.Axis4.position(percent) < -limiter) || (Controller1.Axis3.position(percent) < -limiter && Controller1.Axis4.position(percent) > limiter)){
        //Move diagonally (up and left or down and right)
        LeftFrontMotor.setVelocity(Controller1.Axis3.position(percent), percent);
        LeftBackMotor.setVelocity(Controller1.Axis3.position(percent), percent);
      }
    } else {
      LeftFrontMotor.setVelocity(Controller1.Axis1.position(percent), percent);
      RightFrontMotor.setVelocity(Controller1.Axis1.position(percent), percent);
      LeftBackMotor.setVelocity(Controller1.Axis1.position(percent), percent);
      RightBackMotor.setVelocity(Controller1.Axis1.position(percent), percent);
    }
    

    wait(limiter, msec); // Sleep the task for a short amount of time to prevent wasted resources.
  }

  if (Controller1.ButtonA.pressing() == true){
      ShooterMotor.setVelocity(100, percent);
    }
  if (Controller1.ButtonA.pressing() == false){
      ShooterMotor.setVelocity(0, percent);
    }

    if (Controller1.ButtonL1.pressing()) {
        UpperLeftArm.spin(forward);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonL2.pressing()) {
        UpperLeftArm.spin(reverse);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (!Controller1LeftShoulderControlMotorsStopped) {
        UpperLeftArm.stop();
        Controller1LeftShoulderControlMotorsStopped = true;
      }
      if (Controller1.ButtonL1.pressing()) {
        UpperRightArm.spin(forward);
        Controller1RightShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonL2.pressing()) {
        UpperRightArm.spin(reverse);
        Controller1RightShoulderControlMotorsStopped = false;
      } else if (!Controller1RightShoulderControlMotorsStopped) {
        UpperRightArm.stop();
        Controller1RightShoulderControlMotorsStopped = true;
      }
         //lower motors
          if (Controller1.ButtonL1.pressing()) {
        LowerLeftArm.spin(forward);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonL2.pressing()) {
        LowerLeftArm.spin(reverse);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (!Controller1LeftShoulderControlMotorsStopped) {
        LowerLeftArm.stop();
        Controller1LeftShoulderControlMotorsStopped = true;
      }
      if (Controller1.ButtonL1.pressing()) {
        LowerRightArm.spin(forward);
        Controller1RightShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonL2.pressing()) {
        LowerRightArm.spin(reverse);
        Controller1RightShoulderControlMotorsStopped = false;
      } else if (!Controller1RightShoulderControlMotorsStopped) {
        LowerRightArm.stop();
        Controller1RightShoulderControlMotorsStopped = true;
    }

}

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
