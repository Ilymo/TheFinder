# TODO
from cs50 import get_string

# prompt user for text
def get_text():
    n = get_string("text: ")
    return n

# return letters, words, sentences
def lts(text):
    letters = count_letter(text)
    words = count_word(text)
    sentences = count_sentence(text)
    return(letters, words, sentences)

# calculate grade
def calcul_grade(letters, words, sentences):
    L = letters / words * 100
    S = sentences / words * 100
    grade = in(0.0588 * L - 0.296 * S - 15.8)
    return grade


# print grade
def print_grade(grade):
    if grade >= 16:
        print("Grade 16+")
    elif grade < 1:
        print("Before Grade 1")
    else:
        print(grade)

# func count letter
def count_letter(text):
    nb = 0
    length = len(text)

    for i in range(length):
        if 


# func count word

# func count sentence
