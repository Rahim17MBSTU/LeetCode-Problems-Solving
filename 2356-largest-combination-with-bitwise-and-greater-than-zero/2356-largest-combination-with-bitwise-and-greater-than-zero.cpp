class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        
        int n = candidates.size();
        vector<int>res(32,0);
        bitset<31>b[n];
        for(int i=0;i<n;i++){
            b[i] = candidates[i];
        }
        int mxLenght = 0;
        for(int i = 0 ;i < candidates.size() ;i++){
            for(int j = 30 ; j >= 0;j--){
                res[j] += b[i][j];
                mxLenght = max(mxLenght , res[j]);
            }
        }
        return mxLenght;
    }
};