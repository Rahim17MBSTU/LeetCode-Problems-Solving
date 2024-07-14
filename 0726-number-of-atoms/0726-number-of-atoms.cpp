class Solution {
public:
    string countOfAtoms(string formula) {
        stack<pair<string,int>>st;
        int n = formula.size();
        for(int i=0;i<n;i++){
            string ss = "";
            if(isupper(formula[i])){
               int j = i+1;
               ss+=formula[i];
               for(;j<n;j++){
                 if(islower(formula[j])){
                    ss += formula[j];
                 }
                 else 
                 {
                    //j--;
                    break;
                 }
               }
               int k = j;
               //cout<<"k ="<<k<<endl;
               string digit = "";
               for(;k<n;k++){
                if(isdigit(formula[k])){
                    digit+=formula[k];
                }else{
                    break;
                }
               }
              
               int x = 1;
               if(digit.size()>=1) x = stoi(digit);
              
               st.push({ss,x});
               i = k-1;
              
            }else if(formula[i] =='('){
                ss+=formula[i];
                st.push({ss,0});
            }else if(formula[i] == ')'){
                
                int j = i + 1;
                string digit = "";
                for(;j<n;j++){
                    if(isdigit(formula[j]))
                    digit+=formula[j];
                    else{
                        break;
                    }

                }
                i = j-1;
                int value = 1;
                if(digit.size()>=1)value *= stoi(digit);
                
                vector<pair<string,int>>vp;
                while(!st.empty()){
                    string d = st.top().first;
                    int k = st.top().second;
                    st.pop();
                    if(d == "(" ) break;
                    else{
                        k *= value;
                        vp.push_back({d,k});
                    }
                    
                }
                while(!vp.empty()){
                    string x = vp.back().first;
                    int y = vp.back().second;
                    vp.pop_back();
                    st.push({x,y});
                }
            }
        }
        map<string,int>mp;
        while(!st.empty()){
            string ss = st.top().first;
            int x = st.top().second;
            st.pop();
            mp[ss] += x; 
        }
        string res = "";
        for(auto u:mp){
            if(u.second > 1){
                res+=u.first+ to_string(u.second);
            }else{
                res+=u.first;
            }
        }
        return res;
    }
};