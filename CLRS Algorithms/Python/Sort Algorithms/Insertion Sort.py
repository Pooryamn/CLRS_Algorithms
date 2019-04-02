#   Poorya Mohammadi Nasab
#   April,2019

import os

def Insertion_Sort(Array=[],n=0):
    # begin
    for i in range(n):
        key = Array[i]
        j=i-1
        while j>=0 and Array[j]>key:
            Array[j+1] = Array[j]
            j=j-1

        Array[j+1] = key
    
    return Array
    # end


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
Array = Insertion_Sort(Array,n)
print(Array)

# end main 




