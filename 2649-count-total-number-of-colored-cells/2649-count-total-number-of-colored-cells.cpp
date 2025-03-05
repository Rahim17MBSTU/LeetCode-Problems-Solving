class Solution {
public:
    long long coloredCells(int n) {
        long long ans = (long long)n * (n-1) / 2;
        ans *= 4;
        ans++;
        return ans;
        
    }
};