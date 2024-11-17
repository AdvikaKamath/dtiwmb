using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor LeftMiddle;
extern motor LeftFront;
extern motor LeftBack;
extern motor RightBack;
extern motor RightMiddle;
extern motor RightFront;
extern digital_out Mogo;
extern motor IntakeS1;
extern motor IntakeS2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );