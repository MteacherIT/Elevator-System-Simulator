# Elevator-System-Simulator
design, implementation and testing a high quality elevator system simulator in Qt C++. 
Elevator System Specification
General Operation
A building is equipped with a group of M elevators (or cars) servicing N floors. Each floor has a pair of "up" and "down" buttons. When pressed, these buttons illuminate and stay lit until an elevator arrives to pick up passengers requesting service in a specific direction. Upon arrival, the elevator rings a bell, opens its doors (both elevator and floor doors) for 10 seconds to allow passengers to exit or board, rings the bell again, closes its doors, and then proceeds to the next destination. Inside the elevator, passengers can select one or more destination floors using a panel with buttons for each floor. The elevator also has a display showing the current floor. Additionally, the elevator control panel has "open door" and "close door" buttons that passengers can use to override the default door timing. The "open door" button can hold the door open longer, while the "close door" button can close the doors sooner. There is also a help button linked to the building's safety service.

Floor and Request Handling
Each elevator is equipped with a sensor that detects when it arrives at a floor. The elevator control system ensures that all requests, both from floors and on-board passengers, are handled efficiently.

Displays and Audio System
Each elevator has a display and an audio system that shows the current floor number and syncs warning messages with audio alerts.

Safety Features
Help: When the "Help" button is pressed, the control system receives an alarm signal, and the passenger is connected to the building's safety service through a voice connection. If there is no response from the building safety within 5 seconds or from the passenger, a 911 emergency call is placed.

Door Obstacles: If the door's light sensor is interrupted while closing, the control system stops and reopens the door. If this happens repeatedly within a short period, a warning sounds over the audio system and a text message is displayed.

Fire: Upon receiving a "Fire" alarm signal from the building or an elevator, the control system commands all elevators to move to a safe floor. An audio and text message informs passengers of the emergency and instructs them to disembark upon reaching the safe floor.

Overload: If the sensors detect that the passenger or cargo load exceeds the elevator's capacity, the control system receives an "Overload" alarm signal. The elevator will not move, and an audio and text message will ask passengers to reduce the load before attempting to move again.

Power Outage: When a "Power Out" alarm signal is received, an audio and text message informs passengers of the power outage. Each elevator moves to a safe floor using battery backup power, and passengers are asked to disembark via audio and text messages. The battery backup is sufficient to perform these actions.
Learning objectives: 
 Exploring Qt architecture and functionality
 Implementing an elevator system simulator using Qt C++ and updating the design as needed
 Implementing variability in elevator allocation strategy
 Building a requirements traceability matrix that includes implementation and testing

by Maryam Khalaf
