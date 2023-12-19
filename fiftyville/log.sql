-- Keep a log of any SQL queries you execute as you solve the mystery.

-- check the crime report
--SELECT *
--FROM crime_scene_reports
--WHERE year = "2021" AND month = "7" AND day = "28" AND street = "Humphrey Street"
-- something about bakery on humphrey street

-- check bakery_security_logs
--SELECT
--FROM bakery_security_logs
--WHERE year = "2021" AND month = "7" AND day = "28"


-- check interviews
--SELECT *
--FROM interviews
--WHERE year = "2021" AND month = "7" AND day = "28"
-- id of interviewed are 161, 162, 163

--take plate that left within 10min and save entrance/exit
 SELECT *
 FROM bakery_security_logs
 WHERE license_plate IN
    (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE year = "2021" AND month = "7" AND day = "28" AND hour = "10" AND minute >= "15" AND minute <= "30"
    )
