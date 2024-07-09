class Solution {
public:
    static const int N = 1e3+10;
    int parent[N],size[N];
    int ans1 = 0, ans2 = 0;
    void make(int u){
        parent[u] = u;
        size[u] = 1;
    }
    int find(int u){
        if(u == parent[u]){
            return u;
        }
        return parent[u] = find(parent[u]);
    }
    void Union(int a,int b){
        int a1 = a;
        int b1 = b;
        a = find(a);
        b = find(b);
        if(a != b){
            if(size[a]< size[b]) swap(a,b);
            parent[b] = a;
            size[a] += size[b];
        }else{
            ans1 = a1;
            ans2 = b1;
            
            
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      
        int n = edges.size();
        for(int i=1;i<=n;i++){
            make(i);
        }
        for(auto u:edges){
            int x = u[0];
            int y = u[1];
            Union(x,y);
        }
       
        return {ans1,ans2};
    }
};