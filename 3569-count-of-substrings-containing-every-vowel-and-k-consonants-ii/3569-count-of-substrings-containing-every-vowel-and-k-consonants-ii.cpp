class Solution {
public:
    bool isVowel(char &ch)
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')return 1;
        return 0;
    }
    long long countOfSubstrings(string s, int k) {
        int n = s.size();
        long long ans = 0;
        unordered_map<char,int>mp;
        vector<int> v(n,0);
        int LastConsonent = n;
        for(int i = n-1;i>=0;i--){
             
            v[i] = LastConsonent ;
            if(!isVowel(s[i])){
                LastConsonent = i;
            }
        }
       
        int i = 0 , j = 0, Consonent = 0;
        while(j < n){
            char ch = s[j];
            if(isVowel(ch)){
                mp[ch]++;
            }else{
                Consonent++;
            }
            while(Consonent > k){
                char ch = s[i];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0)mp.erase(ch);
                }else{
                    Consonent--;
                }
                i++;
            
            }
            while( i < n && mp.size() == 5 && Consonent == k){
                int indx = v[j];
                ans += indx - j;
                char ch = s[i];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0)mp.erase(ch);
                }else{
                    Consonent--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};