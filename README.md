# bbot

bbot - or balancing robot - is a two-wheeled, 3D printed robot which is capable of balancing just like a seguway. The general concept behind the algorithm is: if you are falling forward, move forward. If you are falling backward, move backward. The real challenge comes in doing this quickly and accurately enough.

![incomplete picture of the robot](https://cdn.hackaday.io/images/4916851618244520317.jpg)

## Components

The main components for bbot are as follows:

 - ADXL335 (Accelerometer)
 - SparkFun OpenLog (Telemetry to SDCard)
 - 595N (Shift Register)
 - 2x L239D (H-Bridge)
 - 2x Stepper Motors

## Project Files

The project is split out into different folders. Each folder is responsible for a different aspect of the robot design.

**bbot-firmware**
_The arduino source code_

**bbot-jupyter**
_A jupyter notebook used to analyze sensor readings_

**bbot-models**
_SolidWorks models, as well as finalized STL files_

**bbot-pcb**
_KiCAD circuit board and gerber files_



## Jupyter Notebook
TBD


## 3D Models
TBD


## Assembly Instructions
TBD
