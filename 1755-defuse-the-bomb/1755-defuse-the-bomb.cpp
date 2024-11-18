class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int>v(2*n),ans(n,0);
        for(int i = 0;i<2*n;i++){
            int value = code[i%n];
            v[i] = value;
            if(i)v[i] = v[i-1] + v[i];
        }
        int last = n-1, first = n-1-abs(k);

        for(int i=0;i<n;i++){
            if(k>0){
                ans[i] = v[i + k] - v[i];
            }else if(k<0){
                ans[i] = v[last++] - v[first++];
            }else break;
        }
        return ans;
    }
};