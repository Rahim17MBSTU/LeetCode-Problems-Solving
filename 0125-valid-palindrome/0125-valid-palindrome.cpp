class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(int i = 0 ; i < s.size() ; i++){
            s[i] = tolower(s[i]);
            if(s[i] >='a' && s[i] <='z')temp +=s[i];
            if(s[i] >='0' && s[i] <='9')temp +=s[i];
        }
        int  i = 0 , j = temp.size()-1;
        while(i<=j){
            if(temp [i] != temp[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};