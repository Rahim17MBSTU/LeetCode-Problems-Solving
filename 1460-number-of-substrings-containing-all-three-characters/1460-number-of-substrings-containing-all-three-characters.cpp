class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), ans = 0 ;
        int i = 0 , j = 0 ; 
        map<char,int>mp;
        while(j<n){
            while(mp.size() < 3 && j <n){
                mp[s[j]]++;      
                j++;
            }
            while(mp.size() == 3 && i<j){
                mp[s[i]]--;
                if(mp[s[i]] == 0)mp.erase(s[i]);
                i++;
                ans += n-j+1;
            }
        }
        return ans;

    }
};