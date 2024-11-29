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


void intakeRings () {
    static bool intakeOn;
    intakeOn = intakeOn && (IntakeS1.direction()==forward); 
    
    if (intakeOn==false) {
        IntakeS1.spin(fwd, 100, pct);
        IntakeS2.spin(fwd, 100, pct);
        intakeOn = true;
        // For debugging
        Brain.Screen.print("Intake Start: %d %d",intakeOn,(IntakeS1.direction()==forward));
        Brain.Screen.newLine();
    } else {
        IntakeS1.stop(brake);
        IntakeS2.stop(brake);  
        intakeOn = false;
        // For debugging
        Brain.Screen.print("Intake Stop: %d %d",intakeOn,(IntakeS1.direction()==forward));
        Brain.Screen.newLine();
    }
    vex::this_thread::sleep_for(100);
}

void expelRings() {
    static bool expelOn;
    expelOn = expelOn && (IntakeS1.direction()==reverse);
    if (expelOn==false) {
        IntakeS1.spin(reverse, 100, pct);
        IntakeS2.spin(reverse, 100, pct);
        // For debugging
        Brain.Screen.print("expel Start: %d %d",expelOn,(IntakeS1.direction()==reverse));
        Brain.Screen.newLine();
        expelOn = true;
    } else {
        IntakeS1.stop(brake);
        IntakeS2.stop(brake);       
        // For debugging
        Brain.Screen.print("expel Stop: %d %d",expelOn,(IntakeS1.direction()==reverse));
        Brain.Screen.newLine();
        expelOn = false;
    }
    vex::this_thread::sleep_for(100);
}


void mobileGoalClamp() {
    static bool clampOn;

    if (clampOn == false) {
      Mogo.set(true);
      // For debugging
      Controller1.Screen.print("clamp On: %d",clampOn);
      Controller1.Screen.newLine();
      clampOn = true;
    } else {
      Mogo.set(false);
      // For debugging
      Controller1.Screen.print("clamp Off: %d",clampOn);
      Controller1.Screen.newLine();
      clampOn = false;
    }
    vex::this_thread::sleep_for(100);
}

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
  // vexcodeInit();

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
  const double  INCH_TO_DEG = 360*3/22.5;    // Measured on 11/28/2024 - 3 rotations : 22.5 in 

  double reverse_inches = -22.5;

  double spin = 13;

  double fwdLength = 5;

  LeftBack.setVelocity(35, pct);
  LeftMiddle.setVelocity(35, pct);
  LeftFront.setVelocity(35, pct);
  RightBack.setVelocity(35, pct);
  RightMiddle.setVelocity(35, pct);
  RightFront.setVelocity(35, pct);
  // All motors run at the same speed
  
   LeftBack.spinToPosition (reverse_inches * INCH_TO_DEG , degrees, false );
   LeftMiddle.spinToPosition (reverse_inches * INCH_TO_DEG, degrees, false );
   LeftFront.spinToPosition (reverse_inches * INCH_TO_DEG, degrees, false );
   RightBack.spinToPosition (reverse_inches * INCH_TO_DEG, degrees, false );
   RightMiddle.spinToPosition (reverse_inches * INCH_TO_DEG, degrees, false );
   RightFront.spinToPosition (reverse_inches * INCH_TO_DEG, degrees, false );

   // Make it go forward
  vex::this_thread::sleep_for(1000);
  // mOGO CLAMP
  Mogo.set(true);

  // Run intake
  IntakeS1.spin(fwd,100, pct);
  IntakeS2.spin(fwd,100, pct);
  vex::this_thread::sleep_for(100);
  // Turn
  LeftBack.spinToPosition (spin * INCH_TO_DEG , degrees, false );
  LeftMiddle.spinToPosition (spin * INCH_TO_DEG, degrees, false );
  LeftFront.spinToPosition (spin * INCH_TO_DEG, degrees, true );

  vex::this_thread::sleep_for(100);

   // Reset Position
   LeftBack.resetPosition ();
   LeftMiddle.resetPosition ();
   LeftFront.resetPosition ();
   RightBack.resetPosition ();
   RightMiddle.resetPosition ();
   RightFront.resetPosition ();

  vex::this_thread::sleep_for(100);
  LeftBack.spinToPosition (fwdLength * INCH_TO_DEG , degrees, false );
  LeftMiddle.spinToPosition (fwdLength * INCH_TO_DEG, degrees, false );
  LeftFront.spinToPosition (fwdLength * INCH_TO_DEG, degrees, false );
  RightBack.spinToPosition (fwdLength * INCH_TO_DEG, degrees, false );
  RightMiddle.spinToPosition (fwdLength * INCH_TO_DEG, degrees, false );
  RightFront.spinToPosition (fwdLength * INCH_TO_DEG, degrees, false );


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
 

  // Map Button R1 & R2 to Intake & Expel rings
  // Works as a toggle
  Controller1.ButtonR1.pressed(intakeRings);
  Controller1.ButtonR2.pressed(expelRings);

  // Map Button L1 to clamp and unclamp mobile goal
  // Works as a toggle
  Controller1.ButtonL1.pressed(mobileGoalClamp);

  // User control code here, inside the loop
  while (1) {
   // Read the joystick values
    int forward = Controller1.Axis2.position();  // Left joystick Y-axis
    int turn = Controller1.Axis1.position();     // Left joystick X-axis

    // Calculate the speed for each side
    // Scale down to reduce speed
    int leftSpeed  = forward + turn;
    int rightSpeed = forward - turn;

    // Set the motor speeds
    LeftBack.spin(fwd, leftSpeed, pct);
    LeftFront.spin(fwd, leftSpeed, pct);
    LeftMiddle.spin(fwd, leftSpeed, pct);
    
    RightBack.spin(fwd, rightSpeed, pct);
    RightFront.spin(fwd, rightSpeed, pct);
    RightMiddle.spin(fwd, rightSpeed, pct);
  
  
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