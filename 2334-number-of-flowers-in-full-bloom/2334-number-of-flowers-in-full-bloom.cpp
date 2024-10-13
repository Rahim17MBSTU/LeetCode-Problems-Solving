class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        set<int>Set ;
        int n = flowers.size();
        int m = people.size();
        for(int i = 0 ; i < n ; i++){
            int start = flowers[i][0];
            int end = flowers[i][1];
            Set.insert(start);
            Set.insert(end);
        }
        for(auto u:people) Set.insert(u);
        int cnt = 1;
        map<int,int>mp;
        for(auto u:Set){
            mp[u] = cnt++;
        }
        vector<int> sweepLine(cnt+5,0);
        for(int i = 0 ; i < n ; i++){
            int start = flowers[i][0];
            int end = flowers[i][1];
            start = mp[start];
            end = mp[end];
            sweepLine[start]++;
            sweepLine[end+1]--;
        }
        for(int i=1;i<=cnt+2;i++){
            sweepLine[i] = sweepLine[i-1] + sweepLine[i];
        }
        vector<int>result;
        for(auto u:people){
            int x = mp[u];
            result.push_back(sweepLine[x]);
        }
        return result;
    }
};