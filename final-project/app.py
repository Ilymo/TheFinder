import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template


# Configure application
app = Flask(__name__)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///movie.db")

@app.route("/", methods=['POST', 'GET'])
def index():
    if method.request == "POST":
        movie_table = db.execute("SELECT * FROM movie")
        return render_template("index.html", movie_table = movie_table)

    else:
        list = db.execute("SELECT * FROM movie")
        return render_template("index.html", list = list)
