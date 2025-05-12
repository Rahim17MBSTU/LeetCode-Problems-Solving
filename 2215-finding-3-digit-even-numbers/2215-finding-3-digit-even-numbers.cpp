class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>digitFrequency(11,0);
        for(auto u:digits)digitFrequency[u]++;
        set<string>s;
        for(int i = 0 ;i <= 9; i++){
            if(digitFrequency[i] == 0)continue;
            for(int j = 0; j <= 9;j++){

                if(digitFrequency[j] == 0)continue;
                if(i == j && digitFrequency[j] < 2)continue;

                for(int k = 0 ;k<=9 ;k++){
                    if(digitFrequency[k] == 0)continue;
                    if(i == j && j == k && i == k && digitFrequency[k] < 3)continue;
                    
                    if(i == k &&  j != i && digitFrequency[k] < 2)continue;
                    if(j == k && i != k && digitFrequency[k] < 2)continue;

                    string str = "";
                    str += to_string(i);str += to_string(j); str += to_string(k);
                    sort(str.begin(),str.end());
                    do{
                        if(str[0] != '0' && (str[2]-'0') % 2 == 0){
                            s.insert(str);
                            //cout<<str<<" ";
                        }
                    }while(next_permutation(str.begin(),str.end()));
                    
                }
            }
        }
        vector<int>result;
        for(auto u:s) result.push_back(stoi(u));
        return result;
    }
};