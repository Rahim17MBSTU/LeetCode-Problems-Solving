class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int n = s.size();
        for(int i = 0 ;i < n ;i++){
            if(st.empty()){
                st.push(s[i]);
            }else{
                if(st.top() == '[' && s[i] == ']'){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }
        }
        cout << st.size()<<endl;
        int answer = st.size()/2;
        answer = (answer % 2 == 0) ? answer / 2 : answer / 2 + 1;
        return answer ; 
    }
};