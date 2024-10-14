class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq(piles.begin(),piles.end());
        while(k--){
            int value = pq.top();
            value = ceil(value / 2.0);
            pq.pop();
            pq.push(value);
        }
        long long answer = 0;
        while(!pq.empty()){
            answer += pq.top();
            pq.pop();
        }
        return answer;
    }
};