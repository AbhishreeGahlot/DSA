// Union and Intersection  of two arrays
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void combine(vector<int>nums1,vector<int>nums2) 
{
    unordered_set<int> s;
    for(int i = 0 ; i<nums1.size();i++)
    {
        s.insert(nums1[i]);
    }
    for(int i = 0 ; i<nums2.size();i++)
    {
        s.insert(nums2[i]);
    }
    for(auto i : s)
    {
        cout<<i<<endl;
    }
}

void intersection(vector<int>nums1,vector<int>nums2)
{
    unordered_set<int>s{nums1.begin(),nums1.end()};

    for(int i : nums2)
    {
        if(s.find(i) != s.end()) //found
        {
            cout<<i<<endl;
            s.erase(i);
        }
    }
}

int main()
{
    vector<int>nums1={ 7 ,3 , 9};
    vector<int>nums2={ 6,3,9,2,9,4};
    cout<<"union : "<<endl;
    combine(nums1,nums2);
    cout<<"intersection : "<<endl;
    intersection(nums1,nums2);


    return 0;
}