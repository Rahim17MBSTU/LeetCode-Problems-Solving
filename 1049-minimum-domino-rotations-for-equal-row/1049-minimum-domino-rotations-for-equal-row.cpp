class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = 1e9;
        for(int i = 1; i<=6; i++){
            int cnt = 0;
            bool ok = 0;
         
            for(int j = 0;j<tops.size();j++){
                if(tops[j] == i)continue;
                else if(bottoms[j] == i)cnt++;
                else{
                    ok = 1;
                    break;
                }
            }
            if(ok == 0){
                ans = min(ans,cnt);
            }
          
            cnt = 0;
            ok = 0;
            for(int j = 0;j<tops.size();j++){
                if(bottoms[j] == i)continue;
                else if(tops[j] == i)cnt++;
                else{
                    ok = 1;
                    break;
                }
            }
          
            if(ok == 0){
                ans = min(ans,cnt);
            }
        }
        return ans == 1e9 ? -1 : ans;
    }
};