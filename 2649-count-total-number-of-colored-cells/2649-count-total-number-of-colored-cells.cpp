class Solution {
public:
    long long coloredCells(int n) {
        long long sum = 1;
        n--;
        for(int i= 1;i<=n;i++){
            sum += (1LL*4*i);
        }
        return sum;
        
    }
};