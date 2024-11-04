public class Solution {
    public string CompressedString(string word) {
        StringBuilder result = new StringBuilder();
        int cnt = 1,n = word.Length;
        char ch = word[0];
        for(int i = 1 ; i < n; i++){
            if(word[i] == ch)cnt++;
            if(word[i] != ch){
                result.Append(cnt);
                cnt = 1;
                result.Append(ch);
                ch = word[i];
                continue;
            }
            if(cnt == 10){
                cnt--;
                result.Append(cnt);
                result.Append(ch);
                ch = word[i];
                cnt = 1;
            }
        }
        if(cnt >= 1){
            result.Append(cnt);
           
            result.Append(ch);
        }
        
        return result.ToString();
    }
}