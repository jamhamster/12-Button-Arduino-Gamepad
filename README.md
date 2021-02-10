# 12-Button-Arduino-Gamepad
Code to create a 12 button Joypad using the Arduino Joystick library https://github.com/MHeironimus/ArduinoJoystickLibrary 
12 button Arduino USB GamePad code:

This code will enable you to configure and use an Arduino Leonardo or Arduino Micro as a 2-Axis 12 button Joypad with relative ease. 
Features:
Optimised main loop. Higher on memory but faster to process. 
Allows a pin-to -button assignment on a case-by-case basis 
Added logic to the D-Pad to handle 4 button D-Pads, if both left and right are pressed, or if up and down are pressed  this will hold the pad position at middle instead of ‘floating’ 

Pre-Requisites:
Ensure you have consulted the Github page to configure the hardware and have installed the excellent Joystick libraries and examples here: https://github.com/MHeironimus/ArduinoJoystickLibrary

Configuring the options:
Button Count
To configure the amount of buttons, change the following line to however many buttons you need:
int ButtonCount=(12);

Pin assignment
To assign the pins, these are laid out on a logical format with the Joystick button number and the associated Pin on the Arduino. Joystick.setButton provides the button number and digitalRead denotes the pin on the Arduino. 
The example below will set pin 6 on the Arduino to button 1 on the joypad:
    Joystick.setButton(0,(!digitalRead(6)));

Directional buttons:
This section configures the pins needed to provide directional controls. Change these as needed. 
int Right=(3);
int Left=(5);
int Up=(2);
int Down=(4);

Notes:
It may also be possible to also use pins 0 and 1 as additional buttons. 

