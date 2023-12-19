CREATE TABLE students (
    id INTEGER,
    student_name TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE houses (
    id INTEGER UNIQUE,
    house_name TEXT UNIQUE,
    house_head TEXT UNIQUE,
    PRIMARY KEY(id)
);

CREATE TABLE assignements(
    student_id INTEGER,
    house_id INTEGER,
    FOREIGN KEY(student_id) REFERENCES students(id),
    FOREIGN KEY(house_id) REFERENCES houses(id)
);
