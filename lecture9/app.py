from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/greet")
def index():
    name = request.args.get("name", "weirdo")
    return render_template("index.html", name=name)
