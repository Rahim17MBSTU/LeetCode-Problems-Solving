class Solution {
public:
    string countOfAtoms(string formula) {
        stack<pair<string,int>>st;
        int n = formula.size();
        stack<int>st1;
        vector<int>v(n);
        int factor = 1;
        for(int i = n-1;i>=0;i--){
            if(formula[i] ==')'){
                int j = i+1;
                string digit="";
                for(;j<n;j++){
                    if(isdigit(formula[j])) digit+=formula[j];
                    else break;
                }
                if(digit =="")digit ="1";
                int x = stoi(digit);
                factor *= x;
                st1.push(x);

            }else if(formula[i] == '(') {
                int digit = st1.top();
                st1.pop();
                factor/= digit;
            }
            v[i] = factor;
        }
        map<string,int>mp;
        for(int i=0;i<n;i++){
            int factor = v[i];
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
                    break;
                 }
               }
               int k = j;
               
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
               mp[ss] += (x*factor);
              
               i = k-1;
              
            }
         }
        
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