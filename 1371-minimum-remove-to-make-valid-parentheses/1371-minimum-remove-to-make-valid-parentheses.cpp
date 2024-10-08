class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        vector<bool>vis(s.size(),0);
     
        for(int i = 0 ; i < s.size() ; ++i){

            if(s[i] >='a' && s[i] <='z'){
                vis[i] = 1;continue;
            }

            if(st.empty() && (s[i] == ')' || s[i] =='(')){

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
            
             if(vis[i] == 1)result += s[i];
        
        }
        return result;
    }
};