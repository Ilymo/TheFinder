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
    total_value = 0
    user_stocks = db.execute("SELECT * FROM holding WHERE user_id = ?", session["user_id"])
    for rows in user_stocks:
        price = lookup(rows["symbol"])
        total = rows["shares"] * price["price"]
        rows["price"] = usd(price["price"])
        rows["total"] = usd(total)
        total_value += total
    user_cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
    total_value += user_cash[0]["cash"]

    return render_template("index.html", user_stocks=user_stocks, user_cash=usd(user_cash[0]["cash"]), total_value=usd(total_value))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        # Check if symbol exist
        input_shares = request.form.get("shares")
        if not request.form.get("symbol") or lookup(request.form.get("symbol")) == None:
            return apology("Invalid symbol", 400)
        elif input_shares <= "0" or not input_shares.isnumeric():
            return apology("Invalid number of shares", 400)

        # Get number of shares
        shares = float(request.form.get("shares"))

        # Get user info
        user = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"])

        # Get stock price (symbol + price)
        stock = lookup(request.form.get("symbol"))
        print(stock)

        # Check if enought cash to buy price*shares
        if (stock["price"] * shares) > user[0]["cash"]:
            return apology("Not enought cash to buy", 400)

        # If ok, execute purchase
        else:
            # Write purchase in history table
            db.execute("INSERT INTO history (user_id, symbol, price, shares) VALUES (?, ?, ?, ?)",
                       session["user_id"], stock["symbol"], usd(stock["price"]), shares)

            # Check if symbol already in holding with this user_id (update if exist else insert)
            holding = db.execute("SELECT symbol FROM holding WHERE user_id = ? AND symbol = ?", session["user_id"], stock["symbol"])
            if len(holding) != 0:
                if stock["symbol"] in holding[0]["symbol"]:
                    db.execute("UPDATE holding SET shares = shares + ? WHERE user_id = ? AND symbol = ?",
                                shares, session["user_id"], stock["symbol"])
            else:
                db.execute("INSERT INTO holding (user_id, symbol, shares) VALUES (?, ?, ?)",
                            session["user_id"], stock["symbol"], shares)
            # calcule new user cash and update users table
            newcash = user[0]["cash"] - (stock["price"] * shares)
            db.execute("UPDATE users SET cash = ? WHERE id = ?", newcash, session["user_id"])
        return redirect("/")

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    history = db.execute("SELECT * FROM history WHERE user_id = ? ORDER BY datetime DESC", session["user_id"])

    return render_template("history.html", history=history)


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
            return apology("Invalid symbol", 400)
        else:
            stock = lookup(request.form.get("symbol"))
            price = stock["price"]
            symbol = stock["symbol"]
            return render_template("quoted.html", symbol=symbol, price=usd(price))
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
            return apology("must provide username", 400)

        # Ensure username doesn't already exist
        elif request.form.get("username") in usernames:
            return apology("username already exist", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Ensure confirmation was submitted
        elif not request.form.get("confirmation"):
            return apology("must provide confirmation", 400)

        # Ensure password and confirmation match
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("password and confirmation do not match", 400)

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
    # Get symbol holded/shares in holding table
    user_holding = db.execute("SELECT symbol, shares FROM holding WHERE user_id = ?", session["user_id"])
    user_shares = db.execute("SELECT shares FROM holding WHERE user_id = ? AND symbol = ?", session["user_id"], request.form.get("symbol"))
    user_symbol = []
    for rows in user_holding:
        user_symbol.append(rows["symbol"])

    input_shares = request.form.get("shares")
    if request.method == "POST":
        # Check if symbol provided and owned
        if not request.form.get("symbol") or request.form.get("symbol") not in user_symbol:
            return apology("Don't have this symbol")
        # Check if shares input >= 0
        elif input_shares < "0" or not input_shares.isnumeric():
            return apology("Need positive number of shares")
        # Check if shares input not > shares owned
        elif int(request.form.get("shares")) > user_shares[0]["shares"]:
            return apology("Not enought shares owned")


        # Get symbol/negative shares from input
        stock = lookup(request.form.get("symbol"))
        shares = int(request.form.get("shares"))

        # Update history table
        db.execute("INSERT INTO history (user_id, symbol, price, shares) VALUES (?, ?, ?, ?)",
                    session["user_id"], stock["symbol"], usd(stock["price"]), -shares)

        # Update holding table (delete if no shares remain)
        new_shares = user_shares[0]["shares"] - shares
        print(new_shares)
        if new_shares <= 0:
            db.execute("DELETE FROM holding WHERE user_id = ? AND symbol = ?", session["user_id"], stock["symbol"])
        else:
            db.execute("UPDATE holding SET shares = ? WHERE user_id = ? AND symbol = ?", new_shares, session["user_id"], stock["symbol"])

        # Get user reamain cash
        user = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"])
        # calcule new user cash and update users table
        newcash = user[0]["cash"] + (stock["price"] * shares)
        db.execute("UPDATE users SET cash = ? WHERE id = ?", newcash, session["user_id"])
        return redirect("/")

    else:
        return render_template("sell.html", holding=user_holding)