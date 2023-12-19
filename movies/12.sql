SELECT * FROM stars WHERE person_id = (SELECT id FROM people WHERE name = "Bradley Cooper") OR person_id = (SELECT id FROM people WHERE name = "Jennifer Lawrence")
