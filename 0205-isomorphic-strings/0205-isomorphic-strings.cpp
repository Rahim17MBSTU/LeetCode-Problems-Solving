class Solution {
public:
    bool isIsomorphic(string s, string t) {
       vector<int>mp(130,0);
       for(int i = 0;i<t.size();i++){
        if(mp[t[i]] == 0){
            mp[t[i]] = s[i];
        }else{
            if( mp[t[i]] != s[i]) {
                return false;
            }else{
                continue;
            }
         }
       } 
       vector<int>mp1(130,0);
       for(int i = 0;i<t.size();i++){
        if(mp1[s[i]] == 0){
            mp1[s[i]] = t[i] ;
        }else{
            if( mp1[s[i]] != t[i]) {
                return false;
            }else{
                continue;
            }
         }
       } 
       return true;
    }
};