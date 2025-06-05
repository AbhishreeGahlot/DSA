#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
    unordered_set<int>s;
   //unique keys only 
    s.insert(1);
    s.insert(4);
    s.insert(0);
    s.insert(9);
    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(1);

    cout<<"size is "<<s.size()<<endl;
    
    for(const int set : s)
    {
        cout<<set<<endl;
    }
    
   
    return 0;
}
