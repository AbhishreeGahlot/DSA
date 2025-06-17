#include<iostream>
#include<vector>
using namespace std;

// fn to print sudoku
void print_sudoku(int sudoku[9][9])
{
    for(int i = 0 ; i <9 ;i++)
    {
        for(int j = 0 ; j<9 ; j++)
        {
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
}

// fn to tell whether it is safe to place the number or not
bool is_safe( int sudoku[9][9] , int row , int col  , int digit)
{
   //vertical check (row++ , col) 
    for(int i = 0 ; i<=8 ; i++ )
    {
        if(sudoku[i][col] == digit)
        {
            return false;
        }
    }
    //horizontal check (row , col++) 
    for(int j = 0 ; j <=8 ; j++ )
    {
        if(sudoku[row][j] == digit)
        {
            return false;
        }
    }

    // subgrid check(3*3)
    int start_row = (row/3) * 3;
    int start_col = (col/3) * 3;

    for(int i = start_row ; i<=start_row+2 ;i++)
    {
        for(int j = start_col ; j<=start_col+2 ; j++)
        {
            if(sudoku[i][j] == digit)
            {
                return false;
            }
        }
    }

    // else 
    return true ;
}

// fn to solve the sudoku
bool sudoku_solver(int sudoku[9][9] , int row , int col )
{
    // base case condition
    if(row==9)
    {
        print_sudoku(sudoku);
        return true;
    }

    // find the next_row and next_col index 
    int next_row = row ;
    int next_col = col+1 ;

    // condition : if any time we hit the wall means grid end
    if(col + 1  == 9)
    {
        next_row = row + 1 ; 
        next_col = 0 ;
    }

    // first check whether there exist a digit at cell or not 
    if(sudoku[row][col] != 0 ) // not eq to 0 means exist 
    {
        return sudoku_solver(sudoku , next_row , next_col);
    }

    // if no digit exist then
    for(int digit = 1 ; digit<=9 ; digit++)
    {
        if( is_safe( sudoku , row , col , digit )) // if returns true place the digit
        {
            sudoku[row][col] = digit;
            if (sudoku_solver(sudoku , next_row , next_col)) // if it returns true then good else backtrack
            {return true;
            }
            //backtrack and empty that prev cell again 
            sudoku[row][col]=0;
        }  
    }

    //else
    return false;
}

int main()
{
    // 0 means empty cells
    int sudoku[9][9] = {
        { 0 , 0 , 8 , 0 , 0 , 0 , 0 , 0 , 0  },
        { 4 , 9 , 0 , 1 , 5 , 7 , 0 , 0 , 2 },
        { 0 , 0 , 3 , 0 , 0 , 4 , 1 , 9 , 0 },
        { 1 , 8 , 5 , 0 , 6 , 0 , 0 , 2 , 0 },
        { 0 , 0 , 0 , 0 , 2 , 0 , 0 , 6 , 0 },
        { 9 , 6 , 0 , 4 , 0 , 5 , 3 , 0 , 0 },
        { 0 , 3 , 0 , 0 , 7 , 2 , 0 , 0 , 4 },
        { 0 , 4 , 9 , 0 , 3 , 0 , 0 , 5 , 7 },
        { 8 , 2 , 7 , 0 , 0 , 9 , 0 , 1 , 3}
    };
    // fn calling from row=0 and col=0
    sudoku_solver(sudoku,0,0);
    return 0;
}