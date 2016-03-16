Shooting Target
===================

**A program that can automatically calculate your shooting score.**  

Preparations
-----------
1. Put the target paper on a background paper with bright color.  
2. Use your phone/camera to take pictures of the target papers, 
    and put them in the `origin` directory.
3. This program will use color recognition algorithms to detect the target area and your shooting marks, then it can calculate your shooting score.  

Run the code
-----------
Run the code with the following commands:  
1. `cmake CMakeLists.txt`  
2. `make`  
3. `./main`  

You should first select two points to represent the background color and the target color.
Press Enter to confirm your selection.  
Then the program will calculate all the shooting scores for you.  

Dependencies
---------------
* OpenCV 2.0+  
* CMake 2.8+  

Contributing
----------------
The program has been tested on:  
* 10M Air Pistol Target  
* 10M Air Rifle Target  
You can update the code or test this program on more kinds of targets  
