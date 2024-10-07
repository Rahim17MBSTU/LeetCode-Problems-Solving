class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        map<pair<int,pair<int,int>>,int>mp;
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int target = nums[i] * (-1);
            int j = 0 , k = n-1;
            bool ok = 0;
            while(j<=k){
                int sum = nums[j] + nums[k];
                if(i != j && i!=k && j!=k && sum == target){
                    vector<int>v{nums[i],nums[j],nums[k]};
                    sort(v.begin(),v.end());
                    int first = v[0], second= v[1] , third = v[2];
                    if(mp[{first,{second, third} }] == 0){
                        //cout<<"aise = "<<i<<" "<<j<< " "<<k<<endl;
                        //vector<int>vv {nums[v[0]],nums[v[1]],nums[v[2]]};
                        res.push_back(v);
                        mp[{first,{second, third} }]++;
                        //ok  = 1 ;
                    }
                    j++;
                    k--;
                    //if(ok == 1)
                    //break;
                }
                else if(sum > target ){
                    k--;
                }else{
                    j++;
                }
            }
            
        }
        return res;
    }
};