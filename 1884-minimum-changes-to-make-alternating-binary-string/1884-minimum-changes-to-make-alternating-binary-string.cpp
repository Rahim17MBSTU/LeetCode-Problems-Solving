class Solution {
public:
    int minOperations(string s) {
        int ans=0;
        int n = s.size();
        string t = "",t1 = "";
        for(int i = 0 ;i <n;i++){
            if(i%2)t+='0',t1+='1';
            else t+='1',t1+='0';
        }
        int cnt1 = 0,cnt2 =0;
        for(int i = 0 ;i<n;i++){
            if(s[i] != t[i])cnt1++;
            if(s[i] != t1[i])cnt2++;
        }
        
        return min(cnt1,cnt2);
    }
};