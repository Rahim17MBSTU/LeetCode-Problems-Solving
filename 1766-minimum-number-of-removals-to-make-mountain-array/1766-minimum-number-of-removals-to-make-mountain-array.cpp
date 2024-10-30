class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int>LIS(n,1),LDS(n,1);
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < i ;j ++){
                if(nums[j] < nums[i]){
                    LIS[i] = max(LIS[i] ,LIS[j]+1); 
                }
            }
        }
        
        for(int i = n-1;i>=0;i--){
            for(int j = n-1;j>i;j--){
                if(nums[j] < nums[i]){
                    LDS[i] = max(LDS[i],LDS[j]+1);
                }
            }
        }
        for(int i = 0 ; i < n; i++)cout << LIS[i] << " ";
        cout<<endl;
        for(int i = 0 ; i < n; i++)cout << LDS[i] << " ";
        cout<<endl;
        int mx = INT_MAX;
        for(int i = 1; i < n-1 ; i++){
            int len1 = i+1;
            int len2 = n - i;
            int x1 = len1 - LIS[i];
            int x2 = len2 - LDS[i];
            cout<<x1<<" "<<x2<<endl;
            if(LIS[i] > 1 && LDS[i] >1)
            mx = min(mx,x1 + x2);
        }
        return mx;
    }
};