class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {

        priority_queue<int>pq(nums.begin(),nums.end()); // heapify use time complexity O(n)
        long long answer = 0;
        
        while(k>=1 && !pq.empty()){

            int value = pq.top(); // O(1)
            
            pq.pop(); //O(log(n))
            answer += value;
            value = ceil((double)value/3.0);
            pq.push(value); // O(log(n))
            k--;


        }

        return answer;
    }
};