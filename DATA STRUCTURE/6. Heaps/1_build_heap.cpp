#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Heap
{
    vector<int>vec; //complete binary tree array , ..maxheap

    public:

    //1.push TC: O(log n )
    void push(int val)
    {
        //step 1 : push the value 
        vec.push_back(val);

        // step 2 : fix the heap
        int x = vec.size()-1; // childIndex
        int parI  = (x-1)/2 ; //parentIndex

        // loop and swap part
        while( parI>=0 && vec[x] > vec[parI]) // to make min heap just put vec[x] <  vec[parI]
        {
            swap(vec[x] , vec[parI]);
            x= parI;
            parI = (x-1)/2 ;
        }
    }


    // 2. pop function o(logn)
    void pop()
    {
        // step 1 : swap
        swap(vec[0], vec[vec.size()-1]);
        //2. delete from vec
        vec.pop_back();
        //3. heapify function , wrappper function to maintain heap as perfect
        heapify(0);//calling fnction helps as helper function  , becoz root index = 0 
    }
    //2.1
    void heapify(int idx) //parentIndex
    { //for min heap reverse the angular brackets
        //base case
        if(idx >=vec.size())
        {
            return;
        }
        int l = 2*idx + 1; // left child
        int r = 2*idx + 2; // right child 
        int maxIdx = idx;// by default parents index , if not max then swap

        if(l <vec.size() &&  vec[l] > vec[maxIdx])
        {
            maxIdx = l ;  
        } 
        if(r <vec.size() &&  vec[r] > vec[maxIdx])
        {
            maxIdx = r ;  
        } 

        swap(vec[idx], vec[maxIdx]);

        if(maxIdx != idx ) //swapping with child node then recursive call is needed 
        {
            heapify(maxIdx);
        }
    }

    //top function TC: O(1 )
    int top()
    {
        return vec[0];
    }

    // empty function
    bool empty()
    {
        return vec.size() == 0 ;
    }
};



int main()
{
    Heap heap;
    vector<int>vec = {8 , 4 , 5 , 1 , 2 };
    for ( int i = 0 ; i < vec.size() ;i++)
    {
        heap.push(vec[i]);
    }
    cout<<"top is "<<heap.top()<<endl;
    heap.pop();
    cout<<"-------------------"<<endl;
    // heap.push(9);
    cout<<"top is "<<heap.top();

    return 0;
}   