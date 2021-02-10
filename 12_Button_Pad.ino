//  12 button Gamepad example
//  Stuart Brand (JamHamster)https://github.com/jamhamster
//  09/02/21
//  For Arduino Leonardo and Arduino Micro only.
//  Based with thanks on the Gamepad Example code by Matthew Heironimus (https://github.com/MHeironimus)
//  Uses the excellent Joystick library here: https://github.com/MHeironimus/ArduinoJoystickLibrary

//Set up the conditions and environment for the Arduino Joystick Library. Sets an 11 button GamePad 
int ButtonCount=(12);

#include <Joystick.h>
  
  
  Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,ButtonCount,0,1,1,0,0,0,0,0,0,0,0,0);
  void setup() 
  {Joystick.begin();

//Sweeps through Arduino pins and sets all to Input Pullup
  for (int PSweep=0; PSweep<22; PSweep++){pinMode(PSweep, INPUT_PULLUP);}

//Sweeps through Gamepad buttons and sets all to 0
  for (int BSweep=0; BSweep<22; BSweep++){Joystick.setButton(BSweep, 0);}

//Configures Gamepad Ranges
  Joystick.setXAxisRange(-1, 1);
  Joystick.setYAxisRange(-1, 1);}

//Start of main loop
  void loop() {

//Set Pins for D-Pads

int Right=(3);
int Left=(5);
int Up=(2);
int Down=(4);

//Sets X-Axis if only left or only right are pressed, not both.
        if ((!digitalRead(Right) == HIGH)&&(digitalRead(Left) == HIGH)){Joystick.setXAxis(1);}
        if ((!digitalRead(Left) == HIGH)&&(digitalRead(Right) == HIGH)){Joystick.setXAxis(-1);}

//Returns X-Axis to middle if neither Right and Left are pressed or if both are pressed
        if ((digitalRead(Right) == HIGH)&&(digitalRead(Left) == HIGH)){Joystick.setXAxis(0);}
        if ((!digitalRead(Right) == HIGH)&&(!digitalRead(Left) == HIGH)){Joystick.setXAxis(0);}
    
//Sets Y-Axis if only up or only down are pressed, not both.
        if ((!digitalRead(Down) == HIGH)&&(digitalRead(Up) == HIGH)){Joystick.setYAxis(1);}
        if ((!digitalRead(Up) == HIGH)&&(digitalRead(Down) == HIGH)){Joystick.setYAxis(-1);}
    
//Returns Y-Axis to middle if neither Up and Down are pressed or if both are pressed    
        if ((digitalRead(Down) == HIGH)&&(digitalRead(Up) == HIGH)){Joystick.setYAxis(0);}
        if ((!digitalRead(Down) == HIGH)&&(!digitalRead(Up) == HIGH)){Joystick.setYAxis(0);}
        
//Iterates through Pins and translates straight to button presses (Joystick ButtonNumber, Arduino Pin)
//Change this to alter/add/remove button assignments. 
    Joystick.setButton(0,(!digitalRead(6)));
    Joystick.setButton(1,(!digitalRead(7)));
    Joystick.setButton(2,(!digitalRead(8)));
    Joystick.setButton(3,(!digitalRead(9)));
    Joystick.setButton(4,(!digitalRead(10)));
    Joystick.setButton(5,(!digitalRead(14)));
    Joystick.setButton(6,(!digitalRead(15)));
    Joystick.setButton(7,(!digitalRead(16)));
    Joystick.setButton(8,(!digitalRead(18)));
    Joystick.setButton(9,(!digitalRead(19)));
    Joystick.setButton(10,(!digitalRead(20)));
    Joystick.setButton(11,(!digitalRead(21)));
  delay(10);
  }
