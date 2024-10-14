class Solution {
public:
    int halveArray(vector<int>& nums) {
        double answer = accumulate(nums.begin(),nums.end(),0LL);
        double halfAnswer = answer / 2.0;
        priority_queue<double>pq(nums.begin(),nums.end());
        int cnt = 0;
        while(!pq.empty()){

            double value = pq.top();
            //cout<<"Value = "<<value<<endl;
            pq.pop();
            answer -= value;
            value /= 2.0;
            pq.push(value);
            answer += value;
            cnt++;
            //cout<<"answer= "<<answer<<endl;
            if(answer <= halfAnswer)break;
        }
        return cnt;
    }
};