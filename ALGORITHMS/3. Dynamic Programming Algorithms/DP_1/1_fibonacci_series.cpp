#include<bits/stdc++.h>
using namespace std;

int fib_dp(int n , vector<int>&f) //using memoization 
{
    if(n==0 || n==1)
    {
        return n;
    }

    if(n==-1)
    {
        return f[n];
    }

    f[n] = fib_dp(n-1 , f) + fib_dp(n-2  , f);

    return f[n];

}

int fibo_tab(int n) //using tabulation
{
    vector<int>f(n+1 , 0);

    f[0]=0;
    f[1]=1;

    for(int i=2 ;i<=n ;i++)
    {
        f[i] = f[i-1] + f[i-2];
    }

    return f[n];
}

// optimised and will pass leetcode testcases
class Solution {
public:

// We only need the last two Fibonacci values at any point:
// prev2: stores fib(i - 2)
// prev1: stores fib(i - 1)
// curr: stores fib(i), the current value being calculated

   int fib(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;

    int prev2 = 0, prev1 = 1, curr;

    for(int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

};
int main()
{   
    int n =6;
    // vector<int>f(n+1 , -1);
    // cout<< "using memoization "<< fib_dp(n , f)<<endl;
    cout<<"using tabulation: "<<fibo_tab(n)<<endl;
    return 0;
}