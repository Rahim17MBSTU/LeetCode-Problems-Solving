class Solution {
public:
    int answer =0;
     int calculation(int Xor,vector<int>&v,int i,int n,int value ){
        if(i == n){
            if(Xor == value)answer++;
            return 0;
        }
        
        calculation(Xor,v,i+1,n,value) ;
        calculation(Xor|v[i],v,i+1,n,value) ;
        return answer;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int value = 0;
        for(auto u:nums){
            value |= u;
        }
        return calculation(0,nums,0,nums.size(),value);
    }
};