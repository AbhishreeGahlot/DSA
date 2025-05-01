#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void heapify(int i , vector<int>&arr,int n) // O(logn)
{
    // i is parent here 
    int left = 2*i+1;
    int right = 2*i+2;
    int maxI = i ; //will store the maximum among parent/left/right , initially declared with parent

    // FOR DESCENDING ORDER , CHANGE TO < IN LEFT AND RIGHT 
    if(left < n && arr[left] > arr[maxI]) //checking whther the left index is valid and is or not greater than maxI
    {
        maxI = left;
    }
    
    if(right < n && arr[right] > arr[maxI]) //same goes for right too
    {
        maxI = right;
    }

    if(maxI != i) // swap only when a max value is found in left or right , else the parent is greater only , so no need to swap
    {
        swap(arr[i],arr[maxI]);
        heapify(maxI , arr , n);
    }
}

void heapSort(vector<int>&arr)
{
    int n = arr.size();
    //step 1 : build a max heap 
    for(int i = n/2-1 ; i>=0 ;i--) // O(n * logn )
    {
        heapify(i,arr,n);
    }
    // step 2 : taking elements to correct position
    for (int i = n-1 ; i > 0 ; i--) // o(n * logn)
    {
        swap(arr[0], arr[i]);
        heapify(0 , arr, i);
    }
}


void printArray(vector<int> &arr)
{
    for(int i = 0 ; i<arr.size() ; i++)
    {
        cout<<arr[i] << " ";
    }
    cout<<endl;
}

int main()
{
    vector<int> arr = {1, 4, 2, 5, 3};
    
    cout<<"Before sorting:"<<endl;
    printArray(arr);
    
    heapSort(arr); //overall O(nlognc)
    
    cout<<"After sorting:"<<endl;
    printArray(arr);
    
    return 0;
}

