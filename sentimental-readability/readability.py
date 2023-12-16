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
    

# print grade

# func count letter

# func count word

# func count sentence
