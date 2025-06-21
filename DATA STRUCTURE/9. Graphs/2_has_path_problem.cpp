// For unweighted , undirected graph
#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class Graph
{
    int V ; 
    list<int> *l;

    public:
        Graph(int V)
        {
            this->V = V ;
            l = new list<int> [V];
        }
    
        void addEdge(int u , int v)
        {
            l[u].push_back(v);
            l[v].push_back(u);
        }

    // vector<bool>visited(V,false);
    // DFS
    void dfs_helper( int u , vector<bool>&visited) //O(V+E)
    {
        visited[u] = true ;
        cout<<u<<" ";

        list<int>neighbours = l[u];
        for(int v : neighbours)
        {
            if(!visited[v])
            {
                dfs_helper(v,visited);
            }
        }
    }
    void dfs() //wrapper function
    {
        vector<bool>visited(7,false);
        return dfs_helper(0,visited);
    }

    // helper function
    bool path_helper(int src , int dest , vector<bool>&visited)
    {
        if(src==dest)
        {
            return true;
        }
        visited[src]=true;
        list<int>neighbours = l[src];
        for(int v : neighbours)
        {
            if(!visited[v])
            {
               if(path_helper(v,dest,visited))
               {
                return true; // backtrack true return
               }
            }
        }
        return false;
    }
    bool has_path() //wrapper function
    {
        vector<bool>visited(V,false);
        return path_helper(0,6,visited);
    }
};

int main()
{
    vector<bool>visited(7,false);
    Graph graph(7);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(3,4);
    graph.addEdge(3,5);
    graph.addEdge(4,5);
    graph.addEdge(5,6);

    cout<<graph.has_path();
    return 0;

}
