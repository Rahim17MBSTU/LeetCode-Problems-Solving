class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>v(n,0),res;
        for(auto u:edges){
            int x = u[0];
            int y = u[1];
            v[y]++;
        }
        
        for(int i=0;i<n;i++){
            if(v[i] == 0)res.push_back(i);
        }
        return res;
    }
};