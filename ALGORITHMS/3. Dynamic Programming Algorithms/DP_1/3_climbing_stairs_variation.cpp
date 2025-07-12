#include<iostream>
#include<vector>
using namespace std;



//using tabulation variation climbing stairs
int count_ways_tabulation(int n)
{
    vector<int>arr(n+1,0);

    arr[0]=1;
    arr[1]=1;
    arr[2]=2;
    

    for(int i=3 ;i<=n ;i++)
    {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }

    return arr[n];
}


int main()
{   
    cout<<count_ways_tabulation(4);
    return 0;
}