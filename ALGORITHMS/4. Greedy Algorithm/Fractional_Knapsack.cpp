#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//2. descending order sort function
bool compare(pair<double,int>p1 ,pair<double,int>p2) //only sort when bool = true 
{
   return p1.first >  p2.first;
}

//1. fractional knapsack
int fractional_knapsack(vector<int>values , vector<int> weight ,     int W)
{  
        //step 00 declaration of ratio array and n size var
        int n = values.size();
        vector<pair<double,int>>ratio(n,make_pair(0.0,0));  //stored ratio value in first and stored index of values and weights in the second

        //step 01 : find the ratio's
        for(int i = 0 ;i<n ;i++)
        {
            double r = values[i]/double(weight[i]); //typecasting done here for double
            ratio[i]=make_pair(r,i);
        }

        //step 02 : sort the ratios in the descending order
        sort(ratio.begin(),ratio.end(),compare);

        int ans=0;
        //step 03 : now fill the knapsack
        for(int i =0 ;i<n;i++)
        {
            int idx = ratio[i].second; //wt , val
            if(weight[idx]<=W)
            {
                ans+=values[idx];
                W-=weight[idx];
            }

            else
            {
                ans+= ratio[i].first * W;
                W=0;
                break;

            }
        }

        cout<<"Max value is "<<ans<<endl;
        return ans;
}

int main()
{
    vector<int>values={60, 100 , 120 };
    vector<int>weight={10 , 20 , 30 };
    int W=50;
    fractional_knapsack(values,weight,W);

    return 0;
}