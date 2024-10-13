class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        for(int i=0;i<nums.size();i++){
            reverse(nums[i].begin(),nums[i].end());
        }
        vector<int>v;
        int x1,x2,value = INT_MAX;
        bool ok =1 ;
        while(ok){
            int mnIndex = 0;
            int mn = INT_MAX;
            int mx = INT_MIN;
            for(int i=0;i<nums.size();i++){
                if(mn > nums[i].back()){
                    mn = nums[i].back();
                    mnIndex = i;
                }
                mx = max(mx,nums[i].back());
            }
            //cout<<mn<<" "<<mx<< " "<<mnIndex<<endl;
            nums[mnIndex].pop_back();
            if(nums[mnIndex].empty())ok = 0;
            if(mx - mn < value){
                
                value = mx - mn;
                x1 = mn;
                x2 = mx;
            }
        
            
        }
        v.push_back(x1);
        v.push_back(x2);
        return v;
    }
};