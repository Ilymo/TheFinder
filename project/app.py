
from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request

MOVIE_TAGS = ["Action", "Adventure", "Animation", "Comedy", "Crime", "Documentary", "Drama", "Family", "Fantasy",
        "History", "Horror", "Music", "Mystery", "Romance", "Science", "TV", "Thriller", "War", "Western",]

ANIME_TAGS = ["Action", "Adventure", "Avant Garde", "Award Winning", "Boys Love", "Comedy", "Drama", "Ecchi", "Fantasy",
              "Girls Love", "Gourmet", "Horror", "Mystery", "Romance", "Sci-Fi", "Slice of Life", "Sports", "Supernatural", "Suspense"]

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
    return render_template("movie.html", tags=MOVIE_TAGS, title=title)


@app.route("/anime.html")
def anime():
    name = db.execute("SELECT Name FROM anime")
    return render_template("anime.html", tags=ANIME_TAGS, name=name)


@app.route("/movieresult.html")
def movieresult():
###### MOVIE SEARCH
##### For tag research:
    # Check if input
    if request.args.get("tag1") in MOVIE_TAGS and request.args.get("year") and request.args.get("rate"):

        # Get tag, year and rate from input
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

##### For reference research:
    elif request.args.get("reference"):

        # Get reference
        reference = request.args.get("reference")
        # Get tags from reference
        tags = db.execute("SELECT Genre FROM movies WHERE Title LIKE ?", reference)

        # get year and rate from input
        year = request.args.get("year")
        rate = request.args.get("rate")

        # split tags into list and remove ","
        unique_tag = str.split(tags[0]["Genre"].replace(",", ""))

        # count nb of tags
        tag_nb = len(unique_tag)

        # sqlite query depending on tag_nb
        if tag_nb >= 3:
            movie = db.execute("SELECT * FROM movies WHERE Title != ? AND Release_Date >= ? AND Vote_Average >= ? AND Genre LIKE ? AND Genre LIKE ? AND Genre LIKE ? ORDER BY RANDOM() LIMIT 10",
                               reference, year, rate, (f'%{unique_tag[0]}%'), (f'%{unique_tag[1]}%'), (f'%{unique_tag[2]}%'))

        elif tag_nb == 2:
            movie = db.execute("SELECT * FROM movies WHERE Title != ? AND Release_Date >= ? AND Vote_Average >= ? AND Genre LIKE ? AND Genre LIKE ? ORDER BY RANDOM() LIMIT 10",
                               reference, year, rate, (f'%{unique_tag[0]}%'), (f'%{unique_tag[1]}%'))

        elif tag_nb == 1:
            movie = db.execute("SELECT * FROM movies WHERE Title != ? AND Release_Date >= ? AND Vote_Average >= ? AND Genre LIKE ? ORDER BY RANDOM() LIMIT 10",
                               reference, year, rate, (f'%{unique_tag[0]}%'))

        # if no result
        if not movie:
            return render_template("noresult.html")
        # if result
        return render_template("result.html", movie=movie)

    # if no input
    return render_template("noresult.html")


@app.route("/animeresult.html")
def animeresult():
#### ANIME SEARCH
##### For tag research:
    # Check if input
    if request.args.get("tag1") in ANIME_TAGS and request.args.get("year") and request.args.get("rate"):

        # Get tag, year and rate from input
        tag1 = request.args.get("tag1")
        tag2 = request.args.get("tag2")
        tag3 = request.args.get("tag3")
        year = request.args.get("year")
        rate = request.args.get("rate")
        # Sqlite query with tag1, tag2, tag3, year, rate
        anime = db.execute("SELECT * FROM anime WHERE Date >= ? AND Type = 'TV' AND Score > ? AND Genres LIKE ? AND Genres LIKE ? AND Genres LIKE ? ORDER BY RANDOM() LIMIT 10",
                           year, rate, (f'%{tag1}%'), (f'%{tag2}%'), (f'%{tag3}%'))

        # if no result:
        if not anime:
            return render_template("noresult.html")
        # if result
        return render_template("result.html", anime=anime)

##### For reference research:
    elif request.args.get("reference"):

        # Get reference
        reference = request.args.get("reference")
        # Get tags from reference
        tags = db.execute("SELECT Genres FROM anime WHERE Name LIKE ?", reference)

        # get year and rate from input
        year = request.args.get("year")
        rate = request.args.get("rate")

        # split tags into list and remove ","
        unique_tag = str.split(tags[0]["Genres"].replace(",", ""))

        # count nb of tags
        tag_nb = len(unique_tag)

        # sqlite query depending on tag_nb
        if tag_nb >= 3:
            anime = db.execute("SELECT * FROM anime WHERE Name != ? AND Type = 'TV' AND Date >= ? AND Score >= ? AND Genres LIKE ? AND Genres LIKE ? AND Genres LIKE ? ORDER BY RANDOM() LIMIT 10",
                               reference, year, rate, (f'%{unique_tag[0]}%'), (f'%{unique_tag[1]}%'), (f'%{unique_tag[2]}%'))

        elif tag_nb == 2:
            anime = db.execute("SELECT * FROM anime WHERE Title != ? AND Type = 'TV' AND Date >= ? AND Score >= ? AND Genres LIKE ? AND Genres LIKE ? ORDER BY RANDOM() LIMIT 10",
                               reference, year, rate, (f'%{unique_tag[0]}%'), (f'%{unique_tag[1]}%'))

        elif tag_nb == 1:
            tag1 = unique_tag[0].replace(",", "")
            anime = db.execute("SELECT * FROM anime WHERE Title != ? AND Type = 'TV' AND Date >= ? AND Score >= ? AND Genres LIKE ? ORDER BY RANDOM() LIMIT 10",
                               reference, year, rate, (f'%{unique_tag[0]}%'))

        # if no result
        if not anime:
            return render_template("noresult.html")
        # if result
        return render_template("result.html", anime=anime)

    # if no input
    return render_template("noresult.html")
