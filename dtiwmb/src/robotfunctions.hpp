#ifndef ROBOTFUNCTIONS
#define ROBOTFUNCTIONS
#include "vex.h"
#include "robotdevices.h"




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

/*
 This function prints the motor temperatures on controller screen
*/
void printTemps() {
float LeftMTemp = LeftMotorGrp.temperature();
float RightMTemp = RightMotorGrp.temperature();
float IntakeTemp = IntakeS2.temperature();

    Controller1.Screen.setCursor(2,1);
    if(LeftMTemp <= 40){
      Controller1.Screen.print(":D LM: %1.0f", LeftMTemp);
    }else if(LeftMTemp <= 55){
      Controller1.Screen.print(":) LM: %1.0f", LeftMTemp);
    }else{
      Controller1.Screen.print(":( LM: %1.0f", LeftMTemp);
    }


     if(RightMTemp<= 40){
      Controller1.Screen.print(":D RM: %1.0f", RightMTemp);
    }else if(RightMTemp <= 55){
      Controller1.Screen.print(":) RM: %1.0f", RightMTemp);
    }else{
      Controller1.Screen.print(":( RM: %1.0f", RightMTemp);
    }
    Controller1.Screen.newLine();
 
 if(IntakeTemp<= 40){
      Controller1.Screen.print(":D Intake: %1.0f", IntakeTemp);
    }else if(IntakeTemp <= 55){
      Controller1.Screen.print(":) Intake: %1.0f", IntakeTemp);
    }else{
      Controller1.Screen.print(":( Intake: %1.0f", IntakeTemp);
    }

}

#endif
