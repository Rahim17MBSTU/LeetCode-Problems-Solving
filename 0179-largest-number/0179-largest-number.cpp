#include <iostream>
#include <unordered_map>
#include <string>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    static bool comp(string p1, string p2)
    {
        string first = p1 + p2;
        string second = p2 + p1;
        return first > second;
    }
    string largestNumber(vector<int>& nums) {
        
        int n = nums.size();
        string result = "";
        vector<string>v;
        for(auto u:nums){
            string s = to_string(u);
            v.push_back(s);
        }
        sort(v.begin(),v.end(),comp);
        for(auto u:v){
            result += u;
        }
        
        bool ok = 0;
        for(int i=0;i<result.size()-1;i++){
            if(result[i] == result[i+1] && result[i] == '0'){
                continue;
            }else{
                ok =1;
                break;
            }
        }
        if(ok == 0 && result.size()>=2)result = "0";
        return result;
    }
};

// int main() {
//     Solution sol;
//     int n;
//     cin >> n;
//     vector<int>v(n);
//     for(auto &u:v)cin >> u;
//     cout << sol.largestNumber(v) << endl;  // Expected output: 4
//     return 0;
// }
