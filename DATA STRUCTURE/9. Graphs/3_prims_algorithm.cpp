#include<iostream>
#include<queue>
#include<vector>
#include<list>
using namespace std;

class Graph
{
    int V; // node 
    list<pair<int,int>> *l;

    public:
    Graph(int V)
    {
        this->V=V;
        l = new list<pair<int,int>>[V];
    }

    void addEdge(int u , int v , int wt)
    {
        l[u].push_back({v, wt});
        l[v].push_back({u, wt}); // undirected
    }

    void prims_algorithm( int src )
    {
        // priority queue  : min heap implementation
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq; // stores cost/weight , node val
        vector<bool>mstSet(V,false); // number of v nodes and initialise with false 
        int ans=0;

        pq.push({0,src});

        while(pq.size()>0)
        {
             int u = pq.top().second;
             int wt = pq.top().first;
             pq.pop();

            
            if (mstSet[u])
                continue;
            
            //else
                mstSet[u]=true;
                ans+=wt;
                list<pair<int,int>>neighbors = l[u];
                for(pair<int,int> n: neighbors )
                {
                    pq.push({n.second,n.first}); //n.first : node val , n.second : weight 
                }
             
        }

        cout<<ans;
    }
};

int main()
{
    Graph graph(4);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);
    graph.addEdge(1, 3, 40);
    graph.addEdge(2, 3, 50);
 
    graph.prims_algorithm(0);

    return 0;
}