#include<iostream>
#include<vector>
using namespace std;


// fn 
int grid_solver(int row , int col , int m , int n )
{

    if(row==m-1 && col==n-1)
    {
        return 1;
    }

    if(row>m || col>n )
    {
        return 0;
    }

    // right
    int val_1 = grid_solver(row , col+1 , m , n);
    // down
    int val_2 = grid_solver(row+1 , col , m , n);

    return val_1 + val_2 ;

}
int main()
{
    int n = 4 ; 
    int m = 4;
    cout<<grid_solver(0,0,m,n)<<endl;
    return 0;

}