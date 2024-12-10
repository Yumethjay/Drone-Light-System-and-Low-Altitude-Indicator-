# Drone Light System and Low Altitude Indicator 🚁
An Arduino-based system to manage drone lights and ensure safe flying at low altitudes. The project uses LEDs for visibility and an ultrasonic sensor to measure the altitude, triggering a warning when the drone flies below 50 cm.

## Features
Drone Lights:

LEDs on the front, back, left, and right for better visibility during flight.

Low Altitude Warning:
An ultrasonic sensor measures the height of the drone from the ground.
A buzzer activates if the altitude goes below 50 cm, warning the pilot.

## Customizable Settings:
Easily adjust the low-altitude threshold or modify light patterns.

## Components Needed
Arduino (e.g., Uno or Nano)

Ultrasonic sensor (HC-SR04)

LEDs (4 for lights)

buzzer

Wires and a breadboard for connections



## How to Use
Connect the components as shown in the circuit diagram.
Upload the provided code to your Arduino using the Arduino IDE.
Power up the Arduino.
The LEDs will turn on as lights.
The sensor will monitor altitude, and the buzzer will alert you if the altitude is less than 50 cm.

## Customization
Change the altitude threshold in the code:

const int LOW_ALTITUDE_THRESHOLD = 50; 

Modify LED behavior to create blinking or fading patterns.

## Why This Project?
This project is ideal for hobbyists and drone enthusiasts who want to add safety features and cool lighting effects to their drones. It’s simple, fun, and practical for improving flying experience.


