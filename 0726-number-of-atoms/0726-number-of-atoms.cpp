class Solution {
public:
    string countOfAtoms(string s) {
        int n = s.size();
        map<string,int>mp;
        multiset<string>ms;
        stack<char>st;
        for(int i=0;i<n;i++){
            char c = s[i];
            if(st.empty()) st.push(c);
            else if(c =='('){
                st.push(c);
            }else if( c == ')'){
                string ss = "",d="",digit = "",res="";
                i++;
                int next_value = 1;
                while(i<n && s[i]>='0' && s[i]<='9'){
                    d+=s[i];
                    i++;
                }
                if(d.size() >= 1){
                    next_value = stoi(d);
                }
                
                while(1){
                    char ch = st.top();
                    st.pop();
                    if(ch == '('){
                        break;
                    }
                    if(ch >='0' && ch <='9'){
                        digit += ch;
                    }else{
                        
                        if(ch >='A' && ch <='Z'){
                            int x = 1;
                            if(digit.size()>=1){
                               reverse(digit.begin(),digit.end());
                               x = stoi(digit); 
                            }
                            x*=next_value;
                            ss += ch;
                            reverse(ss.begin(),ss.end());
                            ss+=to_string(x);
                           
                            res+=ss;
                            
                            ss="";
                            digit="";
                            
                        }else{
                            ss += ch;
                        }
                    }
                    
                }
                i--;
                for(auto u:res){
                    st.push(u);
                }
            }else{
                st.push(c);
            }
        }
        string kk="";
        char ch;
        while(!st.empty()){
            ch = st.top();
           
            st.pop();
            if(ch >='A' && ch <='Z'){
                kk += ch;
                reverse(kk.begin(),kk.end());
               
                ms.insert(kk);
                kk="";
            }else{
                kk += ch;
            }
        }
       
        string ans="";
        for(auto u:ms){
            string k ="",digit="";
            for(auto t:u){
                if(t >='0' && t<='9'){
                    digit+=t;
                }else{
                    k+=t;
                }
            }
           
            int x = 0;
            x+= (digit.size()>=1)?stoi(digit):1;
            mp[k]+=x;
        }
        
        for(auto u:mp){ 
            ans+=u.first+(u.second != 1 ? to_string(u.second):"");
            
        }
        return ans;
    }
};