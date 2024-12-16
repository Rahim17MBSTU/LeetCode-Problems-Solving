//#define P pair<int,int>
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int> ,vector<pair<int,int>> , greater<pair<int,int>>> pq;
        int n = nums.size();
        for(int i = 0 ; i < n; i++){
            pq.push({nums[i],i});
        }
        while(k--){
            int indx = pq.top().second;
            int value = pq.top().first;
            pq.pop();
            value *= multiplier;
            pq.push({value , indx});
        }
        vector<int>answer(n);
        while(!pq.empty()){
            int indx = pq.top().second;
            int value = pq.top().first;
            pq.pop();
            answer[indx] = value;

        }
        return answer;
    }
};