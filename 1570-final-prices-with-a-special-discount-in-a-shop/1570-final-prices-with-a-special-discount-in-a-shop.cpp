class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>res;
        int n = prices.size();
        for(int i = 0 ; i < n; i++){
            int currentValue = prices[i],temp = 0;
            for(int j = i + 1;j < n ;j++){
                if(currentValue >= prices[j]){
                    temp = prices[j];
                    break;
                }
            }
            res.push_back(currentValue - temp);
        }
        return res;
    }
};