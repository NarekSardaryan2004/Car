**README.txt**

# Car Turning Radius Calculation Program  

## Purpose  
This program calculates the turning radius of a car's wheels when the car turns in a specified direction. 
The program considers various factors such as the steering angle, width, and length of the car to compute the radius for each wheel (front-left, rear-left, front-right, rear-right). 
The user can input these parameters and receive calculated radii for each wheel based on the direction of the turn (left or right).

## Mathematical Concept  
The turning radius depends on the steering angle, the car's wheelbase (distance between the front and rear axles), and the width of the car. 
The program uses trigonometric functions to compute the turning radius for each wheel based on these inputs.

- The radius for the front wheels is calculated using the formula:
  
	      Wheelbase
Radius = -------------------
	 sin(steering angle)

  
- The radius for the rear wheels is calculated using:

	      Wheelbase
Radius = -------------------
	 tan(steering angle)

The program adjusts these calculations based on the direction of the turn, either left or right.

## Input  
The program requires the following inputs from the user:  
1. Steering Angle (degrees): The angle at which the steering wheel is turned, measured in degrees (0 to 45 degrees).  
2. Car Width: The distance between the left and right sides of the car (0.5 to 10.1 meters).  
3. Car Length: The distance between the front and rear axles of the car (1.34 to 21.1 meters).  
4. Turn Direction: The direction in which the car is turning, either 'r' (right) or 'l' (left).

## Output  
The program will display the following turning radii for the car's wheels:  
1. Front-left wheel radius  
2. Rear-left wheel radius  
3. Front-right wheel radius  
4. Rear-right wheel radius  

These values are based on the user’s inputs.

## How to Run the Program  
1. Compile and run the program using any C++ compiler.  
2. Provide the required inputs when prompted:  
   - Steering wheel angle (in degrees)  
   - Car width (in meters)  
   - Car length (in meters)  
   - Turn direction (either 'r' or 'l')  
3. The program will calculate and display the radius of each wheel.

## Example Run  
Enter steering wheel angle (degrees): 30  
Enter car width: 2.5  
Enter distance between wheels (length of car): 4.2  
Enter turn direction ('r' for right, 'l' for left): r  
Front left wheel radius: 5.0  
Rear left wheel radius: 4.1  
Front right wheel radius: 5.0  
Rear right wheel radius: 4.1  

## Notes  
- The program ensures that only valid input values are accepted (within the specified ranges).
- If the user enters an invalid input, the program prompts them to enter the value again.
- The steering angle is assumed to be between 0 and 45 degrees for simplicity.

## Author  
Edgar Sahakyan
Narek Sardaryan
Tigran Davtyan
