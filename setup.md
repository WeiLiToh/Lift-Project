# Switch Setting
There are four DIP switch setting. Ensure that the setting of the DIP switches are accordance to the picture below.

![image](https://user-images.githubusercontent.com/62842333/87240633-c8e1f980-c44d-11ea-9f91-d8666ce18165.png)

# 2 x 16 LCD Panel 
![image](https://user-images.githubusercontent.com/62842333/87240670-2aa26380-c44e-11ea-92dd-4bfa16a4d1f8.png)

The 2 x 16 LCD panel is control by port 2 pins and the LCD panel access is 4 bit. Turn on the LCD panel by pushing the pin 6 of SW7 to the on state. The LCD interface signals are as shown. 

# LEDs
![image](https://user-images.githubusercontent.com/62842333/87240684-5b829880-c44e-11ea-8a41-494a0767211b.png)

The project use two IO ports to represent the lift level. The number of floors available is first to the eight floor. The orientation of the floor level are indicated in the diagram below. Port 1 is for lift A and Port 3 is for Lift B. Pin 0 is level eight and Pin 7 level 1.

![image](https://user-images.githubusercontent.com/62842333/87240727-b6b48b00-c44e-11ea-8351-3cc6d51b8079.png)

The LEDs is to indicate the level which the user has requested for the lift service. When the user request lift service at a certain level, the respective LED at that level need to be turn on. Turning off the LED when the lift request has been fulfilled.

# Tactile Switch 
![image](https://user-images.githubusercontent.com/62842333/87240735-ca5ff180-c44e-11ea-8705-16e214b67fa1.png)

The push button or the tactile switch is for the user to request lift service. The port 1 switches will be used for lift A and port 3 for lift B. 

![image](https://user-images.githubusercontent.com/62842333/87240750-dfd51b80-c44e-11ea-8b3e-1578c302d438.png)

Pin 0 is 8th floor and Pin 7 1st floor.

# Design Requirements
Deisgn is to conform to the design requirements listed below

# Req-01 
This requirement is to display the text “Lift B” and “Lift A” at row 1 column 2 and row 1 column 10 respectively. This requirement is to be display throughout the entire sequence of the lift function.

![image](https://user-images.githubusercontent.com/62842333/87240775-27f43e00-c44f-11ea-9f22-d49736f4af47.png)

# Req-02
This requirement is to display the text “01” and “08 at row 2 column 4 and row 2 column 12 respectively after a power on reset or a push button reset as shown above.

# Req-03
This requirement is to use all the 8 IO pins of port 1 for lift A and 8 IO pins of port 3 for lift B. The port 1 and 3 IO pins are connected to the tact switch and the LEDs. The LEDs are active low which required a logic ‘0’ at the respective IO pin to turn on. 

When the user request lift service at a particular level, the user is required to press the tactile switch for that level. Upon pushing the tactile switch, the respective LED for that floor will be turn on to indicate which level is requesting for lift service. 

When the user press the tactile switch at port 3, the respective level LED will be turn on. The same requirement apply to port 1.

![image](https://user-images.githubusercontent.com/62842333/87240789-4fe3a180-c44f-11ea-82d7-64d569100c53.png) ![image](https://user-images.githubusercontent.com/62842333/87240798-5e31bd80-c44f-11ea-9d00-0f74d18afaed.png)

# Req-04
When the user request for the lift service, the LCD panel is required to indicate the direction of the lift movement. The movement of the lift are categorize to up arrow and down arrow. When the current level of the lift is below the requested service level, the LCD panel is to display two up arrow, as when the current level is above the requested service level, the panel will display two down arrow.

![image](https://user-images.githubusercontent.com/62842333/87240804-70abf700-c44f-11ea-8783-398aa587a0e2.png)
![image](https://user-images.githubusercontent.com/62842333/87240807-77d30500-c44f-11ea-99c0-5a773b13bef8.png)

# Req-05
The operation for both lift A and B have to comply with the flowchart of operation. The flowchart show the overall view of the expected function of the both lift. 

![image](https://user-images.githubusercontent.com/62842333/87240874-ff207880-c44f-11ea-8187-8372c87ee12a.png)

# Req-06
This requirement is to return the 1st level after reaching the request service level. The requirement flowchart is as follow.

![image](https://user-images.githubusercontent.com/62842333/87240885-195a5680-c450-11ea-9779-a10b017bb191.png)





