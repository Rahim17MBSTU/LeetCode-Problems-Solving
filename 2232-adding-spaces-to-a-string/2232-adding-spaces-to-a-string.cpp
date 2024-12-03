class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result = "";
        for(int i = s.size()-1;i >= 0 ;i--){
            result += s[i];
            if(!spaces.empty() && spaces.back() == i){
                result+=' ';
                spaces.pop_back();
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};