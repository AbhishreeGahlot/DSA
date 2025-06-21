#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph
{
    int V ; // node val to be saved 
    list<int> *l;
    public:
        Graph(int V)
        {
            this->V = V;
            l = new list<int>[V];
        }

         void addEdge(int u , int v) // for undirected graph
        {
            l[u].push_back(v);
            l[v].push_back(u); // remove for directed graph 
        }

        
// - **`src`**: Current node being visited
// - **`par`**: Parent of `src` in the DFS tree (to avoid false positives)
// - **`visited`**: Boolean vector to keep track of visited nodes

    // cycle exist in undirected graph or not 
    bool is_cycle_helper(int src , int par , vector<bool>&visited) //O(V+E)
    {
        visited[src]=true;
        list<int>&neighbours = l[src];

        for(int v : neighbours)
        {
            if(!visited[v])
            {
                if(is_cycle_helper(v,src,visited))
                {
                    return true; //// Cycle found in recursion  
                }
            }
            else{
                if( v != par) //// visited and not parent → cycle
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool is_cycle() //wrapper function
    {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) // loop for disconnected components
    {
        if (!visited[i])
        {
            if (is_cycle_helper(i, -1, visited))
            {
                return true;
            }
        }
    }
    return false;
    }
       
};

int main()
{   
    Graph graph(5);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(0,3);

    graph.addEdge(1,2);

    graph.addEdge(3,4);
 
    cout<<graph.is_cycle();
    return 0;
}