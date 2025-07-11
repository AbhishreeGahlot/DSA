class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // step : 01 add all rotten oranges to queue and count fresh ones 
        queue<pair<int ,int>> q; // {row , col }
        int fresh=0;

        for(int i=0; i<n  ;i++)
        {
            for(int j=0 ; j<m ;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j}); //push
                }
                else if(grid[i][j]==1)
                {
                    fresh++;    //fresh count 
                }
            }
        }
        
        // step 02 : directions array and time declaration {up , right , down , left }
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        int time=0;

        // step 03 : multisource bfs 
        while(!q.empty() && fresh>0)
        {
            int size = q.size();
            
            time++; // each bfs level 

            for(int i=0 ; i<size ; i++)
            {
                pair<int,int> curr = q.front();
                q.pop();

                for(int d=0 ; d<4 ; d++) // perform in 4 directions 
                {
                    int n_row = curr.first + dx[d] ;
                    int n_col = curr.second + dy[d];
                        // and check whether it fulfils the condition : 1. valid element in bounds 2. fresh orange 
                    if(n_row >=0 && n_col >=0 && n_row < n && n_col < m && grid[n_row][n_col] == 1 )
                    {
                        grid[n_row][n_col] = 2 ; //rot it 
                        fresh--; 
                        q.push({n_row , n_col}); // and push in queue
                    }
                }
            }
        } 
        
        //step: 04 at last : if any fresh orange remain return -1 else return time it took
        return fresh==0 ? time : -1; 

    }
};