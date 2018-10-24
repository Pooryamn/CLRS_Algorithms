// This algorithm is on page 18 in clrs Book

// This aligoritm take an unsorted array as input and then sort it .

#include <iostream>

using namespace std;

void Insertion_Sort(int *A,int n);

int main(){
	int A[100];
	int b;
	cout << "Element(s) number : ";
	cin >> b ;
	for(int i=0;i<b;i++){
		cin >> A[i];
	}
	system("clear");
	cout << "Current Array : "<< endl;
	for(int i=0;i<b;i++){
		cout << "[ " << A[i] << " ]  ";
	}
	Insertion_Sort(A,b);
	cout <<endl<< "Sorted Array : " << endl;
	for(int i=0;i<b;i++){
		cout << "[ " << A[i] << " ]  ";
	}
	cout << endl;
	return 0;
}

void Insertion_Sort(int *A,int n){
	int key;
	int i;
	for(int j=1;j<n;j++){
		key = A[j];
        	 i = j-1;
		while(i>=0 && A[i] > key){ //if we change a[i]<key algorithm will be decresing
			A[i+1]=A[i];
			i--;
		}
		A[i+1]=key;	
	}
}

