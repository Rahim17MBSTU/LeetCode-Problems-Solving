class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long int pre[n];
        for(int i = 0 ;i <n;i++){
            pre[i] = nums[i];
            if(i) pre[i] += pre[i-1];
        }
        int cnt = 0;
        for(int i = 0 ;i <n-1;i++){
            if(pre[i] >= pre[n-1] - pre[i]) cnt++;
        }
        return cnt;
    }
};