class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        long long answer = 0;
        for(auto u:nums) pq.push(u);
        while(k>=1 && !pq.empty()){
            int value = pq.top();
            pq.pop();
            answer += value;
            value = ceil((double)value/3.0);
            pq.push(value);
            k--;
        }
        return answer;
    }
};