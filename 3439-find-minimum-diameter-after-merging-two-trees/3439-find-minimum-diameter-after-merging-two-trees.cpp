class Solution {
public:
    int longestNodeCalculation(int source ,vector<vector<int>> &g,int n,bool ok ){
        queue<int>q;
        q.push(source);
        vector<bool>vis(n+2,0);
        vector<int>dis(n+2,0);
        vis[source] = 1;
        dis[source] = 0;
        while(!q.empty()){
            int source = q.front();
            q.pop();
            for(auto u:g[source]){
                if(!vis[u]){
                    q.push(u);
                    dis[u] = dis[source] + 1;
                    vis[u] = 1;
                }
            }
        }
        int mx = 0,indx = 0;
       // cout<<"sosroso\n";
        for(int i = 0 ; i<= n;i++){
           // cout<<i<<" "<<dis[i]<<endl;
            if(dis[i] > mx){
                mx = dis[i];
                indx = i;
            }
        }
        if(ok == 0){
             return indx;
        }else{
            return mx;
        }
       
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
            int n = edges1.size();
            int m = edges2.size();
            vector<vector<int>> g1(n+5),g2(m+5);
            
            for(int i = 0 ; i < n;i++){
                int x = edges1[i][0];
                int y = edges1[i][1];
                g1[x].push_back(y);
                g1[y].push_back(x);
            }
            for(int i = 0 ; i < m ;i++){
                int x = edges2[i][0];
                int y = edges2[i][1];
                g2[x].push_back(y);
                g2[y].push_back(x);
            }
            
            int longestNode1 = longestNodeCalculation(0,g1,n,false);
            int longestNode2 = longestNodeCalculation(0,g2,m,false);
            int x = longestNodeCalculation(longestNode1,g1,n,true);
            int y = longestNodeCalculation(longestNode2,g2,m,true);
            //
            int answer = 1 + (x + 1) / 2 + (y + 1) / 2;
            if(answer < max(x,y))answer = max(x,y);
        
            cout << longestNode1 << " " << longestNode2<<endl;
            cout<<"x = "<<x<<" y= "<<y<<endl;
            return answer;
    }
};