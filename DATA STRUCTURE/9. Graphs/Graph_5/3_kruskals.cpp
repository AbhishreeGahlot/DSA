#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

class Edge
{ 
public:
    int u;
    int v ; // destination node 
    int wt ; // weight from u to v 

    Edge(int u , int v , int wt)
    {
        this->u = u;
        this->v = v;
        this->wt = wt;
    } 
};

class Graph
{
    
    public:
    int V; // node 
    vector<Edge>edges;
    vector<int>par;
    vector<int>rank;

   
    Graph(int V)
    {
        this->V=V;
        for(int i =0 ; i<V ; i++)
        {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    void addEdge(int u , int v , int wt)
    {
        edges.push_back(Edge(u,v, wt));
    }

    // find
    int find(int x)
    {
        if(par[x]==x)
        {
            return x;
        }
        //eelse
        return par[x]=find(par[x]);
    }

    void union_by_rank(int u , int v )
    {
        int parU = find(u);
        int parV = find(v);

         if (parU == parV)
            return;

        if(rank[parU]==rank[parV])
        {
            par[parV]=parU;
            rank[parU]++;
        }
        else if(rank[parU]>rank[parV])
        {
            par[parV]=parU;
        }
        else
        {
            par[parU]=parV;
        }
    }

    void kruskals() //O(E log E)
    {
        sort(edges.begin() , edges.end() , [](Edge& a , Edge& b) {return a.wt<b.wt;}); //1 sort

        int minCost =0;
        int count=0;

        for(int i=0 ;i<edges.size() && count<V-1 ;i++)
        {
            Edge e = edges[i];

            int parU = find(e.u);
            int parV = find(e.v);

            if(parU != parV)
            {
                union_by_rank(parU, parV);
                minCost += e.wt;
                count++;
            }
        }

        cout<<"minimum cost is "<< minCost <<endl;
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
 
    graph.kruskals();

    return 0;
}