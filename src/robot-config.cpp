#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LeftMiddle = motor(PORT1, ratio6_1, true);
motor LeftFront = motor(PORT11, ratio6_1, true);
motor LeftBack = motor(PORT20, ratio6_1, true);
motor RightBack = motor(PORT6, ratio6_1, false);
motor RightMiddle = motor(PORT5, ratio6_1, false);
motor RightFront = motor(PORT7, ratio6_1, false);
digital_out Mogo = digital_out(Brain.ThreeWirePort.A);
motor IntakeS1 = motor(PORT2, ratio6_1, false);
motor IntakeS2 = motor(PORT3, ratio18_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}