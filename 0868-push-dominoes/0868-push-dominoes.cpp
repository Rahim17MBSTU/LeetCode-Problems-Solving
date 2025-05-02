class Solution {
public:
    string pushDominoes(string s) {
        int n = s.size();
        vector<pair<int,char>>vp;
        for(int i = 0 ;i < n;i++){
            if(s[i] == 'L')vp.push_back({i,'L'});
            else if(s[i] == 'R') vp.push_back({i,'R'});
        }
       
        for(int i = 0 ;i < vp.size();i++){
            
            if(vp[i].second == 'L'){
                int indx = vp[i].first-1;
                while(indx >= 0){
                    if(s[indx] !='.')break;
                    s[indx] = 'L';
                    indx--;
                }
            }else{
                int indx1 = vp[i].first+1;
                int indx2 = n;
                if(i+1 < vp.size() && vp[i+1].second == 'L'){
                    indx2 = vp[i+1].first-1;
                   
                    while(indx2 - indx1 > 0){
                        s[indx1] = 'R';
                        s[indx2] = 'L';
                        indx2--;
                        indx1++;
                    }
                    i++;
                }else{
                     int indx1 = vp[i].first+1;
                     char ch = vp[i].second;
                    while(indx1 < n ){
                        if(s[indx1] !='.')break;
                        s[indx1] = ch;
                        indx1++;
                    }
                }
                
            }
        }
        return s;
    }
};