from cs50 import SQL
import csv

# Open csv file
with open("students.csv", "r") as file:

# open database
    db = SQL("sqlite:///new.db")


    #creat dict reader
    house_id = 1
    existing_house = []
    reader = csv.DictReader(file)

    db.execute("DELETE FROM students")
    db.execute("DELETE FROM houses")
    db.execute("DELETE FROM assignements")

    for row in reader:
        print(row)
        # insert ID and name into students table
        db.execute("INSERT INTO students(id, student_name) VALUES(?, ?)", row["id"], row["student_name"])

        # insert id, house_name and house_head into houses table
        if row['house'] in existing_house:
            pass
        else:
            db.execute("INSERT INTO houses(id, house_name, house_head) VALUES (?, ?, ?)", house_id, row["house"], row["head"])
            house_id += 1
            existing_house.append(row['house'])

        # insert match in assignements
        house_id = db.execute("SELECT id FROM houses WHERE house_name = ?", row["house"])
        print(house_id)
        db.execute("INSERT INTO assignements(student_id, house_id) VALUES (?, ?)", row["id"], house_id[0]['id'])





