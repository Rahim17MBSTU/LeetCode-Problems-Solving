class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size(),cnt = 0;
        map<int,int>mp;set<int>s(arr.begin(),arr.end());
        for(auto u:s){
            mp[u] = ++cnt;
        }vector<int>res;
        for(auto u:arr){
            res.push_back(mp[u]);
        }
        return res;
    }
};