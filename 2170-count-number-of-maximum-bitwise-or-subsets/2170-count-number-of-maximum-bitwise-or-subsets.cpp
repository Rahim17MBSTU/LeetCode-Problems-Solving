class Solution {
public:
    int calculation(int i, vector<int>&v, int NewOrValue, int targetOr){
        if(i == v.size()){
            return targetOr == NewOrValue ? 1 : 0;
        }
        int pick = calculation(i+1,v, NewOrValue | v[i] , targetOr);
        int nonPick = calculation(i+1,v, NewOrValue , targetOr);
        return pick + nonPick;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int targetOr = 0;
        for(auto u:nums) targetOr |= u;
        return calculation(0,nums,0,targetOr);
    }
    
};