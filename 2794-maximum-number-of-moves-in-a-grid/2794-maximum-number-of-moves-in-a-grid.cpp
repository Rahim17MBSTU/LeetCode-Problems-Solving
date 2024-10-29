class Solution {
public:
    int solve(int i,int j ,vector<vector<int>>&grid,int last,vector<vector<int>>&dp){
        int n = grid.size();
        int m = grid[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m || last >= grid[i][j]) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int x = 1 + solve(i-1,j+1,grid,grid[i][j],dp);
        int y = 1 + solve(i,j+1,grid,grid[i][j],dp);
        int z = 1 + solve(i+1,j+1,grid,grid[i][j],dp);
        return dp[i][j] = max({x,y,z});
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mx = 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i = 0; i<n;i++){
            mx = max(mx,solve(i,0,grid,0,dp));//<<endl;
        }
        return mx-1;
    }
};