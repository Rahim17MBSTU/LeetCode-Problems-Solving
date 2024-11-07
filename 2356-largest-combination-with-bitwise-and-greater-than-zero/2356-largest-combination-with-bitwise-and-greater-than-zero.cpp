class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        
        int size = candidates.size();

        vector<int>res(25,0);
        bitset<25>b[size];

        for(int i=0;i<size;i++){
            b[i] = candidates[i];
        }
        int mxLenght = 0;

        for(int i = 0 ;i < size ;i++){
            
            for(int j = 24 ; j >= 0;j--){
                res[j] += b[i][j];
                mxLenght = max(mxLenght , res[j]);
            }
        }
        return mxLenght;
    }
};