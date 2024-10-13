class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        
        int n = flowers.size();
        map<int,int>mp;
        for(auto u:people){
            mp[u] = 0;
        }

        for(int i = 0 ; i < n ; i++){
            int start = flowers[i][0];
            int end = flowers[i][1]+1;
            mp[start]++;
            mp[end]--;
        }
        int count = 0;
        for(auto u:mp){
            count += u.second;
            mp[u.first] = count;
        }
        n = people.size();
        vector<int> answer;
        
        for(auto u:people){
          answer.push_back(mp[u]);            
        }
        return answer;
    }
};