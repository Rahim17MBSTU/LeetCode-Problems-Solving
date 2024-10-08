class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int>st;
        
        int n = pushed.size(), j = 0;

        for(int i = 0 ; i < n ; i++){
            st.push(pushed[i]);
            
            while(!st.empty() && st.top() == popped[j]){
                st.pop();
                j++;
            }
        }
 
        if(st.empty() && (j == popped.size())){
            return true;
        }return false;
    }
};