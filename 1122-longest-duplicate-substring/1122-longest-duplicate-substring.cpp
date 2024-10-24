class Solution { 
    
public:

    //#define int long long 
     static const int N = 1e6+10 ;
     static const int p1 = 137, p2 = 277 , mod1 = 127657753 , mod2 = 987654319;
     pair<int,int>pw[N],ipw[N];
    int ip1, ip2;
    int bigmod(int base ,int power ,int mod){
    int res = 1;
    while(power != 0){
        if(power % 2  == 0){
            base = 1LL * base * base  % mod;
            power/=2;
        }else{
            res = 1LL * base * res % mod;
            power--;
        }
    }
    return res;
}
void prec(){
    pw[0] = {1,1};
    for(int i = 1; i < N ;i++){
        pw[i].first = 1LL * p1 * pw[i-1].first % mod1;
        pw[i].second = 1LL * p2 * pw[i-1].second % mod2;
    }
    ip1 = bigmod(p1,mod1-2,mod1);
    ip2 = bigmod(p2,mod2-2,mod2);
    ipw[0] ={1,1};
    for(int i = 1; i < N ;i++){
        ipw[i].first = 1LL * ip1 * ipw[i-1].first % mod1;
        ipw[i].second = 1LL * ip2 * ipw[i-1].second % mod2;
    }
}
pair<int,int> string_hash(string s){
    int n = s.size();
    pair<int,int>hs({0,0});
    for(int i = 0 ; i < n ;i++){
        hs.first += (1LL * s[i] * pw[i].first) % mod1;
        hs.first %= mod1;
        hs.second += (1LL * s[i] * pw[i].second ) % mod2;
        hs.second %= mod2;
    }
    return hs;

}
pair<int,int>pref[N];
        void calculate(string s){
        int n = s.size();
        for(int i = 0 ; i < n ;i++){
                pref[i].first = 1LL * s[i] * pw[i].first % mod1;
                if(i) pref[i].first = (pref[i].first + pref[i-1].first ) % mod1;
                pref[i].second = 1LL * s[i] * pw[i].second % mod2;
                if(i) pref[i].second = (pref[i].second + pref[i-1].second ) % mod2;
        }
        }
    pair<int,int> get_hash(int i,int j){
        assert(i <= j);
        pair<int,int> hs({0,0});//pref[j];
        hs.first = pref[j].first;
        hs.second = pref[j].second;
        if(i) hs.first = (hs.first - pref[i-1].first  + mod1) % mod1;
        hs.first = 1LL * hs.first * ipw[i].first % mod1;
        if(i) hs.second = (hs.second - pref[i-1].second  + mod2 ) % mod2;
        hs.second = 1LL * hs.second *ipw[i].second % mod2;
        return hs;

    }
    
    string longestDupSubstring(string s) {
        prec();
        calculate(s);
        int n = s.size();
        int low = 1, high = s.size();
        int ans = - 1, x1 = 0 , x2 = 0;
        string res = "";
        while(low<=high){
            int mid = (low + high) >> 1;
            map<pair<int,int>,int>mp;bool ok = 0;
            for(int i = 0 ;i+mid-1 < n;i++){
                auto hs1 = get_hash(i,i+mid-1);
                mp[hs1]++;
                if(mp[hs1]>=2){
                    cout<<"aise1 ="<< i<<" "<<i+mid-1<<endl;
                    
                    x1 = i;
                    x2 = i+mid-1;
                    //cout<<res<<endl;
                    //x1= i;
                    //x2 = i+mid-1;
                    ok = 1;
                }
            }
            if(ok){
                //cout<<"aise = "<<mid<<endl;
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
            
        }
        
        if(ans == -1){
            return res;
        }
        for(int i=x1;i<=x2;i++)res+=s[i];
        return res;
        
    }
};