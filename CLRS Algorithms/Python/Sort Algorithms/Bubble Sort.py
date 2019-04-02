#   Poorya Mohammadi Nasab
#   April,2019

import os

def Bubble_Sort(Array=[],n=0):
    #begin
    for i in range(n-1):
        for j in range(n-i-1):
            # begin
            if Array[j] > Array[j+1]:
                tmp = Array[j]
                Array[j]=Array[j+1]
                Array[j+1]=tmp
            # end
    return Array
    #end
    

# main

Array = []
while True:
    # begin
    try:
        n = int(input('.:: Element(s) number : '))
    except :
        print('Error : You must enter a positive integer !!')
        continue
    else :
        if n<=0:
            print('Error : You must enter a positive integer !!')
        else :
            break
    # end

for i in range(n):
    Array.append(float(input('.:: Enter num[ {} ] : '.format(i+1))))

os.system('clear')
print(Array)
Array = Bubble_Sort(Array,n)
print(Array)
# end main 