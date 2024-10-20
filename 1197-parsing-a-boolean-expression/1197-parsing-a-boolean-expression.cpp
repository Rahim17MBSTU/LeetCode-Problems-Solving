class Solution {
public:
    bool calculation(int indx,stack<pair<char,int>>&st,bool ok,bool ORR, bool ANND ,bool NOOT){
        while(!st.empty()){
            
            int x = st.top().second;
            bool value = st.top().first == 't'?1:0;
            
            if(x < indx){
                break;
            }
            
            st.pop();
            
            if(ORR == 1) ok |= value;
            if(ANND == 1) ok &= value;
            if(NOOT == 1) ok = !value ;
        }
        cout << ok <<endl;
        return ok;
    }

    bool parseBoolExpr(string s) {
        
        stack<pair<char,int>>symbol,bracket,expression;
        bool result = 0, okk = 0;
        
        for(int i = 0 ; i < s.size(); i++){

            if(s[i] == ',')continue;

            if(s[i] == '&'||s[i] =='|' || s[i] =='!'){

                symbol.push({s[i],i});

            }else if(s[i] =='f' || s[i] =='t'){
                
                expression.push({s[i],i});
            
            }else{
                
                if(s[i] =='('){
                    
                    bracket.push({s[i],i});
                
                }else{
                    
                    int indx = bracket.top().second;
                    bracket.pop();
                    
                    if(symbol.top().first == '|'){ 
                        
                        result = 0;
                        result |=calculation(indx,expression,false,true,false,false);
                    
                    }else if(symbol.top().first == '&'){
                        result = 1;  
                        result &= calculation(indx,expression,true,false,true,false);
                    
                    }else{
                 
                        result = expression.top().first == 't'?1:0;
                        result = calculation(indx,expression,result,false,false,true);
                    
                    }
                   
                    expression.push({result == true?'t':'f',indx});
                    
                    symbol.pop();
                }
            }
        }
        return result;
    }
};