class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int>left(n,0),right(n,0),res;
        if(n == 1){
            res.push_back(0);
            return res;
        }
        for(int i = 0 ; i < n; i++){
            left[i] = (boxes[i] - '0');
            if(i) left[i] += left[i-1];
        }
        
        for(int i = n-1 ; i >= 0; i--){
            right[i] = boxes[i] - '0';
            if(i!= n-1) right[i] += right[i+1];
        }
        
        for(int i = 0 ; i < n ;i ++){
            if(i) left[i] += left[i-1];
        }
        
        for(int i = n-1 ; i >= 0 ;i--){
            if(i != n-1) right[i] += right[i+1];
        }
        for(int i = 0 ; i < n; i++){
            if(i == 0){
                res.push_back(right[i+1]);
                continue;
            }if(i == n-1){
                res.push_back(left[i-1]);
                continue;
            }else{
                res.push_back(left[i-1] + right[i+1]);
            }
        }
        return res;
    }
};