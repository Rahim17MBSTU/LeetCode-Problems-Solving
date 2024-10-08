class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());

        map<pair<int,pair<int,pair<int,int>>>,int>mp;
        
        vector<vector<int>>vp;

        int n = nums.size();
        
        for(int i = 0 ;i <n-1;i++){
            for(int j = i+1;j<n;j++){
                int k = 0, l = n-1;
                while(k<=l){
                    long long int sum = 0;
                    sum = 0LL +nums[i] + nums[j] + nums[k] + nums[l] ;
                    if(target == sum ){
                        if(i!=j && i != k && i!= l && j != k && j!=l && k!=l){
                            vector<int>v{nums[i],nums[j],nums[k],nums[l]};
                            sort(v.begin(),v.end());
                            if(mp[{v[0],{v[1],{v[2],v[3]}}}] == 0){
                                mp[{v[0],{v[1],{v[2],v[3]}}}] ++;
                                vp.push_back(v);
                            }
                            
                        }
                        k++;
                        l--;

                    }else if(sum > target ){
                        l--;
                    }else{
                        k++;
                    }
                }
            }
        }
        return vp;
    }
};