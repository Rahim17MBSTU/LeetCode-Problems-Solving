class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> g;
        unordered_map<int,int>InDegree,OutDegree;
        for(auto edges:pairs){
            int u = edges[0];
            int v = edges[1];
            g[u].push_back(v);
          
            InDegree[v]++;  // calculate outdegree
            OutDegree[u]++; // calculate indegree
        }
        int StartNode = pairs[0][0];
        
        for(auto u:g){
            int Node = u.first;
            
            if((OutDegree[Node] - InDegree[Node]) == 1){
                StartNode = Node;
                break;
            }
        }
        cout << StartNode<<endl;
        vector<int>path;
        stack<int> st;
        st.push(StartNode);
        while(!st.empty()){
            int source = st.top();
            
            if(!g[source].empty()){
                int child = g[source].back();
                g[source].pop_back();
                st.push(child);
            }else{
                path.push_back(source);
                st.pop();
            }
            
        }
        
        reverse(path.begin(),path.end());
        vector<vector<int>>res;
        for(int i = 0 ;i < path.size() - 1;i++){
            int x = path[i];
            int y = path[i+1];
            res.push_back({x,y});
        }
        return res;
    }
};