
class Solution {
public:
    
    string minWindow(string s, string t) {
        
        int n = s.size(), m = t.size();
        
        string result ="";
        int low = 0 , high = s.size() - 1;
        pair<int,int>fre[27];
        pair<int,int>pre[27];
        for(int i = 0 ; i < t.size(); i++){// Capital, small
            if(t[i] >='a' && t[i] <='z'){
                int x = t[i] - 96;
                fre[x].second += 1;
            }else{
                int x = t[i] - 64;
                fre[x].first += 1;
            }
        }
        
    
        int len1 , len2 ;
        len1 = len2 = -1;
        auto check = [&](){
            for(int i=1;i<=26;i++){
                if(pre[i].first >= fre[i].first && pre[i].second >= fre[i].second){
                    continue;
                }else{
                    return false;
                }
            }
            return true;
        };
        auto f = [&](int mid){
            fill(pre, pre + 27, make_pair(0, 0));
            for(int i = 0 ; i <=mid;i++){
                if(s[i] >='a' && s[i] <='z'){
                    int x = s[i] - 96;
                    pre[x].second += 1;
                }else{
                    int x = s[i] - 64;
                    pre[x].first += 1;
                }
            }
            bool ok = check();
            if(ok) 
            {
                len1 = 0;
                len2 = mid;
                return ok;
            }
            for(int i = 0, j = mid+1;j<n;j++,i++){
                if(s[j] >='a' && s[j] <='z'){
                    int x = s[j] - 96;
                    pre[x].second += 1;
                }else{
                    int x = s[j] - 64;
                    pre[x].first += 1;
                }if(s[i] >='a' && s[i] <='z'){
                    int x = s[i] - 96;
                    pre[x].second -= 1;
                }else{
                    int x = s[i] - 64;
                    pre[x].first -= 1;
                }
                ok = check();
                if(ok){
                    len1 = i+1;
                    len2 = j;
                    return ok;
                }

            }
            return ok;

        };
        cout<<low <<" "<<high<<endl;
        while(low<=high){
         int mid = (low + high) >> 1;
         cout<<mid<<endl;
         if(f(mid)){
            high = mid-1;
         }else{
            low = mid+1;
         }
       } 
       if(len1 == len2 && len1 == -1)
        return result;
        else{
            for(int i=len1 ;i <= len2;i++){
                result += s[i];
            }
            return result;
        }
        
    }
};
