class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        for(int i = 0 ;i < k;i++)colors.push_back(colors[i]);
        deque<int>sameIndx;int answer = 0;
        for(int i = 0;i<k-1;i++){
            if(colors[i] == colors[i+1]){
                sameIndx.push_back(i);
                //cout<<"i= "<<i<<" ";
            }
        }//[0, 1, 0, 0,1,0, 1, 0 ,1, 0, 0,1]
        //  0, 1, 2, 3,4,5, 6, 7 ,8, 9, 10,11
        if(sameIndx.empty())answer++;
        //  for(int i = 0 ;i<n+k-1;i++){
        //     cout<<colors[i]<<" ";
        //  }cout<<endl;
        for(int i = 0,j=k;j <n+k-1;j++,i++){
           // cout<<i<<" "<<j<< " "<<sameIndx.size()<<endl;
            if(colors[j] == colors[j-1]){
                sameIndx.push_back(j-1);
              //  cout<<"j= "<<j<<" ";
            }
            if(!sameIndx.empty() && sameIndx.front() == i){
                sameIndx.pop_front();
            }
            if(sameIndx.empty())
            answer++;
            
        }

        return answer;
    }
};