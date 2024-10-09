class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minimumAnswer  = target,minimum = INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i = 0 ;i < nums.size();i++){
            cout << nums[i]<<" ";
        }
        cout <<endl;
        for(int i = 0 ; i < nums.size()-2; i++){
            int j = i + 1, k = nums.size() - 1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum <= target){
                    int x = abs(target-sum);
                    if(x<minimum){
                        minimum = x;
                        minimumAnswer = sum;
                    }
                    j++;
                }else{
                    int x = abs(target-sum);
                    if(x<minimum){
                        minimum = x;
                        minimumAnswer = sum;
                    }
                    k--;
                }
            }
        }
        return minimumAnswer;
    }
};