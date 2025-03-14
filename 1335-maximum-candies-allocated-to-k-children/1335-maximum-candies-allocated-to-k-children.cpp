class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int ans = 0;
        int low = 1 , high = 1e9;
        auto f = [&](int mid){
            long long cnt = 0;
            for(int i = 0 ; i < candies.size();i++){
                cnt += (candies[i] / mid);
            }
            if(cnt >= k)return 1;
            return 0;
        };
        while(low <= high){
            int mid = (low + high) >> 1;
            
            if(f(mid)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }
};