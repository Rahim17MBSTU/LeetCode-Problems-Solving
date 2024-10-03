class Solution {
public:
    int subarraysDivByK(vector<int>&vv, int k) {
       int n=vv.size();
       vector<int>pre(n+5,0),v(n+5);
       int mp[k+3];
       memset(mp,0,sizeof(mp));
       mp[0]++;
       int ans=0;
       for(int i=1;i<=n;i++){
          v[i]=vv[i-1];
          pre[i]=pre[i-1]+v[i];
       }
       for(int i=1;i<=n;i++)pre[i]%=k;
        for(int i=1;i<=n;i++){
           if(pre[i]<0){
               pre[i]=((pre[i]%k)+k)%k;
           }
           ans+=mp[pre[i]];
           mp[pre[i]]++;
       }
       return ans;
    }
};