class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())return false;
        s += s;
        cout<<s<<endl;
        for(int i=0;i<s.size()-goal.size();i++){
            bool ok = 0;
            
            for(int j=0,k = i;j<goal.size();j++){
                if(goal[j] != s[k++]){
                    ok = 1;
                    break;
                }
            }
           if(ok == 0)return true;
        }
        return false;
    }
};