
text = "oliVier Mor elLi "
nb = 0

if text[0].isalpha:
    nb += 1

#count letter
for char in text:
    if char.isspace():
        nb += 1

#calcul word
print(nb)
