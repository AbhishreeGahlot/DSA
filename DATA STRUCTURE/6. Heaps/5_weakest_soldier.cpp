#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

class Row
{
    public:
    int count ; // soldier count in each row 
    int idx ; // index of each row 

    Row(int count , int idx)
    {
        this->count = count ;
        this->idx = idx ;
    }

    // to build min heap with customization we are using operator overloading a comparator function , who acts as a building block for the heap
    bool operator < ( const Row &obj ) const{
        if(this->count == obj.count )
        {
            return this->idx > obj.idx ; // min heap : : smaller idx has higher priority
        }
        // else
        return this->count > obj.count ; //  min heap: smaller count has higher priority
    }

    /* 🧠 Why This Works
            By default, C++ priority_queue is a max-heap, meaning it puts the largest element at the top using the < operator.
            But if you redefine < like this:    
                    operator < This is operator overloading.
                    You're redefining how the < operator works for objects of type Row.
                    So when you write something like row1 < row2, this custom function will be called
                        this->count → refers to the current object's count.
                        obj.count → refers to the count of the other Row object.
    .*/
};


void weakestSoldier ( vector<vector<int>> matrix , int K)
{
    vector<Row> rows; // vector of class row data type 
    for(int i = 0 ; i<matrix.size() ; i++)
    {
        int count = 0 ;
        for( int j = 0 ; j<matrix[i].size() && matrix[i][j]==1 ; j++)
        {
            count++;
        }
        
        rows.push_back(Row(count,i));
    }

    priority_queue<Row> pq ( rows.begin() , rows.end() );
    for(int i = 0 ; i<K ; i++)
    {
        cout<<"Row " << pq.top().idx << endl;
        pq.pop();
    }
}

int main()
{
    vector<vector<int>> matrix = { 
                                    { 1 , 0 , 0 , 0} , 
                                    { 1 , 1, 1 ,1 },
                                    { 1 , 0 , 0 , 0 },
                                    { 1 , 0 , 0 , 0 } 
    };
    int K = 2; //K is the number of weakest rows we want to print.
    weakestSoldier(matrix , K);
    return 0;
}