
text = "oliVier Mor elLi"
nb = 0
letters = 0
spaces = 0

#count letter
for char in text:
    if char.isalpha():
        letters += 1
    elif char.isspace():
        spaces += 1

#calcul word
nb = letters / spaces


print(nb)
