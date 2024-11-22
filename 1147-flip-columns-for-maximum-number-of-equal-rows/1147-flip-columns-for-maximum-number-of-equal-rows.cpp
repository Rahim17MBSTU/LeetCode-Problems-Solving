class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        map<vector<int>,int>mp;
        int answer = 0 ;
        
        for(int i = 0;i<n;i++){
            vector<int>v;
            for(int j =0;j<m;j++){
                v.push_back(matrix[i][j]);
            }
            mp[v]++;
         }
        
        for(auto u:mp){
            vector<int>v;
            int x = u.second;
            for(auto u1:u.first){
                v.push_back(1-u1);
            }
            x += mp[v];
            answer = max (answer,x);
         }
        
        return answer;
    }
};