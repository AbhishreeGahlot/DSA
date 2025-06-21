#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph
{
    int V ; // node val to be saved 
    list<int> *l;
    bool is_undir;
    public:
        Graph(int V , bool is_undir=true)
        {
            this->V = V;
            l = new list<int>[V];
            this->is_undir = is_undir;
        }

         void addEdge(int u , int v) // for undirected graph
        {
            l[u].push_back(v);
            if(is_undir)
            {
             l[v].push_back(u);   
            }
        }

        
// - **`src`**: Current node being visited
// - **`par`**: Parent of `src` in the DFS tree (to avoid false positives)
// - **`visited`**: Boolean vector to keep track of visited nodes

    // cycle exist in undirected graph or not 
    bool is_cycle_helper(int src , vector<bool>&visited , vector<bool>&rec_path) //O(V+E)
    {
        visited[src]=true;
        rec_path[src]=true;
        list<int>&neighbours = l[src];

        for(int v : neighbours)
        {
            if(!visited[v])
            {
                if(is_cycle_helper(v,visited,rec_path))
                {
                    return true; //// Cycle found in recursion  
                }
            }
            else{
                if( rec_path[v]) //// visited + true in rec_path 
                {
                    return true; // cycle exist 
                }
            }
        }
        rec_path[src]=false; // backtracking
        return false;
    }
    bool is_cycle() //wrapper function
    {
        vector<bool> visited(V, false);
        vector<bool> rec_path(V, false);
        for (int i = 0; i < V; i++) // loop for disconnected components
        {
            if (!visited[i])
            {
                if (is_cycle_helper(i, visited , rec_path))
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
    Graph graph(4,false);
    graph.addEdge(1,0);
    graph.addEdge(0,2);
    graph.addEdge(2,3);
    graph.addEdge(3,0);
 
    cout<<graph.is_cycle();
    return 0;
}