// returns true or false :topological sorting can be done or not 
class Solution {
public:
    bool dfs(int src , vector<bool>&visited , vector<vector<int>>&adj , vector<bool>&recPath)
    {
        visited[src]=true;
        recPath[src]=true;

        for(int v : adj[src])
        {
                if(!visited[v]) //if not visited 
                {
                    if(dfs(v , visited , adj, recPath))
                    {
                        return true;
                    }
                }
                else //if exist 
                {
                    if(recPath[v]) //and also exist in recursion path 
                    {
                        return true;
                    }
                }
            
        }

        // backtracking
        recPath[src]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         // Build adjacency list
        //  This creates an adjacency list.
        //  adj[i] will store all courses that depend on course i.
         vector<vector<int>> adj(numCourses); 

        for (auto p : prerequisites) {
            int u = p[1];
            int v = p[0];
            adj[u].push_back(v); // u -> v (u must be done before v)
        }

        vector<bool>visited(numCourses , false);
        vector<bool>recPath(numCourses,false);
        for(int i = 0 ;i<visited.size() ;i++)
        {
            if(!visited[i])
            {
               if(dfs(i,visited,adj,recPath))
               {
                return false;
               }
            }
        }
        return true;
    }
};