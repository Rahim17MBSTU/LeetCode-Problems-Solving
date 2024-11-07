class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0 , j = s.size()-1;
        
        while(i<=j){
             s[i] = tolower(s[i]);
             s[j] = tolower(s[j]);
            if(s[i] >= 'a'  && s[i] <='z' && s[j] >='a' && s[j]<='z'){
                if(s[i] != s[j])return false;
                i++,j--;
                continue;
            }
            if(s[i] >= '0'  && s[i] <='9' && s[j] >='0' && s[j]<='9'){
                if(s[i] != s[j])return false;
                i++,j--;
                continue;
            }if(s[i] >= '0'  && s[i] <='9' && s[j] >= 'a' && s[j] <='z'){
                return false;
            }
            if(s[i] >= 'a'  && s[i] <='z' && s[j] >= '0' && s[j] <='9'){
                return false;
            }
            if(s[i] >= 'a'  && s[i] <='z'){
                j--;continue;
            }if(s[j] >= '0' && s[j] <='9'){
                i++;continue;
            }if(s[i] >= '0'  && s[i] <='9'){
                j--;continue;
            }if(s[j] >= 'a' && s[j] <='z'){
                i++;continue;
            }
            else 
            i++,j--;
        }
        return true;
    }
};