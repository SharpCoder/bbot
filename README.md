# bbot

bbot - or balancing robot - is a two-wheeled, 3D printed robot which is capable of balancing just like a seguway. The general concept behind the algorithm is: if you are falling forward, move forward. If you are falling backward, move backward. The real challenge comes in doing this quickly and accurately enough.

![picture of the robot with most parts assembled](https://cdn.hackaday.io/images/4916851618244520317.jpg)

## Components

The main components for bbot are as follows:

 - Adafruit Metro Mini (Arduino)
 - ADXL335 (Accelerometer)
 - SparkFun OpenLog (Telemetry to SDCard)
 - 595N (Shift Register)
 - 2x L293D (H-Bridge)
 - 2x Stepper Motors

## Project Files

The project is split out into different folders. Each folder is responsible for a different aspect of the robot design.

 - **bbot-firmware**: _The arduino source code_
 - **bbot-jupyter**: _A jupyter notebook used to analyze sensor readings_
 - **bbot-models**: _SolidWorks models, as well as finalized STL files_
 - **bbot-pcb**: _KiCAD circuit board and gerber files_

## bbot-firmware

### Overview

The algorithm which is currently implemented takes the approach of measuring the accelerometer sensor readings every 30ms and then comparing the observed values with a known threshold. If the readings indicate it is tilting forward, the robot will activate the step-forward routine for each motor. If the readings indicate it is tilting backward, the robot will activate the step-backward routine for each motor.

In order to actually move the motors, two primary files are responsible. The first being `motors.h` and `motors.cpp`. This code is designed to track which phase of each motor is active at any point in time. Knowing what phase is active allows us to determine what move to take in order to transition to a forward or backward step state. The H-Bridge is actually wired up to a shift register and to activate it, we must keep track of which pins are active in the shift register. The code which handles this is in the files `shift.h` and `shift.cpp`. Managing the shift register is relatively straightforward and simply requires sending an int array containing the state of each pin.

Collecting telemetry is an important part of this project, so that the thresholds can be tweaked in order to improve the algorithm. The `logger.h` and `logger.cpp` files are responsible for this. By leveraging a Sparkfun OpenLog, we are able to stream telemetry data to an SDCard. Each time the sensor is observed, its readings are written to the SDCard.

### Building

You can build the code through the arduino IDE. The microcontroller I used is the Adafruit Metro Mini, which is compatible with most Arduino board targets (for example: Arduino Pro Mini).

## Jupyter Notebook




## 3D Models
TBD


## Assembly Instructions
TBD


## License

All source code and models are provided under the MIT license.