#include<iostream>
#include<vector>
using namespace std;

// 1. using recursion
int count_ways_recursion(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }

    return count_ways_recursion(n-1) + count_ways_recursion(n-2);
}

// 2. using memoization 
int count_ways_memoization(int n , vector<int>&arr)
{
     if(n==0 || n==1)
    {
        return 1;
    }

    if(arr[n] != -1)
    {
        return arr[n];
    }

    arr[n] = count_ways_memoization(n-1 , arr) + count_ways_memoization(n-2 , arr);

    return arr[n];
}

// 3. using tabulation 
int count_ways_tabulation(int n , vector<int>&arr)
{
    vector<int>arr(n+1,0);

    arr[0]=1;
    arr[1]=1;

    for(int i=2 ;i<=n ;i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
    }

    return arr[n];
}

int main()
{
    int n = 4;
    vector<int>arr(n+1,-1);
    cout<<"using recursion : "<<count_ways_recursion(n); //1. recursion
    cout<<endl;
    cout<<"using memoization : "<<count_ways_memoization(n,arr); //2. memoization
    cout<<endl;
    cout<<"using tabulation : "<<count_ways_tabulation(n,arr); //3. tabulation
    return 0;
}