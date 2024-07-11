#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string current = "";
        
        for (char ch : s) {
            if (ch == '(') {
                st.push(current);
                current = "";
            } else if (ch == ')') {
                reverse(current.begin(), current.end());
                //cout<<"current= "<<current<<endl;
                //cout<<"st-size= "<<st.size()<<endl;
                if (!st.empty()) {
                    //cout<<"cholse\n";
                    //cout<<"st= "<<st.top()<<endl;
                    current = st.top() + current;
                    cout<<current<<endl;
                    st.pop();
                }
            } else {
                current += ch;
            }
        }
        
        return current;
    }
};


