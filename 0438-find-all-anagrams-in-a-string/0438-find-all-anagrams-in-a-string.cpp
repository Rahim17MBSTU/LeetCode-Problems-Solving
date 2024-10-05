class Solution {
public:
    static bool isValidAnagrams( vector<int>&OriginalFre,  vector<int>&demoFrequency){
        
        for(int i = 1; i <= 26; i++){

            if(OriginalFre[i] != demoFrequency[i]) return 0;
        }

        return 1;
    }

    vector<int> findAnagrams(string s, string p) {
        
        vector<int> res;

        if(p.size() > s.size() ) return res; 
        
        vector<int>demoFrequency(27,0),OriginalFre(27,0);

        for(int i = 0 ; i < p.size();i++){
            OriginalFre[p[i]-96]++;
        }

        for(int i = 0; i < p.size() ; i++){
            demoFrequency[s[i]-96]++;
        }
        int indx = 0;

        if(isValidAnagrams(OriginalFre,demoFrequency)) res.push_back(indx);

        for(int i = p.size(); i < s.size(); i++,indx++){
            
            demoFrequency[s[i]-96]++;
            
            demoFrequency[s[indx]-96]--;

            if(isValidAnagrams(OriginalFre,demoFrequency)){
                
                res.push_back(indx+1);
            }

        }

        return res;
    }
};