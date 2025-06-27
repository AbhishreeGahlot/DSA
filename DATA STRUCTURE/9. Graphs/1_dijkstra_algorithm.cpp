#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

class Edge
{ 
public:
    int v ; // destination node 
    int wt ; // weight from u to v 

    Edge(int v , int wt)
    {
        this->v = v;
        this->wt = wt;
    } 
};

// dijkstra logic
void dijkstra( int src , vector<vector<Edge>>graph , int V)
{
    // 1.build a min heap based pq 
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >pq;  
    // 2. Distance Array 
    vector<int>dist(V ,INT_MAX);
    // 3. Push in pq
    pq.push(make_pair(0,src));
    // 4. Initial distance 
    dist[src]=0;
    // 5. relaxation logic
    while(pq.size()>0)
    {
        int u = pq.top().second;
        pq.pop();

        vector<Edge>edges = graph[u];

        for(Edge e : edges)
        {
            if(dist[e.v]>dist[u]+ e.wt)
            {
                dist[e.v] = dist[u] + e.wt;
                pq.push(make_pair(dist[e.v] , e.v));
            }
        }
    }

    for(int d : dist)
    {
        cout<<d<<" ";
    }
}

int main()
{
    int V= 6;
    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));

    graph[1].push_back(Edge(2,1));
    graph[1].push_back(Edge(3,7));

    graph[0].push_back(Edge(4,3));

    graph[0].push_back(Edge(5,1));

    graph[0].push_back(Edge(3,2));
    graph[0].push_back(Edge(2,5));

    dijkstra(0, graph, V);
    return 0;
}