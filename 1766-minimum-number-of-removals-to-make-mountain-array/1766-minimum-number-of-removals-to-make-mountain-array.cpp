class Solution {
public:
    vector<int> FindLongestIncreasingSubsequence(vector<int>&v,bool ok ){
        int n = v.size();
        if(ok == 1) reverse(v.begin(),v.end());
        vector<int>lis,lisen;
        for(int i = 0 ; i < n ; i++){
            int indx = lower_bound(lisen.begin(),lisen.end(),v[i]) - lisen.begin();
            if(indx == lisen.size()){
                lisen.push_back(v[i]);
            }else{
                lisen[indx] = v[i];
            }
            lis.push_back(lisen.size());
        }
        if ( ok == 1)reverse(lis.begin(),lis.end());
        return lis;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int>LIS,LDS;

        LIS = FindLongestIncreasingSubsequence(nums,0);
        LDS = FindLongestIncreasingSubsequence(nums,1);

        for(int i = 0 ; i < LIS.size();i++)
        cout<<LIS[i] << " ";
        cout<<endl;

        for(int i = 0 ; i < LDS.size();i++)cout<<LDS[i] << " ";
        cout<<endl;
        int mxLength = 0;
        int mx = INT_MAX,n=nums.size();
        for(int i = 0 ; i < nums.size();i++){
            if(LIS[i] > 1  && LDS[i] > 1){
                mxLength = max(mxLength, (LIS[i] + LDS[i] - 1));
            }
        }
        return n - mxLength;

        
    }
};