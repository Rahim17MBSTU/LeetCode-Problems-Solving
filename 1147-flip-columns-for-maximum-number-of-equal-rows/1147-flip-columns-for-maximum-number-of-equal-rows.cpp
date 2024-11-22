class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        unordered_map<string ,int>mp;
        for(int i = 0;i<n;i++){
            string s ="S";
            for(int j=1;j<m;j++){
                if(matrix[i][j] == matrix[i][j-1]) s +='S';
                else s+='D';
            }
            mp[s]++;
            ans = max(mp[s],ans);
        }
        return ans;
    }
};