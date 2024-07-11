class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int>v(n,0);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i] == '(')st.push(i);
            else if(s[i] ==')'){
                int x = st.top();st.pop();
                v[i] = x;
                v[x] = i;
            }

        }
        string res = "";
        int i = 0,dir = 1;
        while(i<n){
            if(s[i] =='(' || s[i] ==')'){
                i = v[i] ;
                dir = -1 * dir;
                
            }else{
                res+=s[i];

            }
            i+=dir;
        }
        return res;
    }
};