class Solution {
public:
    bool check(char ch){
        if(ch == 'a' || ch =='e' || ch =='i' || ch =='o' || ch == 'u'){
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size(),indx = 0;
        vector<int> pre(n+1,0),ans;
        for(auto u:words){
            string s = u;
            if(check(s[0])){
                int sz = s.size();
                if(check(s[sz-1])){
                    pre[indx] = 1;
                }
            }
            if(indx > 0){
                pre[indx] += pre[indx-1]; 
            }
            indx++;
        }
        for(int i = 0 ; i<queries.size();i++){
            int x = queries[i][0];
            int y = queries[i][1];
            int res = 0;
            res = pre[y];
            if(x){
                res -= pre[x-1];
            }
            ans.push_back(res);
        }
        return ans;
    }
};