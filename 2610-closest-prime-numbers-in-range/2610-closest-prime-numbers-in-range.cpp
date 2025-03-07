class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int mx = INT_MAX;
        vector<int>prime;
        vector<bool>vis(right+10,0);
        vis[0] = vis[1] = 1;
        for(int i= 2; 1LL*i * i<=right;i++){
            if(vis[i]== 0){
                for(int j = i*i;j<=right;j+=i){
                    vis[j] = 1;
                }
            }
        }
        if(left <= 2)prime.push_back(2);
        for(int i = 3;i<=right;i+=2){
            if(vis[i] == 0 && i>= left)prime.push_back(i);
        }
        vector<int> res ;
        if(prime.size()<2){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        int l ,r;
        for(int i = 0;i<prime.size()-1;i++){
            int x = prime[i+1];
            int y = prime[i];
            if(x-y < mx){
                mx = x-y;
                l = y;
                r = x;
            }
        }
        res.push_back(l);
        res.push_back(r);
        return res;
    }
};