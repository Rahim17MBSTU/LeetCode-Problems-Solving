class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int>vis(1e6+10,0);
        for(int i = 0;i < intervals.size();i++){
            int x = intervals[i][0];
            int y = intervals[i][1];
            vis[x] += 1;
            vis[y+1] -= 1;

        }
        int minimumNumberGroup = 0 ;
        for(int i=1;i<=1e6;i++){
            vis[i] += vis[i-1];
            minimumNumberGroup = max(minimumNumberGroup,vis[i]);
        }
        return minimumNumberGroup;

        
    }
};