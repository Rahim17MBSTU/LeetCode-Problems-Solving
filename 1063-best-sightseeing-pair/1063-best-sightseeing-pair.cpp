class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int>maxSum(n-1);
        vector<int>minSum(n-1);
        for(int i = 0 ;i<n-1;i++){
            maxSum[i] = i + values[i];
        }
        int mn = INT_MAX;
        for(int i= n-2;i>=0;i--){
            mn = min(mn,(i+1)-values[i+1]);
            minSum[i] = mn;
        }
        int mx = INT_MIN;
        for(int i = 0 ;i<n-1;i++){
            mx = max(mx,maxSum[i] - minSum[i]);
        }
        return mx;
    }
};