#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.pop();
    cout<<s.top()<<"\n";
    cout<<s.size()<<"\n";
    if(s.empty())
    {
        cout<<"stack empty"<<"\n";
    }
    else
    {
        cout<<"empty"<<"\n";
    }
    return 0;
}


//output 
1
1
empty
