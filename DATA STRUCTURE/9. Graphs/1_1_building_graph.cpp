// For weighted , undirected graph
#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class Graph {
    int V;
    list<pair<int, int>> *l;

public:
    Graph(int V) {
        this->V = V;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int weight) {
        l[u].push_back({v, weight});
        l[v].push_back({u, weight}); // undirected
    }

    void print() {
        for (int u = 0; u < V; u++) {
            cout << u << " : ";
            for (auto v : l[u]) {
                cout << "(" << v.first << ", wt=" << v.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph graph(5);

    // Adding edges with weights
    graph.addEdge(0, 1, 10);
    graph.addEdge(1, 2, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 20);
    graph.addEdge(2, 4, 25);

    graph.print();
    return 0;
}
