class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
     
        vector<int>Ingoing(n);
        int ans = 0;
        for(vector<int>v :edges){
            int x = v[0];
            int y = v[1];
            Ingoing[y]++;
            
        
        }
        int cnt = 0;
        for(int i = 0 ; i < n;i++) if(Ingoing[i] == 0) {
            ans = i;
            cnt++;
           if(cnt>=2 )return -1;
        } 
        return ans;
    }  
};