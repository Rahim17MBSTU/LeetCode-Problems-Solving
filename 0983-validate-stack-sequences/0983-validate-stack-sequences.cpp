class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st1,st2;
        reverse(popped.begin(),popped.end());
        int n = pushed.size();
        int m = popped.size();
        for(int i = 0 ; i< m; i++){
            st2.push(popped[i]);
        }
        for(int i = 0 ; i < n ; i++){
            st1.push(pushed[i]);
            while(!st2.empty()&&!st1.empty() && st1.top() == st2.top()){
                st1.pop();
                st2.pop();
            }
        }
        cout << st1.size() << " "<<st2.empty()<<endl;
        if(st1.empty() && st2.empty()){
            return true;
        }return false;
    }
};