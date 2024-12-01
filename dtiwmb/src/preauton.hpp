
#ifndef PREAUTON
#define PREAUTON

#include "vex.h"
#include "robotdevices.h"

using namespace vex;

#include "motor.cpp"

//auton selector


/**  OLD AUTON SELECTOR  */

/* void describe(int number) {
  Controller1.Screen.setCursor(4, 1);


  if (number == 1) {Controller1.Screen.print("Elims OZ 30P");}
  else if (number == 2) {Controller1.Screen.print("Elims DZ 13P");}
//   else if (number == 3) {Controller1.Screen.print("Quals DZ AWP 1WP");}
//   else if (number == 4) {Controller1.Screen.print("Auton Skills 190+");}
}


int autons = 2;
int display = 0;


void incr_display() {display = (display + 1) % autons + 1;}
void decr_display() {display = (display - 1) % autons + 1;}

void AutonSelector() {
  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1, 1);
  Controller1.ButtonX.pressed(incr_display);
  Controller1.ButtonB.pressed(decr_display);
  // Controller1.ButtonA.pressed(_display);
  
  Controller1.Screen.print("Choose Your Program");
  vex::this_thread::sleep_for(100);

  while(display == 0){
    Brain.Screen.print(".");

//    if (Controller1.ButtonX.pressing()) { 
      
//       Brain.Screen.print("R1 Selector Auton Selected : %d",display);
//       Brain.Screen.newLine();
//     }
//     if (Controller1.ButtonB.pressing()) {
//       display = (display - 1) % autons + 1;
//     //   vex::this_thread::sleep_for(100);
//       Brain.Screen.print("L1 Selector Auton Selected : %d",display);
//       Brain.Screen.newLine();
//     }
    // if (Controller1.ButtonA.pressing()) {
    // //   vex::this_thread::sleep_for(1000);
    // //   if (Controller1.ButtonA.pressing()) {
    //     Controller1.rumble(rumbleLong);
    // //    Controller1.Screen.clearScreen();
    //     break;
    // //   }
    // }

    // if (display > autons) {display = 0;}
    // if (display < 0) {display = autons;}


    if (display == 0) {
    //  Controller1.Screen.clearScreen();
    //  Controller1.Screen.setCursor(1, 1);
    //   Controller1.Screen.print("Choose Your Program");
    }        
    if (display != 0) {
    //  Controller1.Screen.clearScreen();
    //   Controller1.Screen.setCursor(1, 1);
    //   Controller1.Screen.print("Selected:");
    //   Controller1.Screen.setCursor(4, 1);
    //  describe(display);
    }
    vex::this_thread::sleep_for(100);
  }
  //Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1, 1);
  Controller1.Screen.print("Good Luck! :)");
//   vex::this_thread::sleep_for(3000);
  //Controller1.Screen.clearScreen();
}

 */

// Auton Functions


void CtrlDbgPrt (const char * str) {
  Controller1.Screen.print(str);
  Controller1.Screen.newLine();
}

void goStraight (double dist, bool front) {
  const double  INCH_TO_DEG = 360*3.0/19;    // Measured on 11/28/2024 - 3 rotations : 22.5 in 
  const uint32_t WAIT_TIME    = 300;          // in milliseconds

  double  currentLeftPos  = LeftMotorGrp.position(degrees);
  double  currentRightPos = RightMotorGrp.position(degrees);
  if (front == true) {
    LeftMotorGrp.spinToPosition (currentLeftPos + dist * INCH_TO_DEG, degrees, false );
    RightMotorGrp.spinToPosition (currentRightPos + dist * INCH_TO_DEG, degrees, false );
  } else {
    LeftMotorGrp.spinToPosition (currentLeftPos - dist * INCH_TO_DEG, degrees, false );
    RightMotorGrp.spinToPosition (currentRightPos - dist * INCH_TO_DEG, degrees, false );
  }
  vex::this_thread::sleep_for(WAIT_TIME);

}

void turn (double angle, bool left) {
  const double  INCH_TO_DEG   = 360*3.0/19;    // Measured on 11/28/2024 - 3 rotations : 22.5 in 
  const double  TURN_RADIUS   = 8;            // Measured on 11/29
  const uint32_t WAIT_TIME    = 300;          // in milliseconds

  double linearDegree = TURN_RADIUS * 2 * M_PI * angle / 360;
  double currentLeftPos, currentRightPos;

  if (left == true) {
    currentLeftPos  = LeftMotorGrp.position(degrees);
    currentRightPos = RightMotorGrp.position(degrees);
   // LeftMotorGrp.spinFor(fwd,360,degrees);
     LeftMotorGrp.spinToPosition (currentLeftPos + linearDegree * INCH_TO_DEG, degrees, false);
     RightMotorGrp.spinToPosition (currentRightPos - linearDegree * INCH_TO_DEG, degrees, false);
  } else {
    currentLeftPos  = LeftMotorGrp.position(degrees);
    currentRightPos = RightMotorGrp.position(degrees);
    LeftMotorGrp.spinToPosition (currentLeftPos - linearDegree * INCH_TO_DEG, degrees, false);
     RightMotorGrp.spinToPosition (currentRightPos + linearDegree * INCH_TO_DEG, degrees, false);
  }

    vex::this_thread::sleep_for(WAIT_TIME);

}


#endif


