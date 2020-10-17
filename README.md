# Vex2020 Team B
A guide to VEX team 2337B's code. We separated our code into various folders with the main code being used for the robot being in the MasterCode folder.
## Directory Guide
- **Autons** - Holds all our autons. Includes the ones on the robot and the ones in development.
    - Any folders inside of the *Auton* folder are different auton projects.
- **MasterCode** - All official code being used for the robot is stored in here.
- **Subsystems** - Different parts of the code relating to parts on the robot. Some are complete, some are deprecated, some are in development.
    - Any folders inside of the *Subsystems* folder are different projects containing the code.
## Motor Ports and Names
- Chassis
    - LeftBackMotor -> Port 1
    - LeftFrontMotor -> Port 2
    - RightBackMotor -> Port 3
    - RightFrontMotor -> Port 4
- Intake/Elevator
    - ElevatorMotor -> Port 5
    - IntakeMotor -> Port 8
- Arm
    - LeftArm -> Port 6
    - RightArm -> Port 7
## Controls
- Chassis -> Controller 1
    - Axis1 -> 45 degree angle movements
    - Axis3 -> Forwards and backwards movements
    - Axis4 -> Left and right (sideways) movements
- Intake/Elevator -> Controller 2
    - ButtonR1 -> Intakes balls and moves them up in the elevator
    - ButtonR2 -> Moves balls down the elevator and outtakes them if needed
- Arm -> Controller 2
    - ButtonUp -> Moves arm up
    - ButtonDown -> Moves arm down
