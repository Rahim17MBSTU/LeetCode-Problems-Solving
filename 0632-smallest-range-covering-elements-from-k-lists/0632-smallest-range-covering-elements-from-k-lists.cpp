class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        for(int i = 0 ; i< n;i ++){
            reverse(nums[i].begin(),nums[i].end());
        }
        int mx = INT_MIN,value = INT_MAX;
        priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i = 0 ;i < n; i++){
            int x = nums[i].back();
            mx = max(x,mx);
            nums[i].pop_back();
            pq.push({x,i});
        }
        int answer1 , answer2 = 0;
        while(true){
            int x = pq.top().first;
            int indx = pq.top().second;
            pq.pop();
            if(mx - x < value){
                value = mx - x;
                answer1 = x;
                answer2 = mx;
            }
            if(nums[indx].empty())break;
            int x1 = nums[indx].back();
            nums[indx].pop_back();
            pq.push({x1,indx});
            mx = max(mx,x1);
        }
        vector<int>v{answer1,answer2};
        return v;
    }
};