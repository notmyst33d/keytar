from pynput.keyboard import Controller, Key
from serial import Serial

keyboard = Controller()
controller = Serial("/dev/ttyACM0")
last_key = None

while True:
    action = controller.read(1)
    if action == b"\x00":
        #print("Rest")
        if last_key:
            keyboard.release(last_key)
            last_key = None
        else:
            keyboard.release(Key.f8)
            keyboard.release(Key.f7)
    elif action == b"\x01":
        #print("Down")
        if last_key:
            keyboard.release(last_key)
        last_key = Key.f8
        keyboard.press(last_key)
    elif action == b"\x02":
        #print("Up")
        if last_key:
            keyboard.release(last_key)
        last_key = Key.f7
        keyboard.press(last_key)
