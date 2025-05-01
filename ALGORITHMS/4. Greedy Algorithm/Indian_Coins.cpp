#include<bits/stdc++.h>
using namespace std;

int min_coins(vector<int>coins, int n , int V)
{
    //declaration
    int ans = 0;

    // looping and finding
    for(int i = n-1 ; i>=0 && V>0 ; i-- )
    {
        if(V>=coins[i])
        {
            ans+= V/coins[i];
            V = V % coins[i];
        }
    }
    cout<<"Number of min. coins needed are : " <<ans<<endl;
    return ans;

}

int main()
{
    vector<int>coins={1,2,5,10,20,50,100,500,2000};
    int n = coins.size(); // Correct way to find array
    int V=590;
    min_coins(coins,n,V);
    return 0;
}