#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int>p1, pair<int,int>p2)
{
    return p1.second < p2.second ; //ascendng
}

int max_chain_length(vector<pair<int,int>>pairs)
{
    int n = pairs.size();

    //1. sort
    sort(pairs.begin(),pairs.end(),compare);

    //2.variable declaration
    int max_len = 1 ;
    int currEnd = pairs[0].second;

    //3. overlapping conditions  check
    for(int i = 1 ; i<n ;i++)
    {
        if(pairs[i].first > currEnd)
        {
            max_len++;
            currEnd = pairs[i].second;
        }
    }

    cout<<"Maximum chain Length is : "<<max_len<<endl;

    return max_len;

}

int main()
{
    int n = 5;
    vector<pair<int,int>>pairs(n,make_pair(0,0));
    pairs[0]=make_pair(5,24);
    pairs[1]=make_pair(39,60);
    pairs[2]=make_pair(5,28);
    pairs[3]=make_pair(27,40);
    pairs[4]=make_pair(50,90);

    max_chain_length(pairs);


    return 0;
}