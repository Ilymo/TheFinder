
n = "378282246310005"


sum = 0
length = len(n)
holder = 0

#add 0,2,4... to sum
for i in range(0, length, 2):
    holder = int(n[i]) * 2
    holder = str(holder)
    for k in range(len(holder)):
        sum += int(holder[k])



#multi other by 2 and add to sum
for j in range(1, length, 2):
    sum += int(n[j])


#return last digit
print(sum % 10)
