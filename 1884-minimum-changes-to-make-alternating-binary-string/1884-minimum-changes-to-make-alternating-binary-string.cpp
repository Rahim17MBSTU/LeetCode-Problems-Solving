class Solution {
public:
    int minOperations(string s) {
       
        int cnt1 = 0 ,cnt2 = 0; 
        char ch1 = '0',ch2 = '1';
       
        for(int i = 0 ;i < s.size(); i++){
            if(ch1 != s[i])cnt1++;
            if(ch2 != s[i])cnt2++;
            swap(ch1,ch2);
            
        }
        
        
        return min(cnt1,cnt2);
    }
};