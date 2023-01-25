from flask import Flask, send_from_directory
from flask_socketio import SocketIO
import time
import serial

app = Flask(__name__)
app.config['SECRET_KEY'] = 'secret'
socketio = SocketIO(app,cors_allowed_origins="*")
thread = None


def backgroundThread():
    ser = serial.Serial()
    ser.port = 'COM12'
    if not ser.isOpen():
        ser.open()
    while True:
        message = ser.readline().decode('utf-8').replace('\r\n', '')
    
        if(message == "MASS"):
            ser.write(b'656')
            ser.flushInput()

        if(message == "LEFT"):
            input("LEFT:") 
            ser.write(b'\n')
            ser.flushInput()

        if(message == "RIGHT"):
            input("RIGHT:") 
            ser.write(b'\n')
            ser.flushInput()
            
        if(message.startswith("D")):
            temp = message[2:].split(":")
            socketio.emit('leftWeight', temp[0])
            socketio.emit('rightWeight', temp[1])

@socketio.on('connect')
def connect():
    global thread
    if thread is None:
        thread = socketio.start_background_task(target=backgroundThread)
        

@app.route("/")
def base():
    return send_from_directory("../client/public", "index.html")

@app.route("/<path:path>")
def home(path):
    return send_from_directory('../client/public', path)

if __name__ == "__main__":
    socketio.run(app, debug=True)