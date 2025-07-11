class Solution {
public:
    vector<int> par;
    vector<int> rank;
    // 1 . find function 
    int find(int x)
    {
        if(par[x]==x)
        {
            return x; // self parent 
        }
        // else
        return par[x] = find(par[x]); //path compression
    }

    // 2. unionBYrank
    void union_by_rank(int a , int b)
    {
        int parA = find(a);
        int parB = find(b);

        // bc 
        if(parA == parB)
            return;
        
        // case 1
        if(rank[parA] == rank[parB])
        {
            par[parB] = parA;
            rank[parA]++;
        }
        //case 2 
        else if(rank[parA] > rank[parB])
        {
            par[parB] = parA;
        }
        // case 3
        else
        {
            par[parA] = parB;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        par.resize(n+1);
        rank.resize(n+1 , 0); // 

        // Initially, each node is its own parent
        for (int i = 1; i <= n; i++) {
            par[i] = i;
        }

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // If both nodes have the same parent, this edge creates a cycle
            if (find(u) == find(v)) {
                return edge; // this is the redundant edge
            } else {
                union_by_rank(u, v); // unite them
            }
        }

        return {}; // should never reach here for valid input
    }
};