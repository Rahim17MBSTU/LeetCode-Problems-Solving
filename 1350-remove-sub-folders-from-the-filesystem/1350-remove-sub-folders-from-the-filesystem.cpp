class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string>v;
        bool ok = 0;
        string res = "";
        for(auto u:folder){
            if(ok == 0){
                ok = 1;
                res = u;//v.push_back(u);
            }else{
                string s = u;
                if(res.size() == u.size()){
                    if(res == u)
                        ;
                    else{
                        
                        v.push_back(res);res = u;

                    }
                    continue;
                }
                int i = 0;
                for(;i<s.size();i++){
                    if(i<res.size() && s[i] != res[i]){
                        v.push_back(res);res= u;break;
                    }
                    if(i<res.size() && s[i] == res[i])continue;
                    if(i>=res.size() && s[i] == '/') break;
                    if(i>=res.size() && s[i] >='a' && s[i] <='z'){
                        v.push_back(res);
                        res = u;
                        break;
                    }
                }

            }
            
        }

        cout<<"res= "<<res<<endl;
        if(v.size()>=1){
            if(v.back() != res)v.push_back(res);
        }else{
            v.push_back(res);
        }
        return v;
    }
};