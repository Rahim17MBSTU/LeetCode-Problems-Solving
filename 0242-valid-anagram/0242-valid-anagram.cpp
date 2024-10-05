
    class Solution {
 public:
    static bool isValidAnagrams( vector<int>&OriginalFre,  vector<int>&demoFrequency){
        
        for(int i = 1; i <= 26; i++){

            if(OriginalFre[i] != demoFrequency[i]) return 0;
        }

        return 1;
    }

    bool isAnagram(string s, string t) {

        if(s.size() != t.size() ) return false; 
        
        vector<int>demoFrequency(27,0),OriginalFre(27,0);

        for(int i = 0 ; i < s.size();i++){
            OriginalFre[s[i]-96]++;
        }

        for(int i = 0; i < t.size() ; i++){
            demoFrequency[t[i]-96]++;
        }
        
        if(isValidAnagrams(OriginalFre,demoFrequency)) return true;

        return false;
    }

};