
n = "4003600000000014"


sum = 0
length = len(n)

#add 0,2,4... to sum
for i in range(length - 1):
    sum += int(n[i] * 2)
    i += 2

    #multi other by 2 and add to sum
j = 1
for j in range(length - 1):
    sum += int(n[j])
    j += 2

print(sum)
