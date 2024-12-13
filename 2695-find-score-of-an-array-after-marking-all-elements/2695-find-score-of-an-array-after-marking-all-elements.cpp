class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long  sum = 0 ;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<bool> vis(1e6+10,0);
        for(int i = 0 ; i < nums.size(); i++){
            pq.push({nums[i],i});
        }
        while(!pq.empty()){
            int indx = pq.top().second;
            int value = pq.top().first;
            pq.pop();
            if(vis[indx] == 1)continue;
            if(vis[indx] == 0) sum += value;
            vis[indx ] = 1;
            if(indx == 0){
                vis[indx+1] = 1;
                continue;
            }else if(indx == nums.size()-1){
                vis[indx-1] = 1;
                continue;
            }
            
            vis[indx-1] = 1;
            vis[indx+1] = 1;

        }
        return sum;
    }
};