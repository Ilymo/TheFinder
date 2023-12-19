SELECT * FROM stars WHERE person_id = (SELECT id FROM people WHERE name = "Chadwick Boseman")
