#ifndef AUTONHPP
#define AUTONHPP

#include "vex.h"
#include "robotdevices.h"
#include "preauton.hpp"
using namespace vex;
#include "motor.cpp"


void oneMplusoneR (bool positive) {
  double distToMogo = 18.5;
  double fwdLength = 15;
  double ladder = 25;
  bool debug = false;   // Set to true to see mssages on controller

  // All motors run at the same speed
  LeftMotorGrp.setVelocity(40, pct);
  RightMotorGrp.setVelocity(40, pct);

  // Make it go forward
  if (debug) CtrlDbgPrt("Go Forward");
  goStraight(distToMogo, false); // Robot starts in reverse position

  // mOGO CLAMP
  
  if (debug) CtrlDbgPrt("MOGO");
  vex::this_thread::sleep_for(800); // Need this not to clamp too soon
  Mogo.set(true);
 

  //Run intake
  if (debug) CtrlDbgPrt("Intake spin");
  IntakeS1.spin(fwd,100, pct);
  IntakeS2.spin(fwd,100, pct);
  vex::this_thread::sleep_for(100);

  // Turn
  if (debug) CtrlDbgPrt("Turn to rings");
  turn(100.0, positive==false);

  vex::this_thread::sleep_for(1000);
  if (debug) CtrlDbgPrt("Go to rings");
  goStraight (fwdLength,true);
   


  //turn
  vex::this_thread::sleep_for(2000);
  // Stop intake
  IntakeS1.stop();
  IntakeS2.stop();
  if (debug) CtrlDbgPrt("Intake Stop");

  turn(-135.0, positive==true);
  if (debug) CtrlDbgPrt("Turn to ladder");

  vex::this_thread::sleep_for(1000);

  goStraight(ladder, true);
  if (debug) CtrlDbgPrt("Forward to ladder");
}


// void positiveside (void) {
//   double distToMogo = 18.5;
//   double fwdLength = 15;
//   double ladder = 25;

//   // All motors run at the same speed
//   LeftMotorGrp.setVelocity(40, pct);
//   RightMotorGrp.setVelocity(40, pct);

//   // Make it go forward
//   CtrlDbgPrt("Go Forward");
//   goStraight(distToMogo, false); // Robot starts in reverse position

//   // mOGO CLAMP
  
//   CtrlDbgPrt("MOGO");
//   vex::this_thread::sleep_for(800); // Need this not to clamp too soon
//   Mogo.set(true);
 

//   //Run intake
//   CtrlDbgPrt("Intake spin");
//   IntakeS1.spin(fwd,100, pct);
//   IntakeS2.spin(fwd,100, pct);
//   vex::this_thread::sleep_for(100);

//   // Turn
//   CtrlDbgPrt("Turn to rings");
//   turn(-100.0, true);

//   vex::this_thread::sleep_for(1000);
//     CtrlDbgPrt("Go to rings");
//   goStraight (fwdLength,true);
   


//   //turn
//   vex::this_thread::sleep_for(2000);
//   // Stop intake
//   IntakeS1.stop();
//   IntakeS2.stop();
//   CtrlDbgPrt("Intake Stop");

//   turn(135.0, false);
//   CtrlDbgPrt("Turn to ladder");

//   vex::this_thread::sleep_for(1000);

//   goStraight(ladder, true);
//   CtrlDbgPrt("Forward to ladder");
// }


#endif
