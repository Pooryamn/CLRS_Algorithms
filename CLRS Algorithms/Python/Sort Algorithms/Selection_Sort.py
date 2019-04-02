#   Poorya Mohammadi Nasab
#   April,2019

import os

def Selection_Sort(Array=[],n=0):
    # begin
    for i in range(0,n-1):
        # begin
        Min_index = i
        for j in range(i+1,n):
            if Array[j] < Array[Min_index]:
                Min_index = j

        tmp = Array[Min_index]
        Array[Min_index] = Array[i]
        Array[i] = tmp

        #end    
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
Array = Selection_Sort(Array,n)
print(Array)

# end main 




