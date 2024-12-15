
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double,int>>pq;
        for(int i = 0  ; i < n; i++){
            double current  = (double)classes[i][0] / classes[i][1];
            double Increase = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
            double delta = Increase - current;
            //cout<<"i "<<i<<"-> "<<delta<<endl;
            pq.push({delta,i});
        }        
        while(extraStudents--){
            int indx = pq.top().second;
            
            //cout<<"indx = "<<indx<<" "<<pq.top().first<<endl;
            pq.pop();
            classes[indx][0]++;
            classes[indx][1]++;
            double current  = (double)classes[indx][0] / classes[indx][1];
            double Increase = (double)(classes[indx][0] + 1) / (classes[indx][1] + 1);
            double delta = Increase - current;
            //cout<<"delta "<<delta<<endl;
            pq.push({delta,indx});
        }
        double answer = 0;
        for(int i = 0 ;i <n;i++){
            //cout<<classes[i][0]<<" "<<classes[i][1]<<endl;
            answer +=((double)classes[i][0]/classes[i][1]);
        }
        //cout<<answer<<endl;
        return answer/n;
    }
};