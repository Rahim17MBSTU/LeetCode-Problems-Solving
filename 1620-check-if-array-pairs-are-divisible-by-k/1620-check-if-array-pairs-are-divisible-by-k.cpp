class Solution {
public:
    bool canArrange(vector<int>& v, int k) {
        vector<int>mp(1e5+10,0);
        int pair = 0, n = v.size();
       
        for(int i=0;i<n;i++){
            
            v[i] = ((v[i] % k) + k) % k;
            
            if(v[i] == 0 && mp[v[i]]>=1){
                pair++;
                mp[v[i]]--; continue;

            }if(v[i] != 0 && mp[k-v[i]]>=1){
                pair++;
                mp[k-v[i]]--;continue;
                
            }else{
                mp[v[i]]++;
            }
        }
        
        return pair == n/2 ? 1 : 0 ;
    }
};