from socket import *
from pynput import keyboard
#import time 
#Bot handles time properly

print("Enters socket")
s= socket(AF_INET, SOCK_DGRAM)
address='192.168.1.10'
s.bind(('',8888))
message=bytearray([])
message.append(1)
message.append(1)
message.append(00)
s.sendto(message,(address,8888))
def on_press(key):
    try:
        message.clear()
        if(key==keyboard.Key.left):
            message.append(2)
            message.append(1)
            message.append(150)
            s.sendto(message,(address,8888))
            print("left")
        if(key==keyboard.Key.right):
            message.append(1)
            message.append(1)
            message.append(150)
            s.sendto(message,(address,8888))
            print("right")  

        if(key==keyboard.Key.up):
            message.append(1)
            message.append(1)
            message.append(100)
            s.sendto(message,(address,8888))
            #time.sleep(0.2)
            message.clear()
            message.append(2)
            message.append(1)          
            message.append(100)
            s.sendto(message,(address,8888))
            print("up")
        if(key==keyboard.Key.down):
            message.append(2)
            message.append(0)
            message.append(100)
            s.sendto(message,(address,8888))
            #time.sleep(0.2)
            message.clear()
            message.append(1)
            message.append(0)
            message.append(100)
            s.sendto(message,(address,8888))
            print("down")
        if(key==keyboard.Key.space):
            message.append(2)
            message.append(0)
            message.append(0)
            s.sendto(message,(address,8888))
            #time.sleep(0.2)
            message.clear()
            message.append(1)
            message.append(0)
            message.append(0)
            s.sendto(message,(address,8888))
            print("space")
    except AttributeError:
        print('special key {0} pressed'.format(
            key))

def on_release(key):
    if key == keyboard.Key.esc:
        # Stop listener
        return False
    
with keyboard.Listener(
        on_press=on_press,
        on_release=on_release) as listener:
    listener.join()
