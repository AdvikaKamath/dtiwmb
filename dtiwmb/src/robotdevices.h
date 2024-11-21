#include "vex.h"
using namespace vex;

brain Brain;

// VEXcode devices
controller Controller1 = controller(primary);
motor LeftBack     = motor(PORT6, ratio6_1, true);
motor LeftFront    = motor(PORT11, ratio6_1, true);
motor LeftMiddle   = motor(PORT12, ratio6_1, true);
motor RightBack    = motor(PORT8, ratio6_1, false);
motor RightMiddle  = motor(PORT7, ratio6_1, false);
motor RightFront   = motor(PORT5, ratio6_1, false);
motor IntakeS1     = motor(PORT2, ratio6_1, false);
motor IntakeS2     = motor(PORT4, ratio6_1, false);
//inertial Inertial  = inertial(PORT14);

pneumatics Mogo    = pneumatics(Brain.ThreeWirePort.A);
//limit lswitch;