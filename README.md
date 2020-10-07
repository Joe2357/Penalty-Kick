# Penalty kick

> 2019 - 2학기 RobotC Team-Project

  > By using Arduino

## Motivation
  > For Team project of Robotics  
  > ... and just for **FUN!!**
## Image
  ![Penalty Kick 1](img/Penalty_kick_1.png)
  ![Penalty Kick 2](img/Penalty_kick_2.png)
## Architecture
  1. Start if suer press *Start* **Button**
  2. Infrared sensor starts *ball* **Recognize**  

    If ball was recognized?
      Move goalkeeper to that direction
    If not ( about 2 seconds )
      Don't move goalkeeper
  3. Check whether **Goal** or **Not**

    If goal?
      Print "Congrations" to LCD
    If not
      Print "No Goal" to LCD
  4. End program
## Component
### Button
  ![Button](img/Button.png)
  * By pressing this button, User can start Penalty kick
### Infrared Sensor
  ![Infrared Sensor 1](img/Infrared_sensor_1.png)
  ![Infrared Sensor 2](img/Infrared_sensor_2.png)
  * There is 2 Infrared sensors, both sides of field
  * By using these sensors, we can recognize moving ball
### Servo Motor
  ![Goalkeeper](img/Goalkeeper.png)
  * If infrared sensors recognize moving ball, Servo motor moves to defense the ball
### Ultrasonic Sensor
  ![Ultrasonic Sensor](img/Ultrasonic_sensor.png)
  * Check whether Goal or Not
### LCD ( Liquid-Crystal Display )
  ![LCD](img/LCD.png)

  * Signs appear here ( Shoot / Congratulatios / No goal )