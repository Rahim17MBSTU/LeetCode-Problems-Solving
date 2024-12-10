class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        //cout<<a.size()<<" "<<b.size()<<endl;
       
        if(a.size() > b.size()){
             reverse(b.begin(),b.end());
            int x = a.size() - b.size();
            while(x--){
                b+='0';
            }
            reverse(b.begin(),b.end());
        }else if(b.size() > a.size()){
            reverse(a.begin(),a.end());
            int x = b.size() - a.size();
            while(x--){
                a+='0';
            }
            reverse(a.begin(),a.end());
        }
        //cout<<a.size()<<" "<<b.size()<<endl;
        //cout<<a<< "\n"<<b<<endl;
        int one = 0;
        for(int i = a.size()-1 ; i >=0; i--){
            if(a[i] == '1')one++;
            if(b[i] == '1')one++;
            if(one == 0){
                res += '0';
            }
            else if(one == 1){
                one = 0;
                res += '1';
            }
            else if(one == 2){
                res += '0';
                one = 1;
            }else if(one == 3){
                res +='1';
                one = 1;
            }
            if(i == 0){
                if(one >= 1){
                    res += '1';
                }
            }
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};