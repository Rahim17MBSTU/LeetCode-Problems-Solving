class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>mp;
        unordered_map<string,int>dis;
        
        for(auto u:wordList){
            string s = u;
            mp.insert(s);
            dis[s] = 1e9;
        }
        
        int n = wordList.size();

        queue<string>q;

        q.push(beginWord);
        dis[beginWord] = 1;

        while(!q.empty()){

            string str = q.front();
            q.pop();

            for(int j = 0 ;j<str.size();j++){

                string temp = str;

                for(char i = 'a'; i<='z'; i++){
                    temp[j] = i;

                    if(mp.find(temp)!=mp.end() && dis[str] < dis[temp]){
                    
                    dis[temp] = min(dis[temp],dis[str]+1);
                    q.push(temp);
                        
                }
              }
            }
            
        }
    
        return dis[endWord] == 1e9 ? 0 : dis[endWord] ;
       
    }
};