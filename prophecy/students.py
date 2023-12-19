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
        # insert ID and name into students table
        #db.execute("INSERT INTO students(id, student_name) VALUES(?, ?)", row["id"], row["student_name"])

        # insert id, house_name and house_head into houses table
        id = 1
        db.execute("INSERT INTO houses(id, house_name, house_head) VALUES (?, ?, ?)", id, row["house"], row["head"])





