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
void simple_multiply(int **X,int **Y,int **Ans); // multiplies 2*2 matrices
void Add(int n, int **X , int ** Y , int **Ans); // add two matrices
void Sub(int n, int **X , int ** Y , int **Ans); // Subtrac two matrices


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

    // allocate memory to A B C D E F G H and C11 C12 C21 C22 
    // allocate memory to P1 P2 P3 P4 P5 P6 P7 and TmpX TmpY 
    int **A = new int*[n];
    int **B = new int*[n];
    int **C = new int*[n];
    int **D = new int*[n];

    int **E = new int*[n];
    int **F = new int*[n];
    int **G = new int*[n];
    int **H = new int*[n];

    int **C11 = new int*[n];
    int **C12 = new int*[n];
    int **C21 = new int*[n];
    int **C22 = new int*[n];

    int **P1 = new int*[n];
    int **P2 = new int*[n];
    int **P3 = new int*[n];
    int **P4 = new int*[n];
    int **P5 = new int*[n];
    int **P6 = new int*[n];
    int **P7 = new int*[n];

    int ** TmpX = new int*[n];
    int ** TmpY = new int*[n];

    for (int i = 0; i < n; i++)
    {
        A[i] = new int[n];
        B[i] = new int[n];
        C[i] = new int[n];
        D[i] = new int[n];

        E[i] = new int[n];
        F[i] = new int[n];
        G[i] = new int[n];
        H[i] = new int[n];

        C11[i] = new int[n];
        C12[i] = new int[n];
        C21[i] = new int[n];
        C22[i] = new int[n];

        P1[i] = new int[n];
        P2[i] = new int[n];
        P3[i] = new int[n];
        P4[i] = new int[n];
        P5[i] = new int[n];
        P6[i] = new int[n];
        P7[i] = new int[n];

        TmpX[i] = new int[n];
        TmpY[i] = new int[n];
    }
    

    if(n == 2){ // last step 
        simple_multiply(X,Y,Ans);
    }
    else{

        for (int i = 0; i < n/2; i++) // divide matrices to 4 sub matrix
        {
            for (int j = 0; j < n/2; j++)
            {
                A[i][j] = X[i][j];
                B[i][j] = X[i][j+n/2];
                C[i][j] = X[i+n/2][j];
                D[i][j] = X[i+n/2][j+n/2];

                E[i][j] = Y[i][j];
                F[i][j] = Y[i][j+n/2];
                G[i][j] = Y[i+n/2][j];
                H[i][j] = Y[i+n/2][j+n/2];
            }
            
        }

        // Calcute P5
        Add(n/2,A,D,TmpX); // A + D
        Add(n/2,E,H,TmpY); // E + H
        Strassen(n/2,TmpX,TmpY,P5); // P5 = (A + D) * (E + H)
        
    }
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

void simple_multiply(int **X,int **Y,int **Ans){
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            Ans[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                Ans[i][j] = Ans[i][j] + X[i][k] * Y[k][j];
            }
            
        }
        
    }
    
    
}

void Add(int n, int **X,int ** Y , int **Ans){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Ans[i][j] = X[i][j] + Y[i][j];
        }
        
    }
    
}

void Add(int n, int **X,int ** Y , int **Ans){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Ans[i][j] = X[i][j] - Y[i][j];
        }
        
    }
    
}