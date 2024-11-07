public class Solution {
    public bool IsPalindrome(string s) {
        StringBuilder temp = new StringBuilder();
        for(int i = 0 ; i < s.Length; i++){
            char ch = char.ToLower(s[i]);
            if(ch >='a' && ch <='z')temp.Append(ch);
            if(ch >='0' && ch <='9')temp.Append(ch);
        }
        int  k = 0 , j = temp.Length-1;
        while(k<=j){
            if(temp [k] != temp[j]){
                return false;
            }
            k++;
            j--;
        }
        return true;
    }
}