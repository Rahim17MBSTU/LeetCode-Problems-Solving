class Solution {
public:
    int answer = 1;
    unordered_map<int,int>parent,size,mp;

    void make(int v){
        parent[v] = v;
        size[v] = 1;
        }
    int find(int v){
        if(v == parent[v]) return v;
        // path compression
        return parent[v] = find(parent[v]);
    }
    void Union(int a,int b){
        a = find(a);
        b = find(b);
        if(a != b){
        // union by size
        if(size[a]<size[b]) swap(a,b);
        parent[b] = a;
        size[a]+=size[b];
       
        } 
        answer = max({answer,size[a],size[b]});
    }
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        
        for(auto u:nums){
            make(u);
           
        }
        int n = nums.size();
        for(int i=0;i<n;i++){
            int back = nums[i] - 1;
            int value = nums[i] ;
            int front = nums[i] + 1; 
            
            if(mp[back]>=1){
                mp[back]++;
                Union(back,value);
                
            }
            
            if(mp[front]>=1){
                mp[front]++;
              
                Union(value, front);
            }
            mp[value]++;
        }
        
        return answer;
    }
};