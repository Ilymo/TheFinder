from cs50 import SQL
import csv

# Open csv file
with open("students.csv", "r") as file:

# open database
    db = SQL("sqlite:///new.db")


    #creat dict reader
    reader = csv.DictReader(file)
    for row in reader:
        print(row)
        # insert ID in student table
        db.execute("INSERT )




