class Solution {
public:
    bool isIsomorphic(string s, string t) {
       unordered_map<char,int>mp;
       for(int i = 0;i<t.size();i++){
        if(mp[t[i]] == 0){
            mp[t[i]] = s[i] - 96;
        }else{
            if( mp[t[i]] != s[i]-96) {
                return false;
            }else{
                continue;
            }
         }
       } unordered_map<char,int>mp1;
       for(int i = 0;i<t.size();i++){
        if(mp1[s[i]] == 0){
            mp1[s[i]] = t[i] - 96;
        }else{
            if( mp1[s[i]] != t[i]-96) {
                return false;
            }else{
                continue;
            }
         }
       } 
       return true;
    }
};