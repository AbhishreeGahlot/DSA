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

        void print()
        {
            for(int u = 0 ; u<V ; u++)
            {
                list<int>neighbour = l[u];
                cout<<u<<" : ";
                for(int v : neighbour)
                {
                    cout<<v<<"  ";
                }
                cout<<endl;
            }
        }

        void bfs() //O(V+E)
    {
        queue<int>q;
        vector<bool>visited(V,false);
        q.push(0);
        visited[0]=true;
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
    void dfs()
    {
        vector<bool>visited(7,false);
        return dfs_helper(0,visited);
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

    graph.print();
    cout<<"________________________________"<<endl;
    graph.bfs();
    cout<<"________________________________"<<endl;
    graph.dfs();
    return 0;

}
