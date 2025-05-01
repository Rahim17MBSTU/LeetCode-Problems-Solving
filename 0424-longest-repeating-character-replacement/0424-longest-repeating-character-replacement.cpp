class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;
        int low = 1,high = n;
        auto f = [&](int mid){
            vector<int>v(27,0);
            int mx = 0;
            for(int i = 0 ;i <mid;i++){
                v[s[i]-64]++;
                mx = max(mx,v[s[i]-64]);
            }
            int dif = mid - mx;
            if(dif <= k)return true;
            for(int i = 0 , j = mid;j < n ; i++,j++){
                v[s[i]-64]--;
                v[s[j]-64]++;
                mx = 0;
                for(int k = 1;k<=26;k++){
                    mx = max(mx,v[k]);
                }
                int dif = mid - mx;
                if(dif <= k)return true;
                
            }
            return false;
        };
        while(low <= high){
            int mid = (low + high )>>1;
            if(f(mid)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }
};