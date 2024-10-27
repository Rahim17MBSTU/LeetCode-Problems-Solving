class Solution {
public:
    int n , m ;
    int solve(int i , int j , vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i >= n || j >= m || grid[i][j] == 0 )return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int right = solve(i,j+1,grid,dp);
        int diagonal = solve(i+1,j+1,grid,dp);
        int bottom = solve(i+1,j,grid,dp);
        return dp[i][j] = 1+min({right,diagonal,bottom});
    }
    int countSquares(vector<vector<int>>& grid) {
        int answer  = 0;
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    answer += solve(i,j,grid,dp);
                }
            }
        }
        return answer ;
    }
};