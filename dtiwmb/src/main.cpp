/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Redwood Robotics                                          */
/*    Created:      11/17/2024, 9:30:01 AM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "robotdevices.h"

using namespace vex;

#include "motor.cpp"



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
/*------------------------------`---------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
   // Read the joystick values
    int forward = Controller1.Axis2.position();  // Left joystick Y-axis
    int turn = Controller1.Axis1.position();     // Left joystick X-axis

    // Calculate the speed for each side
    int leftSpeed = forward + turn;
    int rightSpeed = forward - turn;

    // Set the motor speeds
    LeftBack.spin(fwd, leftSpeed, pct);
    LeftFront.spin(fwd, leftSpeed, pct);
    LeftMiddle.spin(fwd, leftSpeed, pct);
    
    RightBack.spin(fwd, rightSpeed, pct);
    RightFront.spin(fwd, rightSpeed, pct);
    RightMiddle.spin(fwd, rightSpeed, pct);
  
      if (Controller1.ButtonL1.pressing()) {
//        Mogo.pump(true);
        Mogo.set(true);
      }
      else {
//         Mogo.pump(false);
         Mogo.set(false);
      }

  if (Controller1.ButtonR1.pressing()) {
        IntakeS1.spin(fwd, 100, pct);
        IntakeS2.spin(fwd, 100, pct);
  }
  else {
        IntakeS1.stop(coast);
        IntakeS2.stop(coast);       
  }

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