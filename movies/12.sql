SELECT * FROM stars WHERE person_id in (SELECT id FROM people WHERE name = "Bradley Cooper" OR name = "Jennifer Lawrence")
