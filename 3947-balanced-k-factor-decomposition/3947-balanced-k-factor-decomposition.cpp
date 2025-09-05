class Solution {
public:
    vector<int>factor,answer;
vector<int>factorPath;
int mn = 1e9;
void calculation(int n,int k,int indx = 0){
    if(factorPath.size()+1 == k){
        vector<int>res = factorPath;
        res.push_back(n);
        sort(res.begin(),res.end());
        if(mn >= res[res.size()-1] - res[0]){
            mn = res[res.size()-1] - res[0];
            answer = res;
        }
        return;
    }
    for(int i = indx ;i < factor.size();i++){
        if(n% factor[i] == 0){
            factorPath.push_back(factor[i]);
            calculation(n/factor[i],k,i);
            factorPath.pop_back();
        }
    }
}
    vector<int> minDifference(int n, int k) {
        for(int i = 1;1LL*i*i<=n;i++){
        if(n% i == 0){
            factor.push_back(i);
            if(n/i != i){
                factor.push_back(n/i);
            }
        }
     }
     sort(factor.begin(),factor.end());
     calculation(n,k);
        return answer;
    }
};