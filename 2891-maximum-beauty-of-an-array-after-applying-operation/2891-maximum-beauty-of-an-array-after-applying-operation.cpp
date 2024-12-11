class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(),nums.end()) + k + 2;
        vector<int>v(mx,0);
        for(int i = 0 ; i< nums.size();i++){
            int lowRange = nums[i] - k;
            int HighRange = nums[i] + k;
            if(lowRange < 0){
                v[0] += 1;
            }else{
                v[lowRange] += 1;
            }
            
            v[HighRange+1] -= 1; 
        }
        
        int ans = 0 ;
        for(int i = 0;i<mx;i++){
            if(i){
                v[i] = v[i-1] + v[i];
            }
            ans = max(ans,v[i]);            
        }
        return ans;
    }
};