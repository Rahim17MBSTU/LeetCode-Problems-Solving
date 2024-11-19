class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long  answer = 0;
        deque<int>duplicate;
        vector<int> v(1e5+10,0);
        long long sum = 0;
        for(int i = 0 ; i < k ; i++){
            v[nums[i]]++;
            if(v[nums[i]] >= 2)duplicate.push_back(nums[i]);
            sum += nums[i];
        }
        if(duplicate.empty()) answer = max(answer, sum);
        // 1 2 1 1 2 3 4 5 k = 4
        for(int i = 0,j = k  ; j < n;j++,i++){
            v[nums[i]]--;
            sum -= nums[i];
            if(v[nums[i]] >= 1){
                duplicate.pop_front();
            }
            v[nums[j]]++;
            sum += nums[j];
            if(v[nums[j]] >= 2){
                duplicate.push_front(nums[j]);
            }
            if(duplicate.empty()){   
                answer = max(answer,sum);
            }
        }
        return answer;
    }
};