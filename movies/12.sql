SELECT * FROM (SELECT * FROM stars WHERE person_id = (SELECT id FROM people WHERE name = "Bradley Cooper")) WHERE person_id = (SELECT id FROM people WHERE name = "Jennifer Laurence")

