# Obstacle-avoiding-rotating-head-robot
We are designing an autonomous robotic car that is capable of moving on its own in an unknown and unstructured environment.
It is equipped with software intelligence to sense its environment, detect obstacles in its path and move around in unknown environment avoiding the obstacles.
The robotic car uses an ultrasonic sensor to sense its environment, detect obstacles and safe distance. The robot can rotate the ultrasonic sensor from 0 degree to 180 degrees with the help of a servo motor and find an escape route by measuring distance on its left and right side. The robot automatically turns left or right depending upon the side at which there is no obstacle or a path obstruction is at a greater distance. The robotic car designed in this project runs on two geared DC motors and is powered by the battery. The ultrasonic sensor, servo motor and motor driver IC coupled with two geared DC motors are interfaced with the Arduino board. The Arduino sketch initializes the robot to move in forward direction and manages to detect any obstacle in front of the robot, rotate ultrasonic sensor with help of servo motors, measure distance on left side and right side and turn robot either left or right where ever there is more distance available to move around. The control circuitry is assembled and mounted on a two-wheel chassis. 

The components used are:
1.	Arduino Uno -1
2.	Servo motor- 1
3.	HC-05 Ultrasonic Sensor- 1
4.	Geared DC motor-2
5.	L293D Motor Driver IC-1
6.	Voltage Regulator 7805 and 7812 IC- Each 1
7.	Breadboard- 2
8.	Connecting wires
9.	Indicator LEDs
10.	Robot chassis and wheels
