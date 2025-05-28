//tc : O(n) + O(n log n) = O(n log n) 
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int connectRopes ( vector<int>ropes)
{
    //O(n)
    priority_queue<int , vector<int> , greater<int>> pq (ropes.begin() , ropes.end());  //priority_queue<Type, Container, Comparator>
                                                            /*int: Each element in the heap is an int.
                                                            vector<int>: The underlying container is a vector.
                                                            greater<int>: This makes it a min-heap (smallest element has highest priority).
                                                            pq(ropes.begin(), ropes.end()): This initializes the priority queue with the elements in the ropes container.
                                                            So this line creates a min-heap pq that contains all the values in ropes.*/
    int cost = 0 ;
    int min_1 , min_2;

    while(pq.size()>1){
    min_1 = pq.top();
    pq.pop();
    min_2 = pq.top();
    pq.pop();
    cost+= min_1+min_2;
    pq.push(min_1+min_2);
    }

    return cost;

}


int main()
{
    vector<int> ropes = {4,3,2,6};
    cout<<"COST IS "<<connectRopes(ropes);
    return 0;
}