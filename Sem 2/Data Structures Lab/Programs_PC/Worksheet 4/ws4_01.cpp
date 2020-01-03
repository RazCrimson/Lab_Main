#include <iostream>
#include <sparseMatrix.cpp>


using namespace std;

int main()
{
    int r,c;
    cout<<"\nEnter the no. of rows and columns : ";
    cin>>r>>c;
    if(r<1||c<1)
    {
        cout<<"Error in size!!";
        exit(0);
    }
    int **arr= new int*[r];
    for(int i=0;i<r;i++)
        arr[i]=new int[c];
    cout<<"\nEnter the elements of the matrix : ";
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>arr[i][j];
        }
    }
    sparseMatrix a(arr,r,c);
    a.print();
    // needs more work
}


