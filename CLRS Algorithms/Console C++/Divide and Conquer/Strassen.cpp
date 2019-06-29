// this algorithm multiplies two n*n matrices faster than usual way !

/*
    we have two n*n matrices :
    
        X = [A  B       Y = [E  F
             C   D]          G  H]
    
    also we define below equations :
        P1 = A * (F - H)
        P2 = H * (A + B) 
        P3 = E * (C + D)
        P4 = D * (G - E)
        P5 = (A + D) * (E + H)
        P6 = (B - D) * (G + H)
        P7 = (A - C) * (E + F)

    finally we have :
        
                | P6 + P5 + P4 - P2     P1 + P2           |
    X * Y =     |                                         |
                | P3 + P4               P1 + P5 - P3 - P7 |

 */

#include <iostream>

using namespace std;

void Strassen(int n,int **X,int **Y,int **Ans); // main function
void input(int n , int **A); // function to get matrix
void output(int n , int **Ans); // pirnt a matrix

int main(){
    int **X; // matrix X
    int **Y; // matrix Y
    int **Ans; // Matrin Ans
    int n; // size of matrices

    cout << "Size of matrices : ";
    cin >> n;

    // allocate memory for matrices :
    Ans = new int*[n];
    for(int i= 0 ; i<n;i++){
        Ans[i]=new int[n];
    }

    X = new int*[n];
    for (int i = 0; i < n; i++)
    {
        X[i]= new int[n];
    }

    Y = new int*[n];
    for (int i = 0; i < n; i++)
    {
        Y[i]= new int[n];
    }

    cout << "Enter X : "<< endl;
    input(n,X);
    system("clear");
    output(n,X);

    cout << "Enter Y : " << endl;
    input(n,Y);
    system("clear");
    output(n,Y);


    Strassen(n,X,Y,Ans);

    output(n,Ans);

    return 0;
}

void Strassen(int n,int **X,int **Y,int **Ans){
    cout << "Ans = X * Y" << endl ;
}

void input(int n , int **A){

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "[" << i << "," << j <<"] : ";
            cin >> A[i][j];
        }
    }
    
}

void output(int n , int **Ans){

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << Ans[i][j] << "  ";
        }
        cout << endl;
    }
}


