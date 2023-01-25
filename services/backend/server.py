from flask import Flask, send_from_directory
from flask_socketio import SocketIO

import random

app = Flask(__name__)
app.config['SECRET_KEY'] = 'secret'
socketio = SocketIO(app)

@app.route("/")
def base():
    return send_from_directory("../client/public", "index.html")

@app.route("/<path:path>")
def home(path):
    return send_from_directory('../client/public', path)

@app.route("/get")
def get():
    return {
        "leftPercentage": random.randint(0,100),
        "rightPercentage": random.randint(0,100)
    }

if __name__ == "__main__":
    socketio.run(app)