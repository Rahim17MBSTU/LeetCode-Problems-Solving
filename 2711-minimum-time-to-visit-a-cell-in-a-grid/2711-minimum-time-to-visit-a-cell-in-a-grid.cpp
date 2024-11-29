class Solution {
public:
    #define P pair<int,pair<int,int>>
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1] > 1 && grid[1][0] > 1)return -1;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        priority_queue<P,vector<P> ,greater<P>>pq;
        pq.push({0,{0,0}});
        vis[0][0] = 1;
        int answer = -1;
        while(!pq.empty()){
            int time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
        
            if(row == n-1 && col == m-1){
                return time;
            } 
           
            for(int i = 0 ;i < 4;i++){
                int x = dx[i] + row;
                int y = dy[i] + col;
                if(x >= 0 && y >= 0 && x < n && y < m && !vis[x][y] ){
                    if(time + 1 >= grid[x][y]){
                        pq.push({time+1,{x,y}});
                    }else{
                        if((grid[x][y] - time ) % 2 == 0){
                            pq.push({grid[x][y] + 1,{x,y}});
                        }else{
                            pq.push({grid[x][y] ,{x,y}});
                        }
                    }
                    vis[x][y] = 1;
                    
                }
            }
        }
        return -1;
        
    }
};