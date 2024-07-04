class Solution {
public:

    bool is_Prime(int n){
        for(int i=2;1LL*i*i<=n;i++){
            if( n % i == 0){
                return false;
            }
        }
        return true;
    }

    bool is_Plaindrom(int n){
        string str = to_string(n);
        int i = 0 , j = str.size()-1;
        while(i<=j){
            if(str[i] == str[j]){
                i++;
                j--; continue;
            }else{
                return false;
            }
        }
        return true;
    }

    int primePalindrome(int n) {
        if( n == 1){
            return 2 ;
        }
        vector<int>prime ;
        vector<bool>b(1e6+10,0);
        for(int i=3;1LL*i*i<=1e6;i+=2){
            if(b[i] == 0){
                for(int j=i*i;j<=1e6;j+=i){
                    b[j] = 1; 
                }
            }
        }
        prime.push_back(2);
        for(int i=3;i<=1e6;i+=2){
            if(b[i] == 0){
                prime.push_back(i);
            }
        }
        int value = n;
        while(1){
            auto it = lower_bound(prime.begin(),prime.end(),value );
            if(n>1e4){
                
                for(int j = 10;j<=2e4;j++){
                    
                    string ss,s = to_string(j);
                    ss = s;
                    string res ="",res1="";
                    res+=s;
                    res1+=s;
                    if(s.size()%2==1){
                      ss.pop_back();
                    }
                    s.pop_back();
                    reverse(s.begin(),s.end());
                    reverse(ss.begin(),ss.end());
                    res+=s;
                    res1+=ss;
                    
                    int k = stoi(res);
                    int k1 = stoi(res1);
                    
                    if(k>=n && is_Prime(k)){
                        return k;
                    }
                    if(k1>=n && is_Prime(k1)){
                        return k1;
                    }
                }
                return n;
            }else{
                if(is_Plaindrom(*it)){
                    return *it;
                }
            }
            value = *it+1;
        }
    }
};