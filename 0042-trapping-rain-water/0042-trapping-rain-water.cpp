class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>v(n,0),v1(n,0);
        int ans = 0;
        int front_mx = 0,back_mx = 0;
        for(int i = 0 ;i<n;i++){
           front_mx = max(front_mx, height[i]);v[i] = front_mx; 
           back_mx = max(back_mx, height[n-1-i]);v1[n-1-i] = back_mx;
        }
        // for(int i=0;i<n;i++){
        //     cout<<v[i]<<" "<<v1[i]<<endl;
        // }
        // cout<<endl;
        for(int i=0;i<n;i++){
            ans += abs(height[i] - min(v1[i],v[i])) ;
        }
        return ans;
    }
};