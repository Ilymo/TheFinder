from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    if request_methods == "POST"
        name = request.form.get("name", "weirdo")
        return render_template("greet.html", name=name)
    return render_template("index.html")


