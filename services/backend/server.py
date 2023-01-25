from flask import Flask, send_from_directory
from flask_socketio import SocketIO
import time

import random

app = Flask(__name__)
app.config['SECRET_KEY'] = 'secret'
socketio = SocketIO(app,cors_allowed_origins="*")
thread = None

def backgroundThread():
    while True:
        socketio.emit('leftPercentage', random.randint(0,100))
        socketio.emit('rightPercentage', random.randint(0,100))
        time.sleep(1)

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