using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LeftBackMotor;
extern motor LeftFrontMotor;
extern motor RightBackMotor;
extern motor RightFrontMotor;
extern motor ElevatorMotor;
extern motor UpperLeftArm;
extern motor LowerLeftArm;
extern motor UpperRightArm;
extern motor LowerRightArm;
extern controller Controller1;
extern controller Controller2;
extern motor ShooterMotor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );