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
#include "buttonapi.hpp"
#include "robotfunctions.hpp"
#include "auton.hpp"
using namespace vex;

#include "motor.cpp"

// A global instance of competition
competition Competition;


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
 
   Controller1.Screen.clearScreen();
   Controller1.Screen.setCursor(1, 1);
   Controller1.Screen.print("Auton sel %d",autonomousSelection);

  switch(autonomousSelection) {
    case 0: {oneMplusoneR(true);}  // set to true when going for positive side
    case 1: {oneMplusoneR(false);}   // set to false when going for negative side
    default: ;
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
/*------------------------------`---------------------------------------------*/
void intakeRings () {
    static bool intakeOn;
    intakeOn = intakeOn && (IntakeS1.direction()==forward); 
    
    if (intakeOn==false) {
        IntakeS1.spin(fwd, 100, pct);
        IntakeS2.spin(fwd, 100, pct);
        intakeOn = true;
        
    } else {
        IntakeS1.stop(brake);
        IntakeS2.stop(brake);  
        intakeOn = false;
       
  
    }
    vex::this_thread::sleep_for(100);
}


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
 
     LeftMotorGrp.spin(fwd,leftSpeed,pct);
    // LeftBack.spin(fwd, leftSpeed, pct);
    // LeftFront.spin(fwd, leftSpeed, pct);
    // LeftMiddle.spin(fwd, leftSpeed, pct);
      RightMotorGrp.spin(fwd, rightSpeed, pct);
    // RightBack.spin(fwd, rightSpeed, pct);
    // RightFront.spin(fwd, rightSpeed, pct);
    // RightMiddle.spin(fwd, rightSpeed, pct);
  
  
  } 
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Run the pre-autonomous function.
  pre_auton();

  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

    // register events for button selection
    Brain.Screen.pressed( userTouchCallbackPressed );
    Brain.Screen.released( userTouchCallbackReleased );

    // make nice background
    Brain.Screen.setFillColor( vex::color(0x404040) );
    Brain.Screen.setPenColor( vex::color(0x404040) );
    Brain.Screen.drawRectangle( 0, 0, 480, 120 );
    Brain.Screen.setFillColor( vex::color(0x808080) );
    Brain.Screen.setPenColor( vex::color(0x808080) );
    Brain.Screen.drawRectangle( 0, 120, 480, 120 );

    // initial display
    displayButtonControls( 0, false );


  // Prevent main from exiting with an infinite loop.
  while (true) {
    printTemps();  // Prints motor temperature on the controller
    wait(100, msec);
  }
}