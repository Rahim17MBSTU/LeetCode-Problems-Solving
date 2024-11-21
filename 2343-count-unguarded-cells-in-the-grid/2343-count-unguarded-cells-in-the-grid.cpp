class Solution {
public:
    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(n,vector<int>(m,0));
        
        
        for(vector<int>&v : guards){
            int x = v[0];
            int y = v[1];
            grid[x][y] = 1; // gards 
        }
       
        
        for(vector<int>&v : walls){
            int x = v[0];
            int y = v[1];
            grid[x][y] = 2; // walls
        }
       
        for(vector<int>&v : guards){
            int x = v[0];
            int y = v[1];
            int j = x, k = y+1;
            while(k<m){  // right side move
                
                if(grid[j][k] == 2 || grid[j][k] == 1)break;
                grid[j][k] = 3;
                k++;
            } 
            j = x, k = y-1;
            
            while(k>=0 ){ // Left side move
                if(grid[j][k] == 2 || grid[j][k] == 1)break;
                grid[j][k] = 3;
                k--;
            }
            j = x+1, k = y;
            
            while(j < n ){ // up side move
                if(grid[j][k] == 2 || grid[j][k] == 1)break;
                grid[j][k] = 3;
                j++;
            }
            j = x-1, k = y;

            while(j >= 0 ){// down side move
                if(grid[j][k] == 2 || grid[j][k] == 1)break;
                grid[j][k] = 3;
                j--;
            }
        }

        int cnt = 0;
        for(int i = 0 ;i<n;i++){
            for(int j =0 ;j<m;j++){    
                if(grid[i][j] == 0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};