class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char,int>>st;
        int mx = 0,cnt=0;
        vector<int>v(s.size(),0);
        for(int i=0;i<s.size();i++){
            if(st.empty()){
                if(s[i] == '(')st.push({s[i],i});
                
            }else{
                if(s[i] == ')'){
                    if(st.top().first == '('){
                        int indx = st.top().second;
                        st.pop();
                        v[indx] = 1;
                        v[i] = 1;
                    }
                }else{
                    st.push({s[i],i});
                }
            }
        }
        while(!st.empty()){
            int indx = st.top().second;
            v[indx ] = 0;
            st.pop();
        }
        for(int i=0;i<s.size();i++){
            if(v[i] == 0){
                mx = max(mx,cnt);
                cnt = 0 ;

            }else{
                cnt+=v[i];
            }
        }
        mx = max(mx,cnt);
        return mx;
    }
};