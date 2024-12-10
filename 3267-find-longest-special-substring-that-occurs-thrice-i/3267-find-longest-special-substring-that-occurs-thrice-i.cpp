class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int  low = 0, ans = -1 , high = n-1;
        auto f = [&](int mid){
            vector<int>fre(29,0);
            map<string,int>mp;
            string t = "";
            for(int i = 0 ;i <= mid;i++){
                
                t +=s[i];fre[s[i] - 96]++;  
                if(fre[s[i]-96] == mid + 1) {
                    mp[t]++;
                } 
            }
            for(int i = 0 , j = mid + 1; j < n ;j++,i++){
                t += s[j];
                reverse(t.begin(),t.end());
                t.pop_back();
                reverse(t.begin(),t.end());
                fre[s[i]-96]--;
                fre[s[j]-96]++;
                for(int k=1;k<=26;k++){
                    if(fre[k] == mid+1){
                        mp[t]++;
                        if(mp[t]>=3){
                            return true;
                        }
                    }
                } 
            }
            return false;
        };
        while(low <= high){
            int mid = (low + high) >> 1;
            if(f(mid)){
                ans = mid+1;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }
};