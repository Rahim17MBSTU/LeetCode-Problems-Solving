class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i = 0 , j = 0 ;
        int n = nums.size();
        int sum = 0 , mx = -1e9;
        while(i <= j && j < n){
            sum += nums[j];
            mx = max(mx,sum);
            while(sum < 0 && i < n){
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return mx;
    }
};