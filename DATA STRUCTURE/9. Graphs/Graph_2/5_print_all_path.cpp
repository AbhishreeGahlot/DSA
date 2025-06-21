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

    void path_helper(int src , int dest , vector<bool>&visited , string &path) //O(v+e)
    {
        if(src==dest)
        {
            cout<<path<<dest<<endl;
            return;
        }

        visited[src]=true;
        path += to_string(src);
        
        list<int>neighbors = l[src];

        for(int v : neighbors)
        {
            if(!visited[v])
            {
                path_helper(v,dest,visited,path);
            }
        }

        // backtracking logic
        path = path.substr(0, path.size()-1); //creates a new string takes more memory 
        visited[src]=false;
    }
    
    void all_path_print(int src , int dest)
    {
        vector<bool>visited(V,false);
        string path="";
        path_helper(src,dest,visited,path);
    }
};

int main()
{   
    Graph graph(6,false);
    graph.addEdge(5,0);
    graph.addEdge(5,2);
    graph.addEdge(0,3);
    graph.addEdge(2,3);
    graph.addEdge(4,0);
    graph.addEdge(4,1);
    graph.addEdge(3,1);

    graph.all_path_print(5,1);
    return 0;
}