class Solution {
public:
    bool check(int &a, int &b , int &c){
        if(a>=1 && b>=1 && c>=1) return 1;
        return 0;
    }
    void Increment(int &a,int &b,int &c,char &ch, bool ok){
        if(ok){
            if(ch == 'a')a++;
            if(ch == 'b')b++;
            if(ch == 'c')c++;
        }else{
            if(ch == 'a')a--;
            if(ch == 'b')b--;
            if(ch == 'c')c--;
        }
    }
    int numberOfSubstrings(string s) {
        int n = s.size(), ans = 0 ;
        int i = 0 , j = 0 ; 
        int a = 0 , b = 0 , c = 0;
        while(j<n){
            while(!check(a,b,c) && j <n){  
                Increment(a,b,c,s[j],true);    
                j++;
            }
            while(check(a,b,c) && i<j){
                Increment(a,b,c,s[i],false);
                i++;
                ans += n-j+1;
            }
        }
        return ans;

    }
};