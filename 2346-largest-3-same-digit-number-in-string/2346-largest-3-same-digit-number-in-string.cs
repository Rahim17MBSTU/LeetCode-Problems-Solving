public class Solution {
    public string LargestGoodInteger(string num) {
        int value = 0;
        for(int i = 0 ;i <num.Length-2;i++){
            if(num[i] == num[i+1] && num[i+1] == num[i+2]){
                int x =(int)num[i];
                if( x > value){
                    value = x;
                    //result = num[i].ToString();
                }
            }
        }
        string result = "";
        if(value != 0){
            for(int i = 0; i <3; i++){
                char ch = (char) value;
                result += ch;
            }
        }
        return result;
    }
}