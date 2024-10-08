class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        vector<bool>vis(s.size()+10,0);
        //return s;
        for(int i = 0 ; i < s.size() ; ++i){
            if(s[i] >='a' && s[i] <='z')continue;
            if(st.size() == 0 && (s[i] == ')' || s[i] =='(')){
                st.push({s[i],i});
            }else{
                if(st.top().first == '(' && s[i] ==')'){
                    int indx = st.top().second;
                    vis[indx] = 1;
                    vis[i] = 1;
                    st.pop();
                }else {
                    st.push({s[i],i});
                }
            }
        }
        
        string result = "";
        
        for(int i=0;i<s.size();i++){
            if(s[i] >= 'a' && s[i] <='z')result += s[i];
            else if(vis[i] == 1)result += s[i];
        }
        return result;
    }
};