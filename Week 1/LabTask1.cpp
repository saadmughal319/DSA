// Lab Task

// Write a program to multiply two matrix A and B.
#include <iostream>
using namespace std;
int main()
{
    int r1, c1; // r1=rows of 1st matrix
    int r2, c2; // c2= column of 2nd matirx
    cout << "Enter NO. of Rows for 1st Matrix:" << endl;
    cin >> r1;
    cout << "Enter NO. of Columns for 1st Matrix:" << endl;
    cin >> c1;

    cout << "Enter NO. of Rows for 2nd Matrix:" << endl;
    cin >> r2;
    cout << "Enter NO. of Columns for 2nd Matrix:" << endl;
    cin >> c2;
    // checkin if no of column 1st matrix ==rows of 2nd
    if (c1 != r2)
    {
        cout << "Can not MUltiply these Matrices" << endl;
        return 0;
    }
    int i, j, k, sum; // loop variables
    int A[r1][c1];
    int B[r2][c2];
    int Result[r1][c2];
    // input 1st Matrix;
    cout<<"Enter Elements for 1st Matrix"<<endl;
    for (i = 0; i < r1; i++)
    {
        for (j=0;j<c1;j++)
        {
            cin>>A[i][j];
        }
    }

    // input 2nd Matrix;
    cout<<"Enter Elements for 2nd Matrix"<<endl;
    for (i = 0; i < r2; i++)
    {
        for (j=0;j<c2;j++)
        {
            cin>>B[i][j];
        }
    }

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            sum = 0;
            for (k = 0; k < c1; k++)
            {
                sum = sum + A[i][k] * B[k][j];
            }
            Result[i][j] = sum;
        }
    }

    //print the result
    cout<<"Result of Multiplication is:"<<endl;
     for (i = 0; i < r1; i++)
    {
        for (j=0;j<c2;j++)
        {
            cout<<Result[i][j];
            cout<<"  ";
        }
        cout<<endl;
    }

    return 0;
}