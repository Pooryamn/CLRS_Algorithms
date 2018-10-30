#include <iostream>

using namespace std;

void Selection_Sort(int *A, int n);
void swap(int *a, int *b);

int main() {
	int A[100];
	int n;
	cout << "Element(s) number : ";
	cin >> n;
	for (int i = 0; i<n; i++) {
		cin >> A[i];
	}
	//system("clear");
	cout << "Current Array : " << endl;
	for (int i = 0; i<n; i++) {
		cout << "[ " << A[i] << " ]  ";
	}
	Selection_Sort(A, n);
	cout << endl << "Sorted Array : " << endl;
	for (int i = 0; i<n; i++) {
		cout << "[ " << A[i] << " ]  ";
	}
	cout << endl;
	return 0;
}

void Selection_Sort(int *A, int n) {
	int min;
	for (int i = 0; i<n; i++) {
		min = i;
		for (int j = i+1; j<n; j++) {
			if (A[j]<A[min]) {
				min=j;
			}
		}
		swap(A[min], A[i]);
	}

}

void swap(int *a, int *b) {
	int *temp;
	temp = a;
	a = b;
	b = temp;
}
