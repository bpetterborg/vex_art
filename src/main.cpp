/*
 *  Robot that draws out pictures with a marker
 *
 */

#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// PenServo             servo         A               
// Drivetrain           drivetrain    9, 14, 10, 15   
// ---- END VEXCODE CONFIGURED DEVICES ----
using namespace vex;

// pen servo positions
int penServoUpPosition = 10;
int penServoDownPosition = 270;

// raise/lower the pen
class Pen
{
  public:
    
    void raise()
    {
      Brain.Screen.print("Raise PenServo...");
      PenServo.setPosition(penServoUpPosition, degrees);
      Brain.Screen.print("Done");
      Brain.Screen.newLine();
    }

    void lower()
    {
      Brain.Screen.print("Lower PenServo...");
      PenServo.setPosition(penServoDownPosition, degrees);
      Brain.Screen.print("Done");
      Brain.Screen.newLine();
    }

};


class Pictures
{
  public:
    
    void square()
    {
      Brain.Screen.print("Draw square..."); // debug logging
      for (int i = 0; i > 4; i++)
      {
        Drivetrain.driveFor(1000, mm);
        Drivetrain.turnFor(90, degrees);
      }
      Brain.Screen.newLine();
    }
    
};


int main() 
{
  vexcodeInit();
  Pictures pictures;
  Pen pen;

  wait(3600, msec);
  pen.raise();


  pen.lower();
  pictures.square();
  pen.raise();


}
