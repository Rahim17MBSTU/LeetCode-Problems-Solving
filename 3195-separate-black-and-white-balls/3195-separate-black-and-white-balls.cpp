class Solution {
public:
    long long minimumSteps(string s) {
        int cnt = 0;
        long long  answer = 0;
        for(int i = 0 ; i < s.size();i++){
            if(s[i] == '0'){
                answer += (i-cnt);cnt++;
            }
        }
        return answer;
    }
};