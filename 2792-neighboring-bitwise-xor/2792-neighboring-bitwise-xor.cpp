class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
       int n = derived.size();
       vector<int>v(n,0);
       int last = derived[0];
       int past = last;
       for(int i = 0 ;i<n;i++){
            if(i!= n-1){
                if(derived[i] == 0){
                    if(last == 0){
                        past = last;
                        last = 0;
                    }else if(last == 1){
                        past = last;
                        last = 1;
                    }
                }else if(derived[i] == 1){
                    if(last == 0){
                        past = last;
                        last = 1;
                    }else if(last == 1){
                        past = last;
                        last = 0;
                    }
                }
            }else{
                if((derived[0] ^ last) == derived[i]){
                    return true;
                }else{
                    return false;
                }
            }
       }
       return true;
    }
};