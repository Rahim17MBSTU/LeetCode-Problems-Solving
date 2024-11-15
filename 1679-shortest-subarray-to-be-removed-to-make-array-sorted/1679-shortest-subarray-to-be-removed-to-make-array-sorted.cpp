class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int low = 0 , high = n-1;
        while(high>0 && arr[high]>=arr[high-1]){
            high--;
        }
        int ans = high;
        while(low<high){
            while(high < n && arr[low] > arr[high]){
                high++;
            }
            ans = min(ans,high - low - 1);
            low ++;
            if(low>0 && arr[low]<arr[low-1])break;
        }
        return ans;
    }
};