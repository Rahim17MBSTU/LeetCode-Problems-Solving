class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        long long int sum = 0,n = nums.size();
        deque<pair<long long int,int>> dq;
        int res = INT_MAX;
        for(int i = 0 ;i<n;i++){
            sum += nums[i];
            if(sum >= k){
                res = min(res,i + 1);
            }
            while(!dq.empty() && sum - dq.front().first >=k ){
                auto it = dq.front();
                dq.pop_front();
                res = min(res, i - (it.second));
            }
            while(!dq.empty() && dq.back().first > sum ){
                dq.pop_back();
            }
            dq.push_back({sum,i});
        }
        return res == INT_MAX ? - 1 : res ;

    }
};