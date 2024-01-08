from flask import Flask, render_template, request

app = Flask(__name__)

SPORTS = ["Basketball", "Soccer", "Climbing"]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def register():
    if not request.form.get("name"):
        return render_template("failure.html")
    for sport in request.form.getall("sport"):
        if sport not in SPORTS:
            return render_template("failure.html")
    sport = request.form.getall("sport")
    name = request.form.get("name")
    return render_template("succes.html", name=name, sport=sport)

