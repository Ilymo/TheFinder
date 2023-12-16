
n = "4003600000000014"


sum = 0
length = len(n)
n = int(n)
#add 0,2,4... to sum
for i in range(length - 1):
    sum += n[i]
    i += 2

    #multi other by 2 and add to sum
j = 1
for j in range(length - 1):
    sum += n[j] * 2
    j += 2

print(sum)
