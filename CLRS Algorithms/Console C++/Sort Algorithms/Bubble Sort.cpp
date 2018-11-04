
#include <iostream>

using namespace std;

void Bubble_Sort(int *A , int n);
void swap(int *a, int *b);

int main(){
	int A[100];
	int n;
	cout << "Element(s) number : ";
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	system("clear");
	cout << "Current Array: " << endl;
	for(int i=0;i<n;i++){
		cout << "[ " << A[i] << " ] ";
	}
	Bubble_Sort(A,n);
	cout << endl << "Sorted Array : " << endl;
	for(int i=0;i<n;i++){
		cout << "[ " <<A[i] << " ] ";
	}
	cout <<endl;
	return 0;
}

void swap(int *a, int *b) {
	        int *temp;
	        temp = a;
	        a = b;
	        b = temp;
}

void Bubble_Sort(int *a, int n){
	for(int i=0;i<n;i++){
		for(int j=n-1;j>=i+1;j--){
			if(a[j]<a[j-1]){
				swap(a[j],a[j-1]);
			}
		}
	}
}


