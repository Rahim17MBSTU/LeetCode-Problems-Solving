class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        
        int mx = INT_MIN;
        int mn = INT_MAX;
        for(int i=0;i<intervals.size();i++){
            int x = intervals[i][0];
            
            int y = intervals[i][1];
            mx = max(mx,y);
            mn = min(mn,x);
        }
        vector<int>vis(mx+10,0);
        for(int i = 0;i < intervals.size();i++){
            
            int x = intervals[i][0];
            
            int y = intervals[i][1];
            
            vis[x] += 1;
            
            vis[y+1] -= 1;

        
        }
        int minimumNumberGroup = INT_MIN;
        for(int i=mn;i<=mx;i++){

            vis[i] +=vis[i-1];
            minimumNumberGroup = max(minimumNumberGroup , vis[i]);
        }
        
        
        
        return minimumNumberGroup;

        
    }
};