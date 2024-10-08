class Solution {
public:
    int minSwaps(string s) {
        string result = "";
        int n = s.size();
        for(int i = 0 ;i < n ;i++){
            if(result.empty()){
                result.push_back(s[i]);
            }else{
                if(result.back() == '[' && s[i] == ']'){
                    result.pop_back();
                }else{
                    result.push_back(s[i]);
                }
            }
        }
        int sz = result.size()/2;
        int answer = sz / 2;  
        if( sz % 2 == 1) answer++;
        
        return answer ; 
    }
};