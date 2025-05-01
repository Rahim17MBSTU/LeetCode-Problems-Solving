class Solution {
public:
    string convert(string s, int numRows) {
        int last = 0;
        string res ="";
        if(numRows == 1)return s;
        for(int i = 0;i<numRows;i++){
            int j = i;
            int cnt = 0, incre = (numRows - (i+1) )*2;
            int incre1 = ((numRows - (i+1))  * 2);
            int incre2 = (i)*2;
           // cout<<i<<" "<<incre1<<" "<<incre2<<endl;
            //cout<<j<<" ";
            while(j<s.size()){
                if(i == 0){
                    res+=s[j];
                    j+=incre;
                    last = incre;
                    if(j == 0)break;
                   // cout<<j<<" ";
                }else if(i == numRows-1){
                   res+=s[j];
                    j+=last;
                  //  cout<<j<<" ";
                }
                else{
                    if(cnt%2 == 0){
                        res+=s[j];
                        j+=incre1;//cout<<j<<" ";
                    }else{
                      res+=s[j];
                        j+=incre2;//cout<<j<<" ";
                    }
                    cnt++;
                }
            }
            cout<<'\n';
        }
        return res;
    }
};