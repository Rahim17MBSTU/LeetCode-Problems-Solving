class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i=0;i<n;i++){
            
            string temp = s;
            s += "1";
            reverse(temp.begin(),temp.end());
            for(auto u:temp){
                s += (u=='1'?'0':'1');
            }
            cout << s <<endl;
            if(s.size() >= k){
                break;
            }
        }
        cout<<s<<endl;
        return s[k-1];
    }
};