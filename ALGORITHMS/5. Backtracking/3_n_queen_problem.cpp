#include<iostream>
#include<vector>
using namespace std;

// fn to print matrix 
void print(vector<vector<char>>board , int n )
{
    for(int i = 0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"___________________________"<<endl;
}

//fn to check queen is safe or not 
bool isSafe(vector<vector<char>>board , int row , int col)
{
    int n = board.size();
    //1. horizontally
    for(int j = 0 ; j<n ; j++)
    {
        if(board[row][j] == 'Q')
        {
            return false;
        }
    }

//2. vertically
    for(int i = 0 ; i<n ; i++)
    {
        if(board[i][col] == 'Q')
        {
            return false;
        }
    }

//3. diagonally left 
    for(int i=row, j=col ; i>=0 && j>=0 ; i-- ,j--)
    {
        if(board[i][j] == 'Q')
        {
            return false;
        }
    }

//4. diagonally right
    for(int i=row, j=col ; i>=0 && j<n ; i-- ,j++)
    {
        if(board[i][j] == 'Q')
        {
            return false;
        }
    }

return true;
}
//fn for N queens 
void nqueen(vector<vector<char>>board , int row)
{
    int n = board.size();
    // base condition 
    if(row == n)
    {
        print(board,n); // whenever the base case hits , print the solution 
        return;
    }

    for(int j = 0 ; j<n ; j++) //j->column
    {
        if(isSafe(board,row,j))
        {
            board[row][j] = 'Q'; //putting queen 
            nqueen(board,row+1);  // recursion to move to next row val ( to put the other queen )
            board[row][j] = '.'; //removing queens to put new one ( backtracking)
        }
        
    }       
}
int main()
{
    int n = 4;
    //vector<vector<T>> vec(rows, vector<T>(cols, initial_value));
    vector<vector<char>> board ( n , vector<char>( n , '.'));
    // initialisation of board 
    // for(int i = 0 ; i<n ; i++)
    // {
    //     vector<char> newRow ; 
    //     for(int j=0 ; j<n ; j++)
    //     {
    //         newRow.push_back('.');
    //     }
    //     board.push_back(newRow);
    // }
    nqueen(board , 0); // starting from row = 0 
    return 0;
}