// SORTING LOGIC BASED ON END TIME 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


//declaration of compare function
bool compare(pair<int,int>p1,pair<int,int>p2)
{
    return p1.second < p2.second ; //ascending sorted  ->end  //to order in descending put > this sign
}

int main()
{
    vector<int> start = {0 , 1, 2 };
    vector<int> end = { 9 , 2, 4};

    vector<pair<int,int>> activity(3, make_pair(0,0)); // initialising three elements of array with 0 value
    activity[0]=make_pair(0,9); 
    activity[1]=make_pair(1,2);
    activity[2]=make_pair(2,4);

    for(int i = 0 ; i<activity.size() ;i++)
    {
        cout<<"A"<<i<<" : "<<activity[i].first <<" , " <<activity[i].second<<endl;
    }

    sort(activity.begin(),activity.end(),compare); // compare function is our own defined func

    cout<<"--------------sorted-----------------"<<endl;
    for(int i = 0 ; i<activity.size() ;i++)
    {
        cout<<"A"<<i<<" : "<<activity[i].first <<" , " <<activity[i].second<<endl;
    }


    return 0;
}