class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        for(int i = 0 ;i < k;i++)colors.push_back(colors[i]);
        priority_queue<int,vector<int>,greater<int>>vp;
        int answer = 0;
        for(int i = 0;i<k-1;i++){
            if(colors[i] == colors[i+1]){
                vp.push(i);
            }
        }
        if(vp.empty())answer++;
        for(int i = 0,j=k;j <n+k-1;j++,i++){
            if(colors[j] == colors[j-1]){
               vp.push(j-1);
            }
            if(!vp.empty() && vp.top() == i){
                vp.pop();
            }
            if(vp.empty())
            answer++;
            
        }

        return answer;
    }
};