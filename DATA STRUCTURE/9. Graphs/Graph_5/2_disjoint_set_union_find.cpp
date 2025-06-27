#include<iostream>
#include<vector>
using namespace std;

class DisjointSet
{
    int n;
    vector<int> par;
    vector<int> rank;

public:  // Make everything accessible from main

    DisjointSet(int n)
    {
        this->n = n;
        par.resize(n);  // Allocate size
        rank.resize(n, 0);

        for(int i = 0; i < n; i++)
        {
            par[i] = i;   // Initially parent is itself
            rank[i] = 0;  // Initially height is 0
        }
    }

    int find(int x)
    {
        if(par[x] == x)
            return x;

        // Path Compression
        return par[x] = find(par[x]);
    }

    void union_by_rank(int a, int b)
    {
        int parA = find(a);
        int parB = find(b);

        if(parA == parB)
            return; // Already in same set

        // Union by rank
        if(rank[parA] == rank[parB])
        {
            par[parB] = parA;
            rank[parA]++;
        }
        else if(rank[parA] > rank[parB])
        {
            par[parB] = parA;
            // No need to increase rank here
        }
        else
        {
            par[parA] = parB;
            // No need to increase rank here
        }
    }
};

int main()
{
    DisjointSet dj(6);
    dj.union_by_rank(0, 2);
    cout << "Parent of 2: " << dj.find(2) << endl;

    dj.union_by_rank(1, 3);
    dj.union_by_rank(2, 5);
    dj.union_by_rank(0, 3);

    cout << "Parent of 2 after more unions: " << dj.find(2) << endl;

    dj.union_by_rank(0, 4);

    return 0;
}
