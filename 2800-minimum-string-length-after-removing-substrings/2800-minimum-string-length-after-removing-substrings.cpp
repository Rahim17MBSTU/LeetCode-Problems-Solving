class Solution {
public:
    int minLength(string s) {
        
        string result="";
        
        for(int i = 0 ; i < s.size(); i++){

            if(result.empty()){
                result.push_back(s[i]);
            }else{
                if(result.back() =='A' && s[i] =='B' ){
                    result.pop_back();
                }else if(result.back() =='C' && s[i] =='D'){
                    result.pop_back();
                }else{
                    result.push_back(s[i]);
                }
            }
        }
        return result.size();
    }
};