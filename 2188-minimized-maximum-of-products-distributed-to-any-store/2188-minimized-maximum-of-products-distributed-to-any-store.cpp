class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int answer = 0;
       
        int low = 1 ,high = *max_element(quantities.begin(),quantities.end());
        auto f = [&](int mid){
            int cnt = 0;bool ok = 0;
            int extra = 0;
            for(auto u:quantities){
                cnt += ceil(u/(mid*1.0));
            }
           
            if(cnt <= n) return false;
            return true;
        };
        while(low <= high){
            int mid = low + high >> 1;
            if(f(mid)){
                
                low = mid + 1;
            }else{answer = mid ;
                high = mid - 1;
            }
        }
        return answer ;
    }
};