class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int i=0,j=skill.size()-1;
        long long answer  = 0;
        sort(skill.begin(),skill.end());
        int equal = skill[0] + skill[j];
        while(i<j){
            if(skill[i] + skill[j] == equal){
                answer +=(skill[i] * skill[j]);
                i++;
                j--;
            }else{
                return -1;
            }
        }
        return answer;
    }
};