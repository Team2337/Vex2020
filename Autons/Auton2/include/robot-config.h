using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LeftBackMotor;
extern motor LeftFrontMotor;
extern motor RightBackMotor;
extern motor RightFrontMotor;
extern controller Controller1;
extern motor LeftElevatorMotor;
extern motor LeftArm;
extern motor RightArm;
extern motor RightElevatorMotor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );