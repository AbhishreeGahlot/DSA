#include<iostream>
using namespace std;

class Stack{
    public:
    //properties
    int *arr;
    int top;
    int size;

    //behaviour
    Stack(int size)
    {
        this->size=size; //this->class=constructor value;
        arr= new int[size];
        top=-1;
    }
    
    // push 
void push(int element)
{
    if(size-top>1)
    {
        top++;
        arr[top]=element;
    }
    else
    {
        cout<<"STACK OVERFLOW"<<endl;
    }

}

// pop
void pop()
{
if(top>=0)
{
    top--;
}
else
{    cout<<"STACK UNDERFLOW"<<endl;
}
}

// peek
int peek(){
if(top>=0)
{
return arr[top];
}
else{
cout<<"STACK is empty"<<endl;
return -1;
}
}



// isempty
bool isempty()
{
if(top==-1)
{return true;
} 
else
{
return false;
}
}
}
;



int main()
{
    Stack st(5);
    st.push(101);
    st.push(102);
    st.push(103);
    st.pop();
    st.peek();
    if(st.isempty()==true)
    {
    cout<<"STACK is EMPTY"<<"\n";
    }
    else
    {
    cout<<"not EMPTY"<<endl;
    }

return 0;
}
