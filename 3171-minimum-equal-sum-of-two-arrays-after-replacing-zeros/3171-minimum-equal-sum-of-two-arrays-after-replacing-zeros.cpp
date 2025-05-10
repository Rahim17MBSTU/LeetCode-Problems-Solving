class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int zero1 = count(nums1.begin(),nums1.end(),0);
        int zero2 = count(nums2.begin(),nums2.end(),0);
        long long sum1 = accumulate(nums1.begin(),nums1.end(),0LL);
        long long sum2 = accumulate(nums2.begin(),nums2.end(),0LL);
        if(zero1 == 0 && zero2 != 0){
            if(sum2 + zero2  <= sum1)return sum1;
            return -1;
        }
        if(zero1 != 0 && zero2 == 0){
            if(sum1 + zero1  <= sum2)return sum2;
            return -1;
        }
        if(zero1 == 0 && zero2 == 0){
            if(sum1 == sum2 )return sum1;
            return -1;
        }
        sum1 += zero1;
        sum2 += zero2;
        return max(sum1,sum2);
        
    }
};