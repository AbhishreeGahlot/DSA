// Find the element that appear more than n/3 times
//TC : O(n)
//SC : O(n)
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void majority_element(vector<int>nums)
{
    unordered_map<int,int> m; ///element , frequency
    
    for(int i = 0 ; i<nums.size();i++)
    {
        //1. case: element already in map (when count = 1(exist if 1))
        //2 case: element not in map (we need to push it),when count = 0(not exist)
        if(m.count(nums[i])==1)
        {
            m[nums[i]]++; //increase the freq
        }
        else
        {
            m[nums[i]] = 1; //initialise with 1 freq
        }
    }

    for(pair<int,int>p : m)
    {
        if(p.second > nums.size()/3)
        {
            cout<<p.first<<endl;
        }
    }
}

int main()
{   
    vector<int>nums={1,3,2,5,1,3,1,5,1};
    majority_element(nums);
    return 0;
}