class Solution {
public:
    bool check(string &s, string &t){
       int j = 0, i = 0 , cnt = 0;
       int n = s.size() ;
       int m = t.size();
        while(j < m && i < n && s[i] == t[j]){
            cnt++;
            j++;
            i++;
        }
        return cnt == m;
    }
    int isPrefixOfWord(string sentence, string searchWord) {
        int Count = 1,n = sentence.size();
        string s = "";
        for(int i = 0 ; i < n;i ++){
            if(sentence[i] == ' '|| i == n-1){
              
                if(i == n-1 && sentence[i]!= ' ') s+=sentence[i];
                if(check(s,searchWord)){

                    return Count;
                }
                Count++;
                s="";
            }
            else s+= sentence[i];
        }
        return -1;
    }
};