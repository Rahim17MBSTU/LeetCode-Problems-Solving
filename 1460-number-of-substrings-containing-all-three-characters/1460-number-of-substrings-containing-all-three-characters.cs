public class Solution {
    public bool size(ref List<int>v){
        return v[0] >= 1 && v[1] >= 1 && v[2] >= 1;
    }
    public int NumberOfSubstrings(string s) {
        int n = s.Length;
        int ans = 0 ;
        List<int> v = new List<int>{0,0,0};
        int i = 0 , j = 0;
        while(j<n){
            while(!size(ref v) && j < n ){
                v[s[j]-97]++;
                j++;
            }
            while(size(ref v) && i < j){
                ans += (n - j + 1);
                v[s[i]-97]--;
                i++;
            }
        } 
        return ans;
    }
}