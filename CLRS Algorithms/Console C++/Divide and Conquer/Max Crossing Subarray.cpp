// in this algorithm we find a nonempty , contiguous subarray with maximum sum 

#include <iostream>

using namespace std;

#define CLC "clear" /* for linux */
//#define CLC "cls" /* for windows */

float Find_max(float * array,int n,int * idx);


int main(){

    int n;
    float answer;
    int index[2];
    cout << ".:: Element(s) number : ";
    cin >> n;
    float *array = new float[n];
    for(int i = 0; i < n; i++)
    {
        cout << "..:: Array[ "<<i<<" ] : ";
        cin >> array[i];
    }
    system(CLC);


    //print main array
    cout << ".:: Array = [ ";
    for(int i = 0; i < n; i++)
    {
        cout << array[i]<< " ";
        if (i < n-1) {
            cout << ", ";
        }
    }
    cout << "]"<<endl;
    
    // call function
    answer = Find_max(array,n,index);
    //print subarray
    cout << ".:: Subarray = [ ";
    for(int i = index[0]; i <= index[1]; i++)
    {
        cout << array[i] << " ";
        if(i < index[1]){
            cout << ", ";
        }
    }
    cout << "]" <<endl;
    cout << ".:: Maximum Sum = " << answer << endl;
    
    return 0;
}



float Find_max(float * array,int n,int * idx){
    
    // find mid
    int mid;
    mid = (n-1) / 2;

    //for left subarray
    float left_sum =0 ;
    float sum = 0;
    int left_idx;
    
    for(int i = mid; i >=0; i--)
    {
        sum += array[i];
        if (sum > left_sum) { // if it is better add it else do nothing
            left_sum = sum ;
            left_idx = i ;  // set begin index
        }
    }

    //for right subarray
    float right_sum = 0;
    int right_idx;
    sum = 0 ;
    
    for(int i = mid+1; i < n; i++)
    {
        sum += array[i];
        if (sum > right_sum) {
            right_sum = sum; // if it is better add it else do nothing
            right_idx = i; // set end index
        }
    }

    // set out puts
    idx[0] = left_idx;
    idx[1] = right_idx;
    return right_sum + left_sum ; 
}


    
