class Solution {
public:
    vector<int>parent;
    int find(int x){
        if(parent[x] == x)return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int a,int b){
        parent[b] = a;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        vector<int>cost(n);
        for(int i = 0 ; i<n;i++){
            parent[i] = i;
            cost[i] = -1;
        }
        for(auto u:edges){
            int x = u[0];
            int y = u[1];
            int w = u[2];
            x = find(x);
            y = find(y);
            if(x != y){
                Union(x,y);
                cost[x] &= cost[y];
            }
            cost[x] &= w;
        }
        vector<int>ans;
        for(auto u:query){
            int x = u[0];
            int y = u[1];
            if(find(x)!=find(y)){
                ans.push_back(-1);
            }else{
                ans.push_back(cost[find(x)]);
            }
        }
        return ans;
    }
};