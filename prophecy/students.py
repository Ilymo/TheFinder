from cs50 import SQL
import csv

# Open csv file
with open("students.csv", "r") as file:

# open database
db1 = SQL("sqlite:///roster.db")
db2 = SQL("sqlite:///new.db")



    #creat dict reader
    reader = csv.DictReader(file)
    for row in reader:




