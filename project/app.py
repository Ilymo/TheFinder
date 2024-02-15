import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request

TAGS = ["Drama", "Action", "Comedy", "cornichonducul"]

# Configure application
app = Flask(__name__)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///media.db")


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/movie.html")
def movie():
    return render_template("movie.html", tags=TAGS)


@app.route("/anime.html")
def anime():
    return render_template("anime.html")


@app.route("/result.html")
def result():
    # Check if input
    if request.args.get("tag1") in TAGS and request.args.get("year") and request.args.get("rate"):

        # Get tag from input
        tag1 = request.args.get("tag1")
        tag2 = request.args.get("tag2")
        tag3 = request.args.get("tag3")
        year = request.args.get("year")
        rate = request.args.get("rate")
        # Sqlite query with tag1, tag2, tag3, year, rate
        movie = db.execute("SELECT * FROM movies WHERE Release_Date >= ? AND Vote_Average > ? AND Genre LIKE ? AND Genre LIKE ? AND Genre LIKE ? LIMIT 10",
                           year, rate, (f'%{tag1}%'), (f'%{tag2}%'), (f'%{tag3}%'))
        print("tag1:", tag1, "tag2:", tag2, "year:", year, "rate:", rate)
        print("movie:", movie)
        # if no result:
        if not movie:
            return render_template("noresult.html")
        # if result
        return render_template("result.html", movie=movie)
    # if no input
    return render_template("noresult.html")
