class Solution {
public:
    int minOperations(vector<int>& v) {
        int n = v.size();
        int ans = 0,gd = v[0], one = 0;
        for(auto u:v){
            gd = __gcd(u,gd);
            if(u == 1) one++;
        }
        if(gd >= 2){
            return -1;
        }if(one>=1){
            return n-one;
        }
        int mx = INT_MAX;
        for(int i=0;i<n;i++){
            int cnt = 0,gd = v[i];
            for(int j=i+1;j<n;j++){
                gd=__gcd(gd,v[j]);
                if(gd == 1){
                    mx = min(mx,cnt);
                    break;
                }
                cnt++;
            }
        }
        return n+mx;

    }
};