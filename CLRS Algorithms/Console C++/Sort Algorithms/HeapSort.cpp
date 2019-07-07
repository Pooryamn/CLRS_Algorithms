#include <iostream>

using namespace std;

// Clases : 
class my_heap{
    private : 
        int *Arr;
        int n;
        int Heaped;//number of elements that heapified

    public :
    // Constractor :

    my_heap(int num){
        n =num;
        Heaped = 0;

        Arr = new int[num];

        for (int i = 0; i < num; i++)
        {
            cout << "["<< i+1 << "] : ";
            cin >> Arr[i]; 
        }
    }

    // print :
    void show(){
        cout << "[";
        for(int i=0;i<n;i++){
            cout<<Arr[i];
            if(i<n-1){
                cout << ",";
            }
        }
        cout << "]\n";
    }  

    void HeapSort(){
        // Sorting Heap
        build_max_heap();
        for (int i = n-1; i >= 0; i--)
        {
            swap(&Arr[0],&Arr[i]);
            Heaped--;
            Max_heapify(0);
        }
        
    }

    void Max_heapify(int index){
        //heapify

        int largest;

        int L = Left(index);
        int R = Right(index);

        if(L < Heaped && Arr[L]>Arr[index]){
            largest = L;
        }
        else{
            largest = index;
        }

        if(R<= Heaped && Arr[R]>Arr[largest]){
            largest = R;
        }

        if(largest != index){
            swap(&Arr[index],&Arr[largest]);
            Max_heapify(largest);
        }

    }

    void build_max_heap(){
        Heaped = n-1;
        for (int i = n/2; i >= 0; i--)
        {
            Max_heapify(i);    
        }
        
    }

    int  Left(int index){
        if(2*index <= n){
            return 2*index;
        }
    }
    int  Right(int index){
        if((2*index)+1 <= n){
            return (2*index)+1;
        }
    }

    void swap(int*a,int *b){
        int tmp;
        tmp = *a;
        *a = *b;
        *b = tmp;
    }

};

// Functions:

int main(){
    int n;

    cout << ".:: Number of elements : ";
    cin >> n;

    my_heap heap(n);
    heap.HeapSort();
    heap.show();
    

    return 0;
} 
