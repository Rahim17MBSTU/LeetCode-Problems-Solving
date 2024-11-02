class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string>result;
        string s = "";
        for(int i = 0 ; i < sentence.size();i++){
            if(sentence[i] == ' '){
                result.push_back(s);
                s ="";
            }else{
                s +=sentence[i];
            }
        }
        if(!s.empty()){
            result.push_back(s);
        }
        int n = result.size();
        for(int i=0;i<result.size();i++){
            int indx1 = i;
            int indx2 = (i+1) % n;
            string s1 = result[indx1];
            string s2 = result[indx2];
            if(s2[0] != s1[s1.size()-1])return false;
        }
        return true;
    }
};