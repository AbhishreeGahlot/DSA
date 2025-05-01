#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int>p1 , pair<int,int>p2)
{
    return p1.second>p2.second; //descending order sorting 
}
int profit(vector<pair<int,int>>&jobs , int n)
{
    //1. sorting 
    sort(jobs.begin(),jobs.end(),compare);

    //2.variable declaration
    int profit = jobs[0].second;
    int safeDeadline = 2;

    //3. condition check for maximizing profit 
    for(int i = 1 ;i<n;i++)
    {
        if(jobs[i].first >= safeDeadline)
        {
            profit+=jobs[i].second;
            safeDeadline++;
        }
    }
    cout<<"maximum profit:  " <<profit<<endl;
    return profit;
}



int main()
{
    int n = 4;
    vector<pair<int,int>>jobs(n,make_pair(0,0)); // deadline , profit
    jobs[0]=make_pair(4,20);
    jobs[1]=make_pair(1,10);
    jobs[2]=make_pair(1,40);
    jobs[3]=make_pair(1,30);

    profit(jobs,n);

    return 0;
}