class Solution {
public:
    string shortestPalindrome(string s) {
         string temp=s,newstr;
    reverse(temp.begin(),temp.end());
    string final="";
    newstr=s+"#"+temp;
    int i=1,len=0;
    int lps[newstr.size()];
    lps[0]=0;
    while(i<newstr.size()){
        if(newstr[i]==newstr[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len>0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }

    int indx=lps[newstr.size()-1];
   string res=newstr.substr(indx,(s.size()-indx));
   reverse(res.begin(),res.end());
   res+=s;
   return res;
    }
};