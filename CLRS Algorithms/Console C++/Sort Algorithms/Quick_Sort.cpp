#include <iostream>

using namespace std;

void show(int* A,int n);
void Quick_Sort(int* A,int first,int last);
int partition(int* A,int first,int last);
int random_partition(int* A,int first,int last);
int hoare_partition(int* A,int first,int last);

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

    Quick_Sort(A,0,n-1);
    
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

void Quick_Sort(int* A,int first,int last){
    if(first < last){
        int q = hoare_partition(A,first,last);
        Quick_Sort(A,first,q);
        Quick_Sort(A,q+1,last);
    }
}

int partition(int* A,int first,int last){
    int x = A[last];
    int i = first - 1;

    for (int j = first; j < last; j++)
    {
        if(A[j] <= x){
            i++;
            
            int tmp = A[j];
            A[j] = A[i];
            A[i] = tmp;


        }
    }
    int tmp = A[i+1];
    A[i+1] = A[last];
    A[last] = tmp;

    return i+1;
    
}

int random_partition(int* A,int first,int last){
    int rnd = (rand()% (last - first)) + first;

    int tmp = A[last];
    A[last] = A[rnd];
    A[rnd] = tmp;
    return partition(A,first,last);
}

int hoare_partition(int* A,int first,int last){
    int pivot = A[first];
    int i = first -1 ;
    int j = last +1 ;

    while (true)
    {
        do
        {
            i++;
        } while (A[i] < pivot);


        do
        {
            j--;
        } while (A[j] > pivot);
    

        if (i >=j)
        {
            return j;
        }
        
        
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
        
    }
    
}