class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        
        int size = candidates.size();

        vector<int>res(25,0);
        
        int mxLenght = 0;

        for(int i = 24 ;i >= 0 ;i--){
            
            for(auto u: candidates){
                if((u & (1 << i)) != 0)res[i]++;
              
            } 
            mxLenght = max(mxLenght , res[i]);
        }
        return mxLenght;
    }
};