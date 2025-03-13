class Solution {
public:
    int q ;
    int n ;
    bool calculation(vector<int>&nums,vector<vector<int>>&queries,int k){
        vector<int>diff(n,0);
        for(int i = 0 ; i < k;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int x = queries[i][2];
            diff[l] += x;
            if(r+1 < n)
            diff[r+1] -= x;
        }
        //cout<<"Mid = "<<k<<" -> \n";
        bool ok = 1;
        for(int i = 0 ;i < n;i++){
            if(i)diff[i] += diff[i-1];
            //cout<<diff[i] <<" ";
            if(nums[i] - diff[i] > 0)ok = 0;
        }
        //cout<< " Ok = "<<ok<<endl;
        return ok;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        q = queries.size();
        n = nums.size();
        bool ok = 0;
        for(int i = 0 ;i < n;i++){
            if(nums[i] > 0){
                ok = 1;
                break;
            }
        }
        if(ok == 0 )return 0;
        int ans = -1;
        int low = 1 , high = q;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(calculation(nums,queries,mid)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};