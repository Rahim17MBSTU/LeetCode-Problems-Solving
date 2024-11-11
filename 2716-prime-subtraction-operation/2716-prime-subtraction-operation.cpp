class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        vector<int>prime;
        vector<bool>vis(1005,0);
        for(int i = 2;i*i<=1000;i++){
            if(vis[i] == 0){
                for(int j = i*i;j<=1000;j += i){
                    vis[j] = 1;
                }
            }
            
        }
        for(int i = 2;i<=1000;i++){
            if(vis[i]==0){
                prime.push_back(i);
            }
        }
        

        for(int i = 0 ; i < n ; i++){
            for(int j = prime.size()-1 ; j >=0;j--){
                if(prime[j] > nums[i])continue;
                else if( i == 0 && prime[j] < nums[i]){
                    nums[i] -= prime[j];
                    break;
                }
                else if(i-1 >=0 && prime[j] < nums[i] && nums[i-1] < nums[i] - prime[j]){
                    nums[i] -= prime[j];
                    break;
                }
            }
        }
        
        for(int i = 1;i<n;i++)if(nums[i]<=nums[i-1]) return false;
        
        return true;
    }
};