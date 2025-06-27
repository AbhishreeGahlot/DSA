// Complexity : T.C ->  O(V+E)
#include<iostream>
#include<vector>
#include<stack>
#include<list>
using namespace std;

class Graph
{
    private:
        int V ;         // Number of vertices (nodes)
        list<int>*l ; //// Pointer to an array of lists (Adjacency List)
    public:
        Graph(int V)  // Constructor to initialize the graph
        {
            this->V = V ; //Save the number of vertices
            l = new list<int>[V]; // Dynamically create an array of lists (one list per node) 
        }
        void addEdge(int u , int v)
        {
            l[u].push_back(v);
            // l[v].push_back(u);
        }
        // topological sorting using dfs : dfs_Wrapper and dfs_Helper
        void dfs(int src , vector<bool>&visited , stack<int>&s)
        {
            visited[src] = true ; 
            list<int>neighbours= l[src];
            for(int v : neighbours)
            {
                if(!visited[v])
                {
                    dfs(v,visited,s);
                }
            }
            // backtracking
            s.push(src);
        }
        void topological_sort()
        {
            vector<bool>visited(V,false);
            stack<int>s;
            for(int i=0 ; i<visited.size();i++) //  Call DFS for all unvisited nodes
            {
                if(!visited[i])
                {
                    dfs(i,visited,s);
                }
            }
            while(s.size()>0) // Print topological order
            {
                cout<<s.top()<<" ";
                s.pop();
            }
        }
};

int main()
{   
    Graph g(6);
    g.addEdge(5,0);
    g.addEdge(5,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(4,1);
    g.addEdge(4,0);

    g.topological_sort();
    return 0;
}