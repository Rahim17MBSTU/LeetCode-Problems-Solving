class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        nums.push_back(1e9+5);
        int n = nums.size();
        long long ans = 0;
        int i = 0 , j = 0 ;
        int mx = INT_MIN,mn = INT_MAX;
        map<int,int>mp;
        vector<int>v(n+10,0);
        for(;j<n && i<n;){
            mx = max(nums[j],mx);
            mn = min(nums[j],mn);
            if(v[j] ==0){
                mp[nums[j]]++;
                v[j] = 1;
            }
            if(mx - mn <= 2)j++;
            else{
                int value = 0;
                value = j-i;
                ans += value;
                //cout<<"aise = "<<i<<" "<<j<<" "<<value<<endl;
                int x = nums[i];
                //mp[x]--;
                if(x == mx){
                    //cout<<"boro"<<endl;
                    if(mp[x]==1){
                        //cout<<"hooo1\n";
                        mp.erase(x);
                        mx = mp.rbegin()->first;
                    }else{
                        mp[x]--;
                    }
                    
                }else{
                    //cout<<"soto"<<endl;
                    if(mp[x]==1){\
                        //cout<<"hooo2\n";
                        mp.erase(x);
                        mn = mp.begin()->first;
                    }else{
                        mp[x]--;
                    }
                }
                //cout<<mn <<" "<<mx<<endl;
                i++;
                
            }
            
        }
       
        return ans;
        
    }
};