class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
       int n = derived.size();
       vector<int>v(n,0);
       v[0] = derived[0];
       for(int i = 0 ;i<n;i++){
            if(i!= n-1){
                if(derived[i] == 0){
                    if(v[i] == 0){
                        v[i+1] = 0;
                    }else if(v[i] == 1){
                        v[i+1] = 1;
                    }
                }else if(derived[i] == 1){
                    if(v[i] == 0){
                        v[i+1] = 1;
                    }else if(v[i] == 1){
                        v[i+1] = 0;
                    }
                }
            }else{
                if((v[0] ^ v[i]) == derived[i]){
                    return true;
                }else{
                    return false;
                }
            }
       }
       return true;
    }
};