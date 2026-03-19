from flask import Flask, request
from flask_cors import CORS
import os

app = Flask(__name__)
CORS(app)

USERS_FILE = os.path.join(os.path.dirname(__file__), '../users.txt')

@app.route('/add-user-python', methods=['POST'])
def add_user():
    username = request.form.get('user')

    if username:
        with open(USERS_FILE, "a") as f:
            f.write(username + "\n")
        return "User added via Python", 200
    
    return "No user provided", 400

app.run(port=5000, debug=True)