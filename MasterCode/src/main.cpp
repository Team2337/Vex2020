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

  //Current Autonomous; Refer to Auton Mappings
  int CurrentAuton = 1; 

  if(CurrentAuton == 1) {
    // Will play Auton 1
  }
  if(CurrentAuton == 2) {
    //Will play Auton 2
  }

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


   while (true) {
    // Chassis 
     //Get the raw sums of the X and Y joystick axes
        double front_left  = (double)(Controller1.Axis3.position(pct) + Controller1.Axis4.position(pct));
        double back_left   = (double)(Controller1.Axis3.position(pct) - Controller1.Axis4.position(pct));
        double front_right = (double)(Controller1.Axis3.position(pct) - Controller1.Axis4.position(pct));
        double back_right  = (double)(Controller1.Axis3.position(pct) + Controller1.Axis4.position(pct));
        
        //Find the largest possible sum of X and Y
        double max_raw_sum = (double)(abs(Controller1.Axis3.position(pct)) + abs(Controller1.Axis4.position(pct)));
        
        //Find the largest joystick value
        double max_XYstick_value = (double)(std::max(abs(Controller1.Axis3.position(pct)),abs(Controller1.Axis4.position(pct))));
        
        //The largest sum will be scaled down to the largest joystick value, and the others will be
        //scaled by the same amount to preserve directionality
        if (max_raw_sum != 0) {
            front_left  = front_left / max_raw_sum * max_XYstick_value;
            back_left   = back_left / max_raw_sum * max_XYstick_value;
            front_right = front_right / max_raw_sum * max_XYstick_value;
            back_right  = back_right / max_raw_sum * max_XYstick_value;
        }
        
        //Now to Consider rotation
        //Naively add the rotational axis
        front_left  = front_left  + Controller1.Axis1.position(pct);
        back_left   = back_left   + Controller1.Axis1.position(pct);
        front_right = front_right - Controller1.Axis1.position(pct);
        back_right  = back_right  - Controller1.Axis1.position(pct);
        
        //What is the largest sum, or is 100 larger?
        max_raw_sum = std::max(fabs(front_left),std::max(fabs(back_left),std::max(fabs(front_right),std::max(fabs(back_right),100.0))));
        
        //Scale everything down by the factor that makes the largest only 100, if it was over
        front_left  = front_left  / max_raw_sum * 100.0;
        back_left   = back_left   / max_raw_sum * 100.0;
        front_right = front_right / max_raw_sum * 100.0;
        back_right  = back_right  / max_raw_sum * 100.0;
        
        //Write the manipulated values out to the motors
         LeftFrontMotor.spin(fwd,front_left, velocityUnits::pct);
          LeftBackMotor.spin(fwd,back_left,  velocityUnits::pct);
        RightFrontMotor.spin(fwd,front_right,velocityUnits::pct);
         RightBackMotor.spin(fwd,back_right, velocityUnits::pct);

    // DEPRECATED 
    /*        
        LeftBackMotor.spin(directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis4.value())/2, velocityUnits::pct); //(Axis3+Axis4)/2;
        LeftFrontMotor.spin(directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis4.value())/2, velocityUnits::pct); //(Axis3+Axis4)/2;
        RightBackMotor.spin(directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis4.value())/2, velocityUnits::pct);//(Axis3-Axis4)/2;      
        RightFrontMotor.spin(directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis4.value())/2, velocityUnits::pct);//(Axis3-Axis4)/2;
   */
    // Arm
         int armSpeedPCT = 50;

         if(Controller1.ButtonUp.pressing()) {
            LeftArm.spin(directionType::fwd, armSpeedPCT, velocityUnits::pct);
            RightArm.spin(directionType::fwd, armSpeedPCT, velocityUnits::pct);

        }
        else if(Controller1.ButtonDown.pressing()) {
            LeftArm.spin(directionType::rev, armSpeedPCT, velocityUnits::pct);
            RightArm.spin(directionType::rev, armSpeedPCT, velocityUnits::pct);
        }
        else {
            LeftArm.stop(brakeType::brake);
            RightArm.stop(brakeType::brake);
        }

    
    } 
  // CURRENTLY NOT BEING USED

  // User control code here, inside the loop

  // Prevents drifting
  /*int limiter = 10;

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

  */

  //Elevator
  if (Controller1.ButtonR1.pressing() == true){
      LeftElevatorMotor.spin(forward, 100, percent);
      RightElevatorMotor.spin(forward, 100, percent);
    }
     else {
      LeftElevatorMotor.spin(forward, 0, percent);
      RightElevatorMotor.spin(forward, 0, percent);
    }
     if (Controller1.ButtonR2.pressing() == true){
      LeftElevatorMotor.spin(reverse, 100, percent);
      RightElevatorMotor.spin(reverse, 100, percent);
    }
     else {
      LeftElevatorMotor.spin(reverse, 0, percent);
      RightElevatorMotor.spin(reverse, 0, percent);
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
