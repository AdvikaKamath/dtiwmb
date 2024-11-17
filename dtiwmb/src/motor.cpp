using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor LeftBack;
extern motor LeftFront;
extern motor LeftMiddle;
extern motor RightBack;
extern motor RightMiddle;
extern motor RightFront;
extern motor IntakeS1;
extern motor IntakeS2;
// extern motor catapult;
extern motor intake;
//extern motor kick;
extern inertial Inertial;

extern pneumatics Mogo;
// extern limit lswitch;
extern inertial Inertial;

/**
* Used to initialize code/tasks/devices added using tools in VEXcode Pro.
*
* This should be called at the start of your int main function.
*/
void  vexcodeInit( void );
#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LeftBack = motor(PORT1, ratio6_1, true);
motor LeftMiddle = motor(PORT2, ratio6_1, true);
motor LeftFront = motor(PORT3, ratio6_1, true);
motor RightBack = motor(PORT4, ratio6_1, false);
motor RightMiddle = motor(PORT5, ratio6_1, false);
motor RightFront = motor(PORT7, ratio6_1, false);
motor IntakeS1 = motor(PORT8, ratio6_1, false);
motor IntakeS2 = motor(PORT9, ratio6_1, false);

// motor catapult = motor(PORT8, ratio36_1, false);
motor intake = motor(PORT8, ratio18_1, true);
//motor kick = motor(PORT8, ratio18_1, false);

pneumatics Mogo = pneumatics(Brain.ThreeWirePort.A);
// limit lswitch = limit(Brain.ThreeWirePort.F);

inertial Inertial = inertial(PORT14);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
* Used to initialize code/tasks/devices added using tools in VEXcode Pro.
*
* This should be called at the start of your int main function.
*/
void vexcodeInit( void ) {

}
