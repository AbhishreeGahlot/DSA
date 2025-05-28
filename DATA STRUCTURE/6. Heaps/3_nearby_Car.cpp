// leetcode q's : https://leetcode.com/problems/k-closest-points-to-origin/description/
#include<bits/stdc++.h>
using namespace std;

class Car
{
    public:
    int idx ; //index of car in the vector
    int distSq ; // square distance from origin
    
    Car(int index , int distanceSquare) // constructor 
    {
        this->idx = index;
        this-> distSq  = distanceSquare;
    }

    // min heap logic using operator overloading
    bool operator < ( const Car &obj ) const{
        return this->distSq > obj.distSq;
    }
};

// now we will find the index and distance for each car 
void nearbyCars ( vector<pair<int,int>> pos , int k)
{
    vector<Car> cars ; // 1. vector<Car> means you're creating a dynamic array (vector) that stores objects of type Car.
    // cars is the name of the variable — it's a list of Car objects.
    for(int i = 0 ; i<pos.size() ;i++) // 2. 
    {
        int distSq = ( pos[i].first * pos[i].first ) + (pos[i].second * pos[i].second );  // x1 sq + y1 sq 
        cars.push_back(Car(i,distSq)); //Then you're creating a Car object using the constructor and pushing it into the cars vector.
    }

    // build priority queue //3. 
    priority_queue<Car> pq (cars.begin() , cars.end()); // O (log n )

    // return the K nearest points //4.     
    for ( int i = 0 ; i <k ; i++)// O ( k * logn + n )
    {
        cout<<"car nearest " << pq.top().idx <<endl ;
        pq.pop();
    }

}


int main()
{
    vector<pair<int,int>> pos; // pair data type to store x,y coordinate value
    pos.push_back(make_pair(3,3));
    pos.push_back(make_pair(5,-1));
    pos.push_back(make_pair(-2,4));

    int k = 2 ; // k nearest points


    nearbyCars(pos,k);

    return 0;
}