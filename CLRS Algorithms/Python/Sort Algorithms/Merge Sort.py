#   Poorya Mohammadi Nasab
#   April,2019

import os

def Merge_Sort(Array=[]):
    #begin
    if len(Array)>1:
        # find mid of array
        Mid = len(Array) // 2

        # Build left sub array
        Left = Array[:Mid]

        # Build right sub array
        Right = Array[Mid:]

        # call merge_sort of each sub Array
        Merge_Sort(Left)
        Merge_Sort(Right)

       
        # merge two sorted sub array
        
        i=0
        j=0
        k=0

        # Copy data to temp arrays L[] and R[] 
        while i < len(Left) and j < len(Right): 
            if Left[i] < Right[j]: 
                Array[k] = Left[i] 
                i+=1
            else: 
                Array[k] = Right[j] 
                j+=1

            k+=1
          
        # Checking if any element was left 
        while i < len(Left): 
            Array[k] = Left[i] 
            i+=1
            k+=1
          
        while j < len(Right): 
            Array[k] = Right[j] 
            j+=1
            k+=1

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
Array = Merge_Sort(Array)
print(Array)
# end main 