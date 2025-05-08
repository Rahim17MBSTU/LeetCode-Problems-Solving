class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        
        pq.push({0,{0,0}});
        int dx[] = {1,0, -1, 0};
        int dy[] = {0,1, 0, -1};
        int ans = 0;
        while(!pq.empty()){
            int value = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            //cout<<value <<" "<< x<<" "<<y<<endl;
            if(x == n-1 && y == m-1){
                ans = value;
               break;
            }
            pq.pop();
            for(int i = 0 ; i < 4; i++){
                if(x + dx[i] < n && y + dy[i] < m && x + dx[i] >= 0 && y + dy[i] >= 0 && vis[x+dx[i]][y+dy[i]] == 0){
                    int X = x + dx[i];
                    int Y = y + dy[i];
                    vis[X][Y] = 1;
                    if(value < moveTime[X][Y]){
                        pq.push({moveTime[X][Y] + 1,{X,Y}});
                    }else{
                        pq.push({value + 1,{X,Y}});
                    }
                }
            }
        }
        return ans;
    }
};