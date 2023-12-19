from cs50 import SQL
import csv

# Open csv file
with open("students.csv", "r") as file:

# open database
    db = SQL("sqlite:///new.db")


    #creat dict reader
    id = 1
    reader = csv.DictReader(file)
    for row in reader:
        print(row)
        # insert ID and name into students table
        #db.execute("INSERT INTO students(id, student_name) VALUES(?, ?)", row["id"], row["student_name"])

        # insert id, house_name and house_head into houses table
        house = row["house"]
        print(house)
        holder = db.execute("SELECT house_name FROM houses")
        print(holder)
        if house in holder[0]['house_name']:
            pass
        else:
            db.execute("INSERT INTO houses(id, house_name, house_head) VALUES (?, ?, ?)", id, row["house"], row["head"])
            id += 1






