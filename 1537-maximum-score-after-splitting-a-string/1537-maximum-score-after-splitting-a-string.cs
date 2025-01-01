public class Solution {
    public int MaxScore(string s) {
        int [] prefix = new int[s.Length];
        for(int i = 0 ; i < s.Length; i++){
            prefix[i] = s[i] - '0';
            if(i > 0) prefix[i] += prefix[i-1];
        }
        int max = 0,zero = 0;
        for(int i = 0 ; i < s.Length-1;i++){
            zero += (s[i] == '0' ? 1 : 0);
            max = Math.Max(max,zero +prefix[s.Length-1] - prefix[i]);
        }
        return max;
    }
}