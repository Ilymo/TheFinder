CREATE TABLE students (
    id INTEGER,
    student_name TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE houses (
    id INTEGER,
    house_name TEXT,
    house_head TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE assignements(
    student_id INTEGER,
    house_id INTEGER,
    FOREIGN KEY()
)
