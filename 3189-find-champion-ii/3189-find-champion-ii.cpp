class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
     
        vector<int>InDegree(n,0);
        int ans = -1 ,cnt = 0;
        for(vector<int>e :edges){
            int u = e[0];
            int v = e[1];
             // u --> v
            InDegree[v]++;
        
        }
        
        for(int i = 0 ; i < n;i++) 
            if(InDegree[i] == 0) {
                ans = i;
                cnt++;
            if(cnt>=2 )return -1;
        } 
        return ans;
    }  
};