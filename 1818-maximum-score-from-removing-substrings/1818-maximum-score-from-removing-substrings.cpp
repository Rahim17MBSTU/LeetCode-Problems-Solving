class Solution {
public:
    int maximumGain(string s, int x, int y) {
        vector<char>v;
        int n = s.size();
        int ab = 0, cnt = 0, ans = 0 ,ba= 0;
        if(x >= y){ 
            for(int i=0;i<s.size();){
                if(v.size()>=1 && s[i] =='b' && v.back() =='a'){
                    char c = v.back();
                    while(!v.empty() && s[i] =='b' && v.back() =='a' && i<n){
                        ab++;
                        i++;
                        v.pop_back();
                    }
                }else
                {
                    v.push_back(s[i]);i++;
                }
            }
            int a = 0,b = 0;
            for(auto u:v){
                if(u == 'a'){
                    a++;continue;
                }
                if(u == 'b'){
                    b++;continue;
                }
                else{
                    ba += min(a,b);
                    a = b = 0;
                }
            }
            ba += min(a,b);
        }else{
            for(int i=0;i<s.size();){
                
                if(v.size()>=1 && s[i] =='a' && v.back() =='b'){
                   
                    while(!v.empty() && s[i] =='a' && v.back() =='b' && i<n){
                        ba++;
                        ans += y;
                        i++;
                        v.pop_back();
                    }
                }else{
                    v.push_back(s[i]);
                    i++;
                }
                
            }
            int a = 0,b = 0;
            for(auto u:v){
                cout<<u;
                if(u == 'a'){
                    a++;continue;
                }
                if(u == 'b'){
                    b++;continue;
                }
                else{
                    ab += min(a,b);
                    a = b = 0;
                }
            }
            
            ab += min(a,b);
         
        }
        ans = (ab * x) + (ba * y);
        return ans ; 
    }
};