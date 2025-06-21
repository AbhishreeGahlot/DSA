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

        // to check bipartite graph or not 
        bool bfs()
        {
            vector<bool>visited(V,false);
            vector<int>color(V,-1);
            queue<int>q;

            q.push(0); //insert first index val of visited 
            color[0]=0; // blue color 
            visited[0]=0;

            while(q.size()>0)
            {
                int curr = q.front();
                q.pop();
                list<int>neighbors = l[curr];

                for(int v : neighbors)
                {
                    if(!visited[v]) // if not visited 
                    {
                        visited[v]=true;
                        color[v]= !color[curr];
                        q.push(v);
                    }
                    else // if visited 
                    {
                        if(color[curr] == color[v])
                        {
                            return false;
                        }
                    }
                }
            }
            //else
            return true; //bipartite graph exist 
        }   
};

int main()
{   
    Graph graph(4);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,3);
    graph.addEdge(0,3);
 
    cout<<graph.bfs();
    return 0;
}