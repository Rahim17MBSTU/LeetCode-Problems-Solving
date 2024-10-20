class Solution {
public:
    bool calculation(vector<char>&v,char op){
        bool result;
        if(op == '|'){
            result = 0;
            for(auto u:v){
                result |= (u=='f'?0:1);
            }
        }else if(op == '&'){
            result = 1;
            for(auto u:v){
                result &= (u=='f'?0:1);
            }
        }else{
            result = 0;
            for(auto u:v)
            result = !(u == 'f'?0:1);
        }
        return result;
    }
    bool parseBoolExpr(string s) {
        stack<char> expression;
        bool result = 0;
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] == ',')continue;
            if(s[i] == ')'){
                vector<char>v;
                while(!expression.empty()){
                    char ch = expression.top();
                    expression.pop();
                    if(ch == '('){  
                        break;
                    }v.push_back(ch);
                }
                char op = expression.top();

                expression.pop();
                result = calculation(v,op);
                expression.push(result==1?'t':'f');
            }
            else{
                expression.push(s[i]);
            }
                
               
        }
        return result;
    }
};