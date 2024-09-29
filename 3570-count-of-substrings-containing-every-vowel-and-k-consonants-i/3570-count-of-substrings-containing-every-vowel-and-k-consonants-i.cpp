class Solution {
public:
    int countOfSubstrings(string word, int k) {
        
        int res = 0;
        for (int i = 0; i < word.size(); ++i) {
                //string str = "";
                int cnt = 0;
                set<char>st;
            for (int j = i; j < word.size(); ++j) { 
                
                if(word[j] =='a'||word[j] =='e'||word[j] =='i'|| word[j] =='o'||word[j] =='u'){
                       st.insert(word[j]);
                }else{
                        cnt++;
                }  
                
                if(cnt == k && st.size() == 5){
                    res++;
                }
                if(cnt > k)break;
            }
        }
        
        return res;
    }
};