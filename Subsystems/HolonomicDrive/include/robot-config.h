using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LeftFrontMotor;
extern motor RightFrontMotor;
extern motor LeftBackMotor;
extern motor RightBackMotor;
extern motor ElevatorMotor;
extern motor UpperLeftArm;
extern motor LowerLeftArm;
extern motor UpperRightArm;
extern motor LowerRightArm;
extern motor ShooterMotor;
extern controller Controller1;
extern controller Controller2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );