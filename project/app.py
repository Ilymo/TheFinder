import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request

TAGS = ["Action", "Adventure", "Animation", "Comedy", "Crime", "Documentary", "Drama", "Family", "Fantasy",
        "History", "Horror", "Music", "Mystery", "Romance", "Science", "TV", "Thriller", "War", "Western",]

# Configure application
app = Flask(__name__)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///media.db")


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/movie.html")
def movie():
    title = db.execute("SELECT Title FROM movies")
    return render_template("movie.html", tags=TAGS, title=title)


@app.route("/anime.html")
def anime():
    return render_template("anime.html")


@app.route("/result.html")
def result():
    # For tag research:
    # Check if input
    if request.args.get("tag1") in TAGS and request.args.get("year") and request.args.get("rate"):

        # Get tag from input
        tag1 = request.args.get("tag1")
        tag2 = request.args.get("tag2")
        tag3 = request.args.get("tag3")
        year = request.args.get("year")
        rate = request.args.get("rate")
        # Sqlite query with tag1, tag2, tag3, year, rate
        movie = db.execute("SELECT * FROM movies WHERE Release_Date >= ? AND Vote_Average > ? AND Genre LIKE ? AND Genre LIKE ? AND Genre LIKE ? ORDER BY RANDOM() LIMIT 10",
                           year, rate, (f'%{tag1}%'), (f'%{tag2}%'), (f'%{tag3}%'))

        # if no result:
        if not movie:
            return render_template("noresult.html")
        # if result
        return render_template("result.html", movie=movie)

    # For reference research:
    elif request.args.get("reference"):

        # Get reference
        reference = request.args.get("reference")
        # Get data from reference
        movie = db.execute("SELECT * FROM movies WHERE Title = ?", reference)
        print(movie)

        # get tags from reference movie, year and rate from input
        tags = movie[0]["Genre"]
        print(tags)
        year = request.args.get("year")
        rate = request.args.get("rate")

        # split tags, remove ",", get 3 first tags into tag1, tag2, tag3
        unique_tag = str.split(tags.replace(",", ""))

        # count nb of tags
        tag_nb = len(unique_tag)

        if tag_nb >= 3:
            tag1 = unique_tag[0].replace(",", "")
            tag2 = unique_tag[1].replace(",", "")
            tag3 = unique_tag[2].replace(",", "")
            movie = db.execute("SELECT * FROM movies WHERE Title != ? AND Release_Date >= ? AND Vote_Average >= ? AND Genre LIKE ? AND Genre LIKE ? AND Genre LIKE ? ORDER BY RANDOM() LIMIT 10",
                               reference, year, rate, (f'%{tag1}%'), (f'%{tag2}%'), (f'%{tag3}%'))

        elif tag_nb == 2:
            tag1 = unique_tag[0].replace(",", "")
            tag2 = unique_tag[1].replace(",", "")
            movie = db.execute("SELECT * FROM movies WHERE Title != ? AND Release_Date >= ? AND Vote_Average >= ? AND Genre LIKE ? AND Genre LIKE ? ORDER BY RANDOM() LIMIT 10",
                               reference, year, rate, (f'%{tag1}%'), (f'%{tag2}%'))

        elif tag_nb == 1:
            tag1 = unique_tag[0].replace(",", "")
            movie = db.execute("SELECT * FROM movies WHERE Title != ? AND Release_Date >= ? AND Vote_Average >= ? AND Genre LIKE ? ORDER BY RANDOM() LIMIT 10",
                               reference, year, rate, (f'%{tag1}%'))

        # if no result
        if not movie:
            return render_template("noresult.html")
        # if result
        return render_template("result.html", movie=movie)

    # if no input
    return render_template("noresult.html")
