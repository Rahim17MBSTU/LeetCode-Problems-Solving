class Solution {
public:
    int maxChunksToSorted(vector<int>& nums) {
        int NumberOfSplite = 0 ;
        int n = nums.size();
        int ans = 0;
        set<int>s;
        for(int i = 0 ; i <n;i++){
            s.insert(nums[i]);
            if((*s.rbegin()) == i){
               
                ans++;
                s.clear();
            }
        }
        return ans;
    }
};