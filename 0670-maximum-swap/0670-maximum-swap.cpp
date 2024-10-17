class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        string temp = s;
        sort(s.begin(),s.end());
        reverse(s.begin(),s.end());
        cout << s <<endl;
        cout <<temp<<endl;
        vector<int>v[10];
        for(int i=0;i<temp.size();i++){
            v[temp[i]-'0'].push_back(i);
        }
        for(int i=0;i<temp.size();i++){
            if(temp[i]!=s[i]){
                swap(temp[i],temp[v[s[i]-'0'].back()]);
                break;
            }
        }
     
        return stoi(temp);
    }
};