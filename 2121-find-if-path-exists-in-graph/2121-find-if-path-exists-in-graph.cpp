class Solution {
public:
    static const int N = 2e5+10;

    int parent [N],size[N];
    void make(int v){
        parent[v] = v;
        size[v] = 1;
    }
    int find(int u){
        if(u == parent[u]){
            return u;
        }
        return parent[u] = find(parent[u]);
    }
    void Union(int a,int b){
        int a1 = find(a);
        int b1 = find(b);
        if(a1 != b1){
            if(size[a1] < size[b1]) swap(a1,b1);
           parent[b1] = a1;
           
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        int n1 = edges.size();
        for(int i=0;i<n;i++) {
            make(i);
        }
        for(int i=0;i<n1;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            Union(u,v);
            
        }
        if(find(source) != find(destination)){
            return false;
        }
        return true;
    }
};