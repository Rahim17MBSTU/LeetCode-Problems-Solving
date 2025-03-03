class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>Result(nums.size(),0);
        
        int left = 0 , right = nums.size()-1;

        for(int i = 0 , j = nums.size()-1 ; i < nums.size(); i++,j--){
            if(nums[i] < pivot){
                Result[left++] = nums[i];
            }if(nums[j] > pivot){
                Result[right--] = nums[j];
            }
        }
        
        while(left <= right){
            Result[left++] = pivot;
        }
        return Result;
    }
};