class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int row = moveTime.size();
        int col = moveTime[0].size();

        int answer = 0 ; 
        vector<vector<bool>> visited(row, vector<bool>(col,0));

        priority_queue<pair<int,pair<int,pair<int,int>>> , vector<pair<int,pair<int,pair<int,int>>>> , greater<pair<int,pair<int,pair<int,int>>>>> Priority_queue;

        Priority_queue.push({0,{0,{0,2}}});
        visited[0][0] = 1;
        
        while(!Priority_queue.empty()){

            int oldValue = Priority_queue.top().first;
            int oldRow = Priority_queue.top().second.first;
            int oldCol = Priority_queue.top().second.second.first;
            int moveValue = Priority_queue.top().second.second.second;

            Priority_queue.pop();
           
            if(oldRow == row - 1 && oldCol == col-1){
                answer = oldValue;
                break;
            }
            moveValue = (moveValue == 2) ? 1 : 2 ; 
            for(int i = 0 ; i < 4; i++){

                int newRow = oldRow + dx[i];
                int newCol = oldCol + dy[i];

                if(newRow < 0 || newCol < 0 || newRow >= row || newCol >= col || visited[newRow][newCol]) continue;
                visited[newRow][newCol] = 1;

                if(oldValue < moveTime[newRow][newCol]){

                    int newValue = moveTime[newRow][newCol] + moveValue;
                    Priority_queue.push({newValue,{newRow,{newCol,moveValue}}});

                }else{

                    int newValue = oldValue + moveValue;
                    Priority_queue.push({newValue,{newRow,{newCol,moveValue}}});

                }
            }
    
        }

        return answer;

    }
};