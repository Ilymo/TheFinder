import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request


# Configure application
app = Flask(__name__)

# Configure CS50 Library to use SQLite database
#db = SQL("sqlite:///movie.db")

@app.route("/", methods=['POST', 'GET'])
def index():
        return render_template("index.html")

@app.route("/movie.html")
def movie():
        return render_template("movie.html")

@app.route("/anime.html")
def anime():
        return render_template("anime.html")

@app.route("/result.html")
def result():
        # if by tag: tag1, tag2, year, rate
        test = request.form.get("tag1", "tag2",)
        return render_template("result.html")
