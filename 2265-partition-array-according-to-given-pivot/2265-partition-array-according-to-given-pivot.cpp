class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>less,getter,equal;
        for(auto u:nums){
            if(u > pivot)getter.push_back(u);
           else if(u < pivot)less.push_back(u);
            else equal.push_back(u);
        }
       
        vector<int>result;
        result.insert(result.end(),less.begin(),less.end());
        result.insert(result.end(),equal.begin(),equal.end());
        result.insert(result.end(),getter.begin(),getter.end());
        return result;
    }
};