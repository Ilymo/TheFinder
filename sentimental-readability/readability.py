# TODO
from cs50 import get_string


def main():
    text = get_text()
    letters = count_letter(text)
    words = count_word(text)
    sentences = count_sentence(text)
    grade = calcul_grade(letters, words, sentences)
    print_grade(grade)


# prompt user for text
def get_text():
    n = get_string("text: ")
    return n


# calculate grade
def calcul_grade(letters, words, sentences):
    L = letters / words * 100
    S = sentences / words * 100
    grade = round(0.0588 * L - 0.296 * S - 15.8)
    return grade


# print grade
def print_grade(grade):
    if grade >= 16:
        print("Grade 16+")
    elif grade < 1:
        print("Before Grade 1")
    else:
        print(f"Grade: {grade}")


# func count letter
def count_letter(text):
    nb = 0
    for char in text:
        if char.isalpha():
            nb += 1
    return nb


# func count word
def count_word(text):
    nb = 0

    if text[0].isalpha:
        nb += 1

    for char in text:
        if char.isspace():
            nb += 1
    return nb


# func count sentence
def count_sentence(text):
    nb = 0
    nb += text.count(".")
    nb += text.count("?")
    nb += text.count("!")

    return nb


main()
