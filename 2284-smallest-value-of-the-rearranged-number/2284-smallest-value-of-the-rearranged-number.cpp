class Solution {
public:
    vector<int> digit_calculation(string str,bool ok){
        vector<int>v;
        for(auto u:str){
            v.push_back(u-'0');
        }
        if(ok == 1){
            sort(v.rbegin(),v.rend());
        }else{
            sort(v.begin(),v.end());
            for(int i=0;i<v.size();i++) {
                if(v[i] != 0){
                    swap(v[0],v[i]);
                    break;
                }
            }
        }
        cout<<"printkorse\n";
        for(auto u:v)cout<<u;
        //endl;
        return v;
        
    }
    long long smallestNumber(long long num) {
       long long answer = 0, multiply = 1;
       string str = to_string(num);
       reverse(str.begin(),str.end());
       if(str[str.size()-1] == '-'){
            str.pop_back();
            vector<int>v(digit_calculation(str,1));
            for(auto u:v){
                answer *= (multiply*10);
                answer +=u;
            }
            answer *= (-1);
            return answer;

       }else{
            vector<int>v(digit_calculation(str,0));
            for(auto u:v){
                //cout<<u;
                
                answer *= (multiply*10);
                answer +=u;
                //multiply *= 10;
            }
            //answer *= (-1);
            return answer;
       }
    }
};