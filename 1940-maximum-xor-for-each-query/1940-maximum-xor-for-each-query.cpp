class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int>Xor(n,0),result;
        Xor[0] = nums[0];
        int mxValue = (1 << maximumBit) - 1;
        for(int i = 1 ; i < n ; i++){
            Xor[i] = Xor[i-1] ^ nums[i];
        }
        
        for(int i = n -1 ; i >= 0;i--){
            result.push_back(mxValue ^ Xor[i]);
        }
        return result;
    }
};