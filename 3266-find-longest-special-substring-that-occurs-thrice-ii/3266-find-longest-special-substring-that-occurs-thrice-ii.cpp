class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int low = 0 , high = n-1;
        
        int ans = -1;
        auto check = [&](int mid,vector<int>&fre){
            for(int i=1;i<=26;i++){
                if(fre[i] == mid+1) return true;
            }
            return false;
        };
        auto f = [&] (int mid){
            vector<int>fre(28,0);
            map<pair<char,int>,int>mp;
            for(int i = 0 ; i <= mid;i++){
                fre[s[i] - 96]++;
            }
            char ch = s[0];
            if(check(mid,fre)){
                mp[{ch,mid}]++;
            }
            for(int i = 0, j = mid+ 1;j<n;j++,i++){
                
                fre[s[i]-96]--;
                fre[s[j]-96]++;
                ch  = s[j];
                if(check(mid,fre)){
                    mp[{ch,mid}]++;
                    if(mp[{ch,mid}]>=3){
                        return true;
                    }
                }
            }
            return false;
        };
        while(low <= high){
            int mid = (low + high) >> 1;
            if(f(mid)){
                low = mid + 1;
                ans = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }
};