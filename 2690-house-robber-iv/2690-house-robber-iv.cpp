class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int low = 1,high = *max_element(nums.begin(),nums.end());
        int ans = high;
        auto f = [&](int mid){
            int cnt = 0;
            for(int i = 0 ; i< nums.size();i++){
                if(nums[i] <= mid){
                    i++;
                    cnt++;
                }
            }
            return cnt >= k;
        };
        while(low <= high){
            int mid = (low + high) >> 1;
            if(f(mid)){
                ans = mid;
                high = mid -1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};