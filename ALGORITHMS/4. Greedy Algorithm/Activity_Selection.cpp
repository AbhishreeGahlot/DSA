#include<iostream>
#include<vector>
using namespace std;

int activity(vector<int>start ,vector<int>end)
{
    //1. sort -> by default done here 

    // 2. declaration of variables
    // what to return : count of activity 
    // which variable to compare and update : countEnd
    int count = 1 ;
    int current_End = end[0];

    //3 . checking the non-overlapping  condition 
    for(int i = 1 ; i<start.size() ; i++)
    {
        if(start[i]>=current_End)
        {
            count++;
            current_End = end[i];
        }

    }

    return count;



}


int main()
{
    //  by default end is sorted in ascending order here
    vector <int> start = {1, 3, 0, 5, 8, 5} ;
    vector <int> end   = { 2, 4, 6, 7, 9, 9} ;
    cout<<activity(start,end)<<endl;


    return 0;
}