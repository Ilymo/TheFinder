import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        # Check if symbol exist
        if not request.form.get("symbol") or lookup(request.form.get("symbol")) == None:
            return apology("Invalid symbol", 403)
        elif request.form.get("shares") <= "0":
            return apology("Invalid number of shares", 403)

        # Getting values
        shares = request.form.get("shares")


        # Check user cash
        user = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"])
        print(user)
        # Check stock price
        stock = lookup(request.form.get("symbol"))
        print(stock)
        #check if enought cash to buy price*shares
        if stock["price"] * shares > user[0]["cash"]:
            return apology("Not enought cash to buy", 403)
        # Add purchase to purchase table
        else:
            db.execute("INSERT INTO purchase (user_id, symbol, price, shares) VALUES (?, ?, ?, ?)",
                       session["user_id"], stock["symbol"], stock["price"], shares)
            newcash = user[0]["cash"] - (stock["price"] * shares)
            db.execute("UPDATE users SET cash = ? WHERE id = ?", newcash, session["user_id"])
        return redirect("/")

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":

        # Check valid input
        if not request.form.get("symbol") or lookup(request.form.get("symbol")) == None:
            return apology("Invalid symbol", 403)
        else:
            stock = lookup(request.form.get("symbol"))
            price = stock["price"]
            symbol = stock["symbol"]
            return render_template("quoted.html", symbol=symbol, price=price)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():

    # Check for POST method
    if request.method == "POST":

        usernames = []
        for value in db.execute("SELECT username FROM users"):
            usernames.append(value["username"])

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure username doesn't already exist
        elif request.form.get("username") in usernames:
            return apology("username already exist", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Ensure confirmation was submitted
        elif not request.form.get("confirmation"):
            return apology("must provide confirmation", 403)

        # Ensure password and confirmation match
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("password and confirmation do not match", 403)

        # Insert new user in users table
        username = request.form.get("username")
        hash = generate_password_hash(request.form.get("password"))
        db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hash)

        rows = db.execute("SELECT * FROM users WHERE username = ?", username)
        session["user_id"] = rows[0]["id"]
        return redirect("/")
    else:
        return render_template("register.html")



@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
