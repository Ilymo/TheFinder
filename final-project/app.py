import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash


# Configure application
app = Flask(__name__)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///movie.db")

@app.route("/", methods=['POST', 'GET'])
def index():
    if request.method == "POST":
        list = db.execute("SELECT * FROM movie")
        return render_template("index.html", list = list)

    else:
        return render_template("index.html")
