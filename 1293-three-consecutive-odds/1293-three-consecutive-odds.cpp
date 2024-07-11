class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        for(auto u:arr){
            if(u % 2 == 1){
                cnt++;
            }else{
                cnt = 0;
            }
            if(cnt >= 3) return 1;
        }
        return 0;
    }
};