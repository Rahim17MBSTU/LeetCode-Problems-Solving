class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int>v;
        vector<pair<int,pair<int,pair<char,int>>>>vp;
        for(int i=0;i<n;i++){
            vp.push_back(make_pair(positions[i],make_pair(healths[i],make_pair(directions[i],i))));

        }
        sort(vp.begin(),vp.end());
        stack<pair<int,pair<char,int>>>st;
        vector<pair<int,int>>res;
        for(auto u:vp){
            int pos = u.first;
            int health = u.second.first;
            char dir = u.second.second.first;
            int indx =  u.second.second.second;
            if(st.empty()){
                if(dir == 'L'){
                    res.push_back({indx,health});
                    continue;
                }
                st.push(make_pair(health,make_pair(dir,indx)));continue;
            }
            if(dir == 'L' && !st.empty()&& st.top().second.first == 'R'){
                bool ok = 0;
                while(!st.empty() && st.top().second.first == 'R'){
                   
                  int R_health = st.top().first;
                    char R_dir = st.top().second.first;
                    int R_indx = st.top().second.second;
                    
                    if(R_health == health){
                        ok = 0;
                        st.pop();
                        break;
                    }else if(R_health > health){
                        st.pop();
                        st.push({R_health-1,{R_dir,R_indx}});
                        ok = 0;
                        break;
                    }else{
                        st.pop();
                        health--;
                        ok = 1;
                        
                    }
                }
                if(ok == 1){
                   res.push_back({indx,health});
                    
                }
               

            }else{
               if(dir == 'L'){
                    res.push_back({indx,health});
                    continue;
                }
                st.push({health,{dir,indx}});
            }
            
        }
        while(!st.empty()){
            
            int health = st.top().first;
            int indx = st.top().second.second;
            res.push_back({indx,health});
            
            st.pop();
        }
        sort(res.begin(),res.end());
        for(auto u:res){
            int value = u.second;
            v.push_back(value);
        }
        
        return v;
    }
};