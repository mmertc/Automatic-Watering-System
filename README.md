# Automatic-Watering-System
An Arduino-based automatic watering system for the plants at home. There are 2 water pumps connected to the plants, each connected to a particular group of them that have similar water needs. The motors are driven by relays as Arduino's digital pins cannot supply enough current for the motors to work properly. Hence Arduino controls the motors via the relays.

To minimise water loss, it waters in short bursts of 10 seconds. It also checks if it is time to water every 10 seconds. 
I measured how much water is dispensed in one burst and calculated how many bursts are needed in total in a day to reach a particular watering amount goal. And then calculated how many 10 seconds periods it needs to wait after each burst to reach that goal. The design takes this value as the input and works accordingly.
