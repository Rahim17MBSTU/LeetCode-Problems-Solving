public class Solution {
    public int NumberOfSubstrings(string s) {
        int n = s.Length;
        int ans = 0 ;
        Dictionary<char,int> mp = new Dictionary<char,int>();
        int i = 0 , j = 0;
        while(j<n){
            while(mp.Count < 3 && j < n ){
                if(mp.ContainsKey(s[j])){
                    mp[s[j]]++;
                }else{
                    mp[s[j]] = 1;
                }
                j++;
            }
            while(mp.Count == 3 && i < j){
                ans += (n - j + 1);
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.Remove(s[i]);
                }
                i++;
            }
        } 
        return ans;
    }
}