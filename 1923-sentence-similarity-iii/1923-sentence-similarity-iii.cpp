class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.size() == s2.size()){
            if(s1 == s2) return 1;
            return 0;
        }
        deque<string>a,b;
        s1.push_back(' ');
        s2.push_back(' ');
        string temp ="";
        for(int i=0;i<s1.size();i++){
            if(s1[i] == ' '){
                a.push_back(temp);
                temp = "";
            }else{
                temp += s1[i];
            }
        }
        temp = "" ;
        for(int i=0;i<s2.size();i++){
            if(s2[i] == ' '){
                b.push_back(temp);
                temp = "";
            }else{
                temp += s2[i];
            }
        }
        while(a.size() && b.size() && a.front() == b.front()){
            a.pop_front();
            b.pop_front();
        }
        while(a.size() && b.size() && a.back() == b.back()){
            a.pop_back();
            b.pop_back();
        }
        if(a.empty() || b.empty()){
            return 1;
        }
        return 0;
        
    }
};