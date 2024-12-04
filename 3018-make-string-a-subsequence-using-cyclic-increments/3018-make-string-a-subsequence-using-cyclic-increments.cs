public class Solution {
    public bool CanMakeSubsequence(string str1, string str2) {
        
        if(str2.Length > str1.Length)return false;
        
        int indx = 0;

        for(int i = 0 ; i < str1.Length ; i++){

            if(indx >= str2.Length) break;

            if(str1[i] == str2[indx])indx++;

            else if(str1[i] == 'z' && str2[indx] == 'a')indx++;

            else if(str1[i] + 1 == str2[indx])indx++;
            
        }
        if(indx >= str2.Length) return true;
        return false;
    }
}