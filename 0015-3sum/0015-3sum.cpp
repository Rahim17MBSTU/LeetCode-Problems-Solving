class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        
        set<vector<int>>vp;
        
        
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            int target = nums[i] * (-1);
            int j = 1 , k = n-1;
            bool ok = 0;
            while(j<=k){
                int sum = nums[j] + nums[k];
                if(i != j && i!=k && j!=k && sum == target){
                    vector<int>v{nums[i],nums[j],nums[k]};
                    sort(v.begin(),v.end());
                    vp.insert(v);
                    j++;
                    k--;
                }
                else if(sum > target ){
                    k--;
                }else{
                    j++;
                }
            }
            
        }
        vector<vector<int>> res(vp.begin(),vp.end());
        return res;
    }
};