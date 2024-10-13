class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        vector<int>start(n,0),end(n,0);
        
        for(int i = 0 ; i < n;i++){
            int st = flowers[i][0];
            int ed = flowers[i][1];
            start.push_back(st);
            end.push_back(ed);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        vector<int>result ;
        for(auto u:people){
            int x = upper_bound(start.begin(),start.end(),u)-start.begin();
            int y = lower_bound(end.begin(),end.end(),u)-end.begin();
            result.push_back(x-y);
        }
        return result;
    }
};