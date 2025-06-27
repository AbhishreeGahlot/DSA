class Solution {
public:
    bool dfs(int src, vector<bool>& visited, vector<bool>& recPath, stack<int>& s, vector<int> adj[]) {
        visited[src] = true;
        recPath[src] = true;

        for (int neighbour : adj[src]) {
            if (!visited[neighbour]) {
                if (dfs(neighbour, visited, recPath, s, adj)) {
                    return true; // Cycle detected
                }
            } else if (recPath[neighbour]) {
                return true; // Cycle detected
            }
        }

        recPath[src] = false; // Backtracking
        s.push(src); // Add to stack after visiting all neighbours
        return false; // No cycle
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        // Build adjacency list
        for (auto p : prerequisites) {
            int u = p[1];
            int v = p[0];
            adj[u].push_back(v);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> recPath(numCourses, false);
        stack<int> s;
        vector<int> result;

        // Run DFS on all nodes
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(i, visited, recPath, s, adj)) {
                    return {}; // Cycle detected → no valid order
                }
            }
        }

        // Retrieve topological order from stack
        while (!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }

        return result;
    }
};
