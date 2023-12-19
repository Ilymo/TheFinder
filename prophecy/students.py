import cs50 import SQL
import csv

# Open csv file
with open("students.csv", "r") as file:

    #creat dict reader
    reader = csv.DictReader(file)



