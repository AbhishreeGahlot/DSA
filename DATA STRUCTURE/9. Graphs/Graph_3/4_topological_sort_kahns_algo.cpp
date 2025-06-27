// Complexity : T.C ->  O(V+E)
#include<iostream>
#include<vector>
#include<queue>
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

        void in_degree(vector<int>&indegree)
        {   
            for(int i=0 ; i<V ;i++)
            {
                list<int>neighbours=l[i];
                for(int v : neighbours)
                {
                    indegree[v]++;
                }
            }
        }

        void topological_sort()
        {
            queue<int>q;
            vector<int>indegree(V,0);
            in_degree(indegree);

            for(int i=0 ; i<V ; i++)
            {
                if(indegree[i]==0)
                {
                    q.push(i);
                }
            }

            while(!q.empty())
            {
                int curr= q.front();
                q.pop();
                cout<<curr<<" ";
                list<int>neighbours=l[curr];
                for(int v : neighbours)
                {
                    indegree[v]--;
                    if(indegree[v]==0)
                    {
                        q.push(v);
                    }
                }
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