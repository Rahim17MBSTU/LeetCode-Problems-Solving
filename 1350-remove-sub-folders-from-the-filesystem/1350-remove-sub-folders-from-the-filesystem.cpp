class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string>v;
        string res = "";
        for(int i = 0 ;i < folder.size();i++){
            string u = folder[i];
            if(i){
                
                if(res.size() == u.size()){
                    if(res != u){
                        
                        v.push_back(res);res = u;

                    }
                    continue;
                }
                int i = 0;
                for(;i<u.size();i++){
                    if(i<res.size() && u[i] != res[i]){
                        v.push_back(res);res= u;break;
                    }
                    if(i<res.size() && u[i] == res[i])continue;
                    if(i>=res.size() && u[i] == '/') break;
                    if(i>=res.size() && u[i] >='a' && u[i] <='z'){
                        v.push_back(res);
                        res = u;
                        break;
                    }
                }

            }else{
                res= u;
            }
            
        }

        //cout<<"res= "<<res<<endl;
        if(v.size()>=1){
            if(v.back() != res)v.push_back(res);
        }else{
            v.push_back(res);
        }
        return v;
    }
};