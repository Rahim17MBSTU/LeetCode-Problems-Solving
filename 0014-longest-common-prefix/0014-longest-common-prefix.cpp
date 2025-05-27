class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int mn = 1000;
        for(auto u:strs){
            int x = u.size();
            mn = min(mn,x);
        }
        string res="";
        for(int col = 0 ;col <mn;col++){
            char ch = strs[0][col];
            int cnt = 0 ;
            for(int row = 0;row <n;row++){
                if(ch == strs[row][col])cnt++;
            }
            if(cnt == n){
                res += ch;
            }else{
                break;
            }
            
        }
        return res;
    }
};