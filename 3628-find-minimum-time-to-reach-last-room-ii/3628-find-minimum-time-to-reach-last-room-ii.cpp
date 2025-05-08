class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int answer = 0;
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        priority_queue<pair<int,pair<int,pair<int,int>>>, vector<pair<int,pair<int,pair<int,int>>>> , greater<pair<int,pair<int,pair<int,int>>>>> pq;
        pq.push({0,{0,{0,2}}});
        while(!pq.empty()){
            int value = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second.first;
            int inc = pq.top().second.second.second;
            //cout<<value <<" "<<x <<" "<<y<<" "<<inc<<endl;
            if(x == n-1 && y == m-1){
                answer = value ;
                break;
            }
            pq.pop();
            if(inc == 2) inc = 1;
            else inc = 2;
            for(int i = 0 ; i < 4; i++){
                int X = x + dx[i];
                int Y = y + dy[i];
                if(X >= n || X < 0 || Y >= m || Y < 0 || vis[X][Y] ) continue;
                vis[X][Y] = 1;
                
                if(value < moveTime[X][Y]){
                     
                     pq.push({moveTime[X][Y]+inc,{X,{Y,inc}}});
                }else{
                    pq.push({value+inc,{X,{Y,inc}}});
                }
            }
        }
        return answer;
    }
};