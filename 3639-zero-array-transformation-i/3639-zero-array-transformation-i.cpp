class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>fre(n+2,0);
        for(auto u:queries){
            int x = u[0];
            int y = u[1];
            fre[x] += 1;
            fre[y+1] -= 1;

        }
        bool result = true;
        for(int i = 0; i <n ;i++){
            if(i) fre[i] += fre[i-1];
            if(nums[i] - fre[i] > 0){
                result = false;break;
            }
        }
        return result;
    }
};