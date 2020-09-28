/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Michael Francis                                           */
/*    Created:      Mon Sep 28 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftBackMotor        motor         1               
// LeftFrontMotor       motor         2               
// RightBackMotor       motor         3               
// RightFrontMotor      motor         4               
// Controller1          controller                    
// LeftElevatorMotor    motor         5               
// LeftArm              motor         6               
// RightArm             motor         7               
// RightElevatorMotor   motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----


#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
//Autonomous functions

//Run motors
void runMotors(double velocity){
  LeftBackMotor.setVelocity(-velocity, percent);
  LeftFrontMotor.setVelocity(-velocity, percent);
  RightBackMotor.setVelocity(velocity, percent);
  RightFrontMotor.setVelocity(velocity, percent);
}

//Turn motors
void turnMotors(double velocity){
  LeftBackMotor.setVelocity(velocity, percent);
  LeftFrontMotor.setVelocity(velocity, percent);
  RightBackMotor.setVelocity(velocity, percent);
  RightFrontMotor.setVelocity(velocity, percent);
}

//Stop motors
void stopMotors(){
  LeftBackMotor.setVelocity(0, percent);
  LeftFrontMotor.setVelocity(0, percent);
  RightBackMotor.setVelocity(0, percent);
  RightFrontMotor.setVelocity(0, percent);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

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

  //Current Autonomous; Refer to Auton Mappings
  int CurrentAuton = 1; 

  if(CurrentAuton == 1) {
    // Will play Auton 1
  }
  if(CurrentAuton == 2) {
    //Will play Auton 2
    //Written by Michael Francis

    //Go forward at half speed for 0.25 seconds
    runMotors(0.5);
    vex::task::sleep(250);
    stopMotors();
    //Small break for motors
    vex::task::sleep(50);
    //Run intake/elevator motors for half a second
    LeftElevatorMotor.setVelocity(0.75, percent);
    RightElevatorMotor.setVelocity(0.75, percent);
    vex::task::sleep(500);
    LeftElevatorMotor.setVelocity(0, percent);
    RightElevatorMotor.setVelocity(0, percent);
    //Small break for motors
    vex::task::sleep(50);
    //Turn 45 degrees right
    turnMotors(0.75);
    vex::task::sleep(250);
    //Move backwards at half speed for half a second
    runMotors(-0.5);
    vex::task::sleep(500);
    stopMotors();
    //Turn 135 degrees right
    turnMotors(0.75);
    vex::task::sleep(625);
    //Go forwards at full speed for half a second
    runMotors(1);
    vex::task::sleep(500);
    //Turn 90 degrees left
    turnMotors(-0.75);
    vex::task::sleep(500);
    //Go forwards at half speed for 0.25 seconds
    runMotors(0.5);
    vex::task::sleep(250);
    stopMotors();
    //Small break for motors
    vex::task::sleep(50);
    //Reverse intake/elevator for a little over half a second (to ensure ball is out)
    LeftElevatorMotor.setVelocity(-0.75, percent);
    RightElevatorMotor.setVelocity(-0.75, percent);
    vex::task::sleep(625);
    LeftElevatorMotor.setVelocity(0, percent);
    RightElevatorMotor.setVelocity(0, percent);
    //Small break for motors
    vex::task::sleep(50);
    //Turn 90 degrees right
    turnMotors(0.75);
    vex::task::sleep(500);
    //Go forwards at full speed for half a second
    runMotors(1);
    vex::task::sleep(500);
    //Turn 90 degrees left
    turnMotors(-0.75);
    vex::task::sleep(500);
    //Go forwards slowly while running intake
    runMotors(0.1);
    LeftElevatorMotor.setVelocity(0.75, percent);
    RightElevatorMotor.setVelocity(0.75, percent);
    vex::task::sleep(500);
    LeftElevatorMotor.setVelocity(0, percent);
    RightElevatorMotor.setVelocity(0, percent);
    stopMotors();
    //end
  }

}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void usercontrol(void) {
  //this doesn't exist in this subsystem :shrug:
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


// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftBackMotor        motor         1               
// LeftFrontMotor       motor         2               
// RightBackMotor       motor         3               
// RightFrontMotor      motor         4               
// LeftElevatorMotor    motor         5               
// LeftArm              motor         6               
// RightArm             motor         7               
// Controller1          controller                    
// Controller2          controller                    
// RightElevatorMotor   motor         8               
