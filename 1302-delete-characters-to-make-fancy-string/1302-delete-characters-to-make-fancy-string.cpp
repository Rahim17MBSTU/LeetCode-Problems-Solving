class Solution {
public:
    string makeFancyString(string s) {
        string result = "";
        result += s[0];
        int cnt = 1;
        for(int i = 1 ; i < s.size(); i++){
            
            if(s[i] == result.back()){
                cnt++;
                if(cnt <= 2 )
                    result+=s[i];
                
            }else{
                cnt = 1;
                result += s[i];
            }
            
        }
        return result;
    }
};