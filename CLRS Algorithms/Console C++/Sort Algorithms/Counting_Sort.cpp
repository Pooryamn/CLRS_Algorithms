#include <iostream>

using namespace std;

void input(int *A,int n,int min,int max);
void print(int *A,int n);
void Count_sort(int *A,int n,int *res);


int main(){
    int *A;
    int *res;
    int n;
    int min;
    int max;

    cout << ".:: Min value : ";
    cin >> min;
    cout << ".:: Max value : ";
    cin >> max;
    cout << ".:: Elements number : ";
    cin >> n;

    A = new int[n];

    input(A,n,min,max);
    print(A,n);
    //Count_sort(A,n,res);
    //print(res,n);

    return 0;
}


void input(int *A,int n,int min , int max){
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cout << "["<<i+1<<"] : ";
        cin >> tmp;
        if(tmp<=max && tmp>-min){
            A[i] = tmp;
        }
        else{
            i--;
            cout << tmp << " is out of range."<<endl;
        }
    }
}
void print(int *A,int n){
    cout << '[';
    for (int i = 0; i < n; i++)
    {
        cout << A[i];
        if(i<n-1){
            cout << ',';
        }
    }
    cout << ']' << endl;
}
void Count_sort(int *A,int n,int *res);