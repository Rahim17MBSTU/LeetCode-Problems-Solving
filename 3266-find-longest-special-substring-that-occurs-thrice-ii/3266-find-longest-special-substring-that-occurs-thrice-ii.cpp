class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        map<pair<char,int>,int>mp;
        char ch = s[0];
        int cnt = 1;
        int ans = -1;
       
        for(int i = 1;i<n;i++ ){
            if(s[i] == ch){
                cnt++;    
            }else{
                
                if(cnt-2>=1)
                ans = max(ans,cnt-2);

                mp[{ch,cnt}]++;
                if(mp[{ch,cnt}]>=3){
                    ans = max(ans,cnt);
                }
                if(cnt-1>=1){
                    mp[{ch,cnt-1}] += 2;
                    if(mp[{ch,cnt-1}]>=3){
                        ans = max(ans,cnt-1);
                    }
                }
                
                ch = s[i];
                cnt = 1;
                
            }
        }
        
        mp[{ch,cnt}]++;
        if(mp[{ch,cnt}]>=3){
            ans  = max(ans,cnt);
        }
        
        if(cnt-2>=1){
                
                ans = max(ans,cnt-2);
                
                mp[{ch,cnt-1}] += 2;
                if(mp[{ch,cnt-1}]>=3){
                    ans = max(ans,cnt-1);
                }
        }
        
        return ans;
    }
};