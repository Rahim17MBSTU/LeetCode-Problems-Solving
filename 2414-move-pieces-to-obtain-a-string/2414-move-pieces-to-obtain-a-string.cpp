class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        //int m = target.size();
        deque<char>dq1,dq2;
        int charCount1 = 0 ,charCount2 = 0;
        for(int i = 0 ; i < n; i++)
        {
            if(start[i] == 'L' || start[i] =='R')charCount1++;
            if(target[i] == 'L' || target[i] =='R')charCount2++;
        }
        if(charCount1 != charCount2)return false;
        int j = 0;
        for(int i = 0 ;i < n;i++){
            if(target[i] == 'L'){
                bool ok = 0;
                while(j<n){
                    if(j<i && target[i] == start[j]){
                        return false;
                    }else if(i <= j && target[i] == start[j]){
                        ok = 1;j++;
                        break;
                    }
                    j++;
                }
                if(ok == 0)return false;
            }else if(target[i] == 'R'){
                bool ok = 0;
                while(j<n){
                    if(i<j && target[i] == start[j]){
                        return false;
                    }else if(j <= i && target[i] == start[j]){
                        ok = 1;
                        j++;
                        break;
                    }
                    j++;
                }
                if(ok == 0)return false;
            }
        }
        return true;
    }
};