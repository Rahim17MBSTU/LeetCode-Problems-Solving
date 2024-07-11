class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        for(auto u:s){
            if(u == ')'){
                string temp = "";
                while(1){
                    char c = st.top();
                    st.pop();
                    if(c == '(')break;
                    temp+=c;
                }cout<<temp<<endl;
                
                for(auto v:temp){
                    st.push(v);
                }
            }else{
                st.push(u);
            }
        }
        s = "";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }reverse(s.begin(),s.end());
        return s;
    }
};