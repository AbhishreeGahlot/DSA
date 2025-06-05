#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    // key , value pair
    unordered_map<string,int>m;
    m["China"] = 150 ; // m[key] = value; treats key as index 
    m["India"] = 50 ;
    m["US"] = 90 ;
    m["Nepal"] = 80 ;

    for(pair<string,int> p : m)
    {
        cout<<p.first<<" ," <<p.second<<endl;
    }

    //count :tells whether the element exist or not 
    // if 1 : exist and 0 : doesn't exist 
    cout<<m.count("India");
    return 0;
}
