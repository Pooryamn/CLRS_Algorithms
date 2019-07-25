#include <iostream>

using namespace std;

void show(int* A,int n);

int main(){
    
    system("clear");

    int* A;
    int n;

    cout << ".:: Element number : ";
    cin >> n;

    A = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "[" << i+1 << "] : ";
        cin >> A[i];
    }

    system("clear");
    cout << ".:: Input Array : ";
    show(A,n);

    
    return 0;
}

void show(int* A,int n){
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << A[i];
        if(i<n-1){
            cout <<',';
        }
    }
    cout << "]"<< endl;
}   