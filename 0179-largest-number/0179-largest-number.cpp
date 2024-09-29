#include <iostream>
#include <unordered_map>
#include <string>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // static bool comp(string p1, string p2)
    // {
        
    //     int i = 0,j = 0;
    //     int x = p1.size();
    //     int y = p2.size();
    //         cout<<"aise "<<p1 <<" "<<p2<<endl;
    //         for(;i<(x+y) && j<(x+y);j++,i++){
    //             //cout<<"cholse = "<<i<< " "<<j<<endl;
    //                             if(i == p1.size()){
    //                 i = 0;
    //             }
    //             if(j == p2.size()){
    //                 j = 0;
    //             }cout<<p1[i]<<" "<<p2[j]<<" "<<i<<" "<<j<<endl;

    //             if(p1[i] == p2[j])continue;
    //             else if(p1[i] > p2[j]){
    //                 cout<<p1 <<" > "<<p2<<endl;
    //                 return p1 > p2;
    //             }
                    
    //             else if(p1[i] < p2[j]){
    //                 cout << p1 << " < "<<p2<<endl;
    //                 return p2 > p1;
    //             }
                   
    //         }
    //         //cout<<"kkkk\n";
    //         return p1>p2;
        
        
    // }
    static bool comp(string p1, string p2)
    {
    int x = p1.size();
    int y = p2.size();

    
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
        sort(v.rbegin(),v.rend());
        // for(auto u:v){
        //     cout << u <<endl;
        // }
        // cout<<endl;
        for(int i=9;i>=0;i--)
        {
            vector<string>vp;
            for(int j = 0 ;j < n ;j++){

                string s = to_string(nums[j]);
                if(s[0]-'0' == i)
                {
                    vp.push_back(s);
                }
            }
            if(!vp.empty()){
                sort(vp.begin(),vp.end(),comp);
                for(auto u:vp){
                    cout<<u<<endl;
                    result += u;
                }
                
            }
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
