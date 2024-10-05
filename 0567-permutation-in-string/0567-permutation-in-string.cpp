class Solution {
public:
    static bool isValidPermutation(vector<int>&original,vector<int>&demo){
        for(int i =1;i<=26;i++){
            if(original[i] != demo[i]){
                return 0;
            }
        }
        return 1;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int>frequency(28,0),demoFrequency(28,0);
        for(int i=0;i<s1.size();i++){
            frequency[s1[i]-96]++;
        }
        for(int i=0;i<s1.size();i++){
            demoFrequency[s2[i]-96]++;
        }
        if(isValidPermutation(frequency,demoFrequency)){
            return true;
        }
        
        for(int i = s1.size(),j=0; i < s2.size(); i++,j++){
            demoFrequency[s2[i]-96]++;
            demoFrequency[s2[j]-96]--;
            if(isValidPermutation(frequency,demoFrequency)){
                return true;
            }
        }
        return false;
        return 0;
    }
};