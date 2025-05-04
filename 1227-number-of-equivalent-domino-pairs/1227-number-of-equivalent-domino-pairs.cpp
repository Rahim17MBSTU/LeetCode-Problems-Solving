class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int,int>mp;
        for(int i = 0 ;i < dominoes.size();i++){
            int x = dominoes[i][0];
            int y = dominoes[i][1];
            int z = min(x,y) * 10 + max(x,y);
            mp[z]++;
        }
        int ans = 0;
        for(auto u:mp){
            int x = u.second;
            x = ( x*(x-1))/2;
            ans += x;
        }
        return ans;
    }
};