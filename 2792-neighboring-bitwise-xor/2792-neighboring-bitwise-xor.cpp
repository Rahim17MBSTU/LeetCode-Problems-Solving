class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int ans = 0;
        for(auto u:derived) ans ^= u;
        return ans == 0 ? 1 : 0; 
    }
};