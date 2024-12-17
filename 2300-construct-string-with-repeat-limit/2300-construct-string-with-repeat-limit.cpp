class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> v(28,0);
        for(auto u:s) v[u-96]++;
        string res= "";
        
        for(int i = 26;i>=1;){
            int k = repeatLimit;
            while(k--){
                if(v[i] == 0)break;
               
                char ch = (char)i+96;
                res += ch;
                v[i]--;
                
            }
            if(v[i]>=1){
                int j = i ;
                bool ok = 0;
                for(j = i-1;j>=1;j--){
                    if(v[j]>=1){
                        
                        char ch = (char)j+96;
                        res +=ch;
                        v[j]--;
                        ok = 1;
                        break;
                    }
                }
                if(ok == 0){
                    i = j;
                }
               
            }else{
                i--;
            }
        }
        return res;
    }
};