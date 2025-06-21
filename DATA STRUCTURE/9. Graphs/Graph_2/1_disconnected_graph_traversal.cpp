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

        void dfs_helper(int u , vector<bool>&visited)
        {
            cout<<u<<" ";
            visited[u] = true ;

            list<int>&neighbours = l[u];
            for(int v : neighbours)
            {
                if(!visited[v])
                {
                    dfs_helper(v,visited);
                }
            }
        }
        void dfs()
        {   
            vector<bool>visited(V,false); // v size initialised with false val
            for(int i = 0 ; i<V ; i++)
            {
                if(!visited[i])
                { dfs_helper(i , visited);}
                
                cout<<endl;

            }
        }

        void bfs_helper(int st, vector<bool>&visited)
        {
            queue<int>q;
            q.push(st);
            visited[st]=true;
            while(q.size()>0)
            {
            int u = q.front(); //curr vertex 
                q.pop();
                cout<<u<<" ";

                list<int>neighbour = l[u];

                for(int v : neighbour)
                {
                    if(!visited[v])
                    {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            cout<<endl;
        }

        void bfs()
        {   
            vector<bool>visited(V,false);
            for(int i = 0 ; i<V ; i++)
            {
                if(!visited[i])
                {
                     bfs_helper(i,visited);
                }
            }
        }
};

int main()
{   
    Graph graph(10);
    graph.addEdge(0,2);
    graph.addEdge(2,5);
    graph.addEdge(1,6);
    graph.addEdge(6,4);
    graph.addEdge(4,9);
    graph.addEdge(4,3);
    graph.addEdge(3,8);
    graph.addEdge(3,7);

    graph.dfs();
    graph.bfs();
    return 0;
}