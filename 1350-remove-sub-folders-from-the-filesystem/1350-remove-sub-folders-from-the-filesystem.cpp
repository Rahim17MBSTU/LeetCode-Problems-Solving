class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string>v;
        string prev = "";
        for(auto u:folder){
            if(prev.empty() || u.compare(0,prev.size(),prev) != 0 || u[prev.size()]!='/'){
                v.push_back(u);
                prev = u;
            }            
            
        }

      
       
        return v;
    }
};