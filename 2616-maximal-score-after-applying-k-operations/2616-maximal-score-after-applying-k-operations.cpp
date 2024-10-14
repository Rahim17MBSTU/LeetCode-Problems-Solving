class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {

        priority_queue<int>pq(nums.begin(),nums.end());
        long long answer = 0;
        
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