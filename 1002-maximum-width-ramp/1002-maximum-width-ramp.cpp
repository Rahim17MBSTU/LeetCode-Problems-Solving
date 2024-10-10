class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
       stack<int>st;
       for(int i = 0 ; i < nums.size();i++){
         if(st.empty())st.push(i);
         else{
            if(nums[st.top()] > nums[i]){
                st.push(i);
            }
         }
       }
    
       int mx = 0 ; 
       for(int i = nums.size() - 1; i >= 0 ; i--){
           
            while(!st.empty() && nums[st.top()] <= nums[i]){
                mx = max(mx,i - st.top());st.pop();
            }
            if(st.empty())break;
       }
       return mx;
    }
};