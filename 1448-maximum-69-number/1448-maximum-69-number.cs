public class Solution {
    public int Maximum69Number (int num) {
        StringBuilder  str = new StringBuilder(num.ToString());
        for(int i = 0 ; i< str.Length; i++){
            if(str[i]=='6')
            {
                str[i] = '9';
                break;
            }
        }

        return int.Parse(str.ToString());
    }
}