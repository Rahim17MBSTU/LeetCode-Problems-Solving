class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        map<int,int>mp1,mp2;
        int mx1 = 0, mx2 = 0, ans = -1, mx_cnt1 = 0 , mx_cnt2 = 0;
        for(auto u:tops){
            mp1[u]++;
            if(mx_cnt1 <= mp1[u]){
                mx_cnt1 = mp1[u];
                mx1 = u;
            }
           
        }
        for(auto u:bottoms){
            mp2[u]++;
            if(mx_cnt2 <= mp2[u]){
                mx_cnt2 = mp2[u];
                mx2 = u;
            }
        }
        bool ok1 = 0, ok2 = 0;
        int cnt1 = 0 , cnt2 = 0;
        for(int i=0;i<tops.size();i++){
            if(tops[i] == mx1)continue;
            else if(bottoms[i] == mx1)cnt1++;
            else ok1 = 1;
        }
        for(int i=0;i<tops.size();i++){
            if(bottoms[i] == mx2)continue;
            else if(tops[i] == mx2)cnt2++;
            else ok2 = 1;
        }
        cout<<mx1<<" "<<mx2<<endl;
        if(ok1 == 1 && ok2 == 1)return -1;
        if(ok1 == 1 && ok2 == 0)return cnt2;
        if(ok1 == 0 && ok2 == 1)return cnt1;
        if(ok1 == 0 && ok2 == 0)return min(cnt1,cnt2);
        return cnt1;
    }
};