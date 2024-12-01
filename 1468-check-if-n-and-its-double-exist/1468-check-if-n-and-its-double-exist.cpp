class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto u:arr){
            mp[u]++;
        }
        for(auto u:arr){
            if(u!=0 && mp[2*u]>=1)return true;
            if(u!=0 && u%2 == 0 && mp[u/2] >= 1)return true;
            if(u == 0 && mp[0]>=2)return true;
        }
        return false;
    }
};