class Solution {
public:
    int minLength(string s) {
        
        stack<char>Stack;
        
        for(int i = 0 ; i < s.size(); i++){

            if(Stack.empty()){
                Stack.push(s[i]);
            }else{
                if(Stack.top() =='A' && s[i] =='B' ){
                    Stack.pop();
                }else if(Stack.top() =='C' && s[i] =='D'){
                    Stack.pop();
                }else{
                    Stack.push(s[i]);
                }
            }
        }
        return Stack.size();
    }
};