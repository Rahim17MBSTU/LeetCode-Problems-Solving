class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        if(str2.size() > str1.size()) return false;
        int indx = 0;
        bool ok = 0;
        for(int i = 0 ; i < str1.size() ; i++){
            if(indx >= str2.size()) break;
            if(str1[i] == str2[indx])indx++;
            else if(str1[i] == 'z' && str2[indx] == 'a')indx++;
            else if(str1[i]+1 == str2[indx])indx++;

        }
        if(indx >= str2.size() )return true;
        return false;
    }
};