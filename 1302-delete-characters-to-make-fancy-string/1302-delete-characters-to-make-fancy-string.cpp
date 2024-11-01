class Solution {
public:
    string makeFancyString(string s) {
        string result = "";
        int cnt = 0;
        for(int i = 0 ; i < s.size(); i++){
            if(i){
                if(s[i] == result.back()){
                    cnt++;
                    result+=s[i];
                }else{
                    cnt = 1;
                    result += s[i];
                }
                if(cnt >= 3){
                    cnt--;
                    result.pop_back();
                }
            }else{
                result += s[i];
                cnt++;
            }
        }
        return result;
    }
};