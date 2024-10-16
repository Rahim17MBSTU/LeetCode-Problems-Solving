class Solution {
public:
    
    string longestDiverseString(int a, int b, int c) {
        string result = "";
        map<char,int>mp;
        if(a!=0)mp['a']+=a;
        if(b!=0)mp['b']+=b;
        if(c!=0)mp['c']+=c;
        int mx = 0;
        char ch ;
        for(auto u:mp){
            if(u.second > mx){
                mx = u.second;
                ch = u.first;
            }
        }
        //cout << mx <<" "<< ch<<endl;
        if(mx >= 1){
            if(mx >=2){
            result += ch;
            result += ch;
            mp[ch] -=2;
            if(mp[ch] == 0)mp.erase(ch);

            }else{

            result += ch;
            //result += ch;
            mp[ch] -=1;
            if(mp[ch] == 0)mp.erase(ch);
            }
        }
       
        while(!mp.empty()){
            bool ok = 0;
            int Max = 0;
            char CH ;
            for(auto u:mp){
                mx = u.second;
                ch = u.first;
                if(result.back()!=ch && Max < mx){
                    Max = mx;
                    CH = ch;  
                }
            }
            if(Max!=0){
                if(Max >= 2){
                    mp[CH]-=2;
                    result += CH;
                    result += CH;
                    ok = 1;
                }else if(Max == 1){
                    result += CH;
                    mp[CH] --;
                    ok = 1;
                }
                if(mp[CH] == 0){
                    mp.erase(CH);
                }
                Max = 0;
            }
            
            if(ok == 0)break;
        }
        if(!mp.empty()){
            while(!mp.empty()){
                bool ok = 0;
            
            for(auto u:mp){
                char ch =  u.first;
                for(int i=0;i<result.size()-1;i++){
                    if(result[i] == result[i+1] && result [i]!= ch ){
                        int cnt = min(2,u.second);
                        mp[ch] -= cnt;
                        if(mp[ch] == 0)mp.erase(ch);
                        result.insert(i+1,cnt,ch);
                        ok = 1;
                        break;
                    }
                }
             }
             if(ok == 0)break;
            }
        }
        
        return result;
        
        
    }
};