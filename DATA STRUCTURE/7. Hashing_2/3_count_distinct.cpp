// Count the distinct elements in an array
// Complexity : TC: O(n)  , SC : O(n)
#include<iostream>
#include<vector>
#include<unordered_set>
// #include<bits/stdc++.h>
using namespace std;

// 1. to print the count of unique elements in an array
int count_distinct(vector<int>nums)
{
    unordered_set<int> s; //element , freq 
    for( int i = 0 ; i<nums.size() ; i++)
    {
        s.insert(nums[i]);
    }

    return s.size();
}

int main()
{   
    vector<int>nums = { 4 , 3 , 2 , 5 , 6 , 7 , 3 , 4 , 2 , 1};
    cout<<"Count of distinct element in array : "<<count_distinct(nums)<<endl;
    return 0;
}
