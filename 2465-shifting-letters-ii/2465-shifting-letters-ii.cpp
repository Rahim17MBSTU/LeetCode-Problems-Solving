class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
         int sz = shifts.size();
         vector<int>v(s.size() + 1, 0);
         for(int i = 0 ; i < sz;i++){
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direction = shifts[i][2];
            if(direction == 1){
                v[start] += 1;
                v[end+1] -= 1;
            }else{
                v[start] -= 1;
                v[end+1] += 1;
            }
         }
         for(int i = 1;i <s.size() ; i++){
            v[i] += v[i-1];
         }
        //  for(auto u:v){
        //     cout << u <<" ";

        //  }
        //  cout <<'\n';
        //  for(int i = 0 ; i < s.size(); i++){
        //     v[i] = (v[i] % 26 + 26 ) % 26;
        //  }
         for(int i = 0 ; i < s.size();i++){
            if(v[i] < 0){
                int x = abs(v[i]) % 26;
                //cout<<"x= "<<x<<endl;
               // x = abs(x);
                char ch = s[i];

                while(x--){
                    if(ch == 'a'){
                        ch = 'z';
                        continue;
                    }
                    ch--;
                }
                s[i] = ch;
            }else if(v[i] > 0){
                int x = ((v[i] % 26) + 26 ) % 26;
                char ch = s[i];
                //cout<<"x = "<<x<<endl;
                while(x--){
                    if(ch == 'z'){
                        ch = 'a';
                        continue;
                    }
                    ch++;
                }
                s[i] = ch;
            }
         }
         return s;
    }
};