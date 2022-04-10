# Mechatronics:- PICK AND PLACE ROBOTIC ARM : Involves the application of ARDUINO, Color Detecting Sensor and Motors.
Term project: During the course of Mechatronics laboratory in spring semester 2022, Mechanical systems design , M.Tech , IIT Kharagpur.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
ABSTRACT: 
A Robotic arm is controlled and specified to perform an automatic task of detecting and picking a coloured ball and placing it in a predefined position. The task consists of two major things. One is the detecting the user specified coloured ball, with the help of colour detecting sensor and the second thing is to pick and place the same ball , in a predefined position, using a mechanical gripper. Both these sub-tasks are co-ordinated with each other and controlled using an  Arduino UNO board, which acts as a motherboard to this entire task. It takes in power required for the task from an external source (Battery) and set of instructions from the user, co-ordinate the functions of each component attached to it and  performs the task according to the C++ program instructed by the user.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
WORKING PRINCIPLE:
The mechanism starts with the user, specifying the input in terms of which coloured ball the Robotic arm is required to pick and place it near him. This user input is given through the push buttons. There are three push buttons, one for each colour of the ball i.e. Red, Blue and green. Upon receiving the signal, the Primary Motor  starts rotating , which in turn moves the Moving C section arm . This motion transmission from primary motor to the moving arm is ensured using Timing Belt and Pulleys. The colour detecting sensor  attached to the moving arm also gets activated as soon as primary motor starts rotating and continuously detects the colour nearby it. As soon as the sensor detects the user specified colour, the primary motor stops rotating and along with it, after a certain second of delay, the secondary motor  switches on and lower the Mechanical gripper using the timing belt and pulley. As soon as the Gripper reaches the base of box, the arms of the gripper, which were kept open till that point, closes gradually and firmly hold the ball by controlling the servo motor connected to the arms. Then again after ensuring the balls is firmly held by arms of gripper, the secondary motor rotates in opposite direction, lifts up the mechanical gripper. At the point, the gripper reaches original position, the primary motor starts rotating in the opposite direction until the moving C section arm reaches its original position. As soon as the moving arm reach the home position i.e. empty box, the servo motor at the gripper opens the arms rotating by same amount as it did while closing, and releases the ball. The ball is then picked up from the empty box by the user. This marks the end of mechanism and hence all the components were switched off until the next input.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
FLOW DIAGRAM:
![image](https://user-images.githubusercontent.com/86163226/162606562-94ab293e-850e-4f44-b9e5-d6ac6b397421.png)
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
[DEMONSTRATION VIDEO:] (https://www.youtube.com/watch?v=Mo6bAmHys4M)
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
OUTCOMES OF THE PROJECT:
  Acquainted with the Arduino and other electronic components.	
  Understood the working principles and controlling the functions of,
          •	TCS 3200 colour detecting sensor
          •	Stepper motor
          •	Servo motor
  Understood the essence of 
          •	Team work
          •	Collaborative tasks
          •	Planning and implementations of projects
          •	Modelling and design using usual DIY components.
          •	Making an alternative plan in case of unforeseen situations.
