# keytar
A shitty Guitar Hero controller code for ESP32: [Video](https://youtube.com/watch?v=os85YB9zJnA)

## How to use
1. Get a keyboard
2. Get an ESP32(though with some tweaks it might also work on other microcontrollers with Arduino IDE support)
3. Get a potentiometer-based thumb stick with separate X and Y axis
4. Connect the Y axis potentiometer pins to ESP32, the value pin should be connected to GPIO34(you can change this value in the Arduino sketch if you know what you are doing)
5. Upload the code to ESP32
6. Realize that the default settings are dogshit
7. Tweak the settings
8. Upload the code to ESP32
9. Enjoy i guess
10. Oh wait, not yet. If you are on Windows you have to change `/dev/ttyACM0` in `strum.py` to an ESP32 COM port, so instead of `Serial("/dev/ttyACM0")` you should have `Serial("COM4")`, but with a different COM port number ofcourse
11. Yes these instructions are intentionally bad because why would anybody even try to build this shit
