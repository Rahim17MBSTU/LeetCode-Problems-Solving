/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<pair<TreeNode *,int>>q;
        int answer = 0 ; 
        q.push({root,1});
        vector<int>vp;
        set<int>s;
        int lastLevel = 1;
        int level1 = 0;
        while(!q.empty()){
            auto [current,level] = q.front();
            level1= level;
            q.pop();
            if(lastLevel<level){
                unordered_map<int,int>mp;
                int indx = 0;
                for(auto u:vp){
                    mp[u] = indx++;
                }
                indx = 0;
                for(auto u:s){
                    if(u == vp[indx]){
                        indx++;
                        continue;
                    }
                    int cnt = mp[u];
                    int i = mp[vp[indx]];
                    mp[vp[indx]] = cnt;
                    swap(vp[cnt],vp[i]);
                    mp[u] = i; 
                    
                    answer++;
                    indx++;
                }
                
                 lastLevel = level;
               
                mp.clear();
                s.clear();
                vp.clear();
            }
            if(current->left!=nullptr){
                q.push({current->left,level+1});
               
                    vp.push_back(current->left->val);
                    s.insert(current->left->val);
               
                
            }if(current->right!=nullptr){
                q.push({current->right,level+1});
                
                     vp.push_back(current->right->val);
                    s.insert(current->right->val);
            
            }
            
        }
        if(lastLevel<level1){
               
              
                unordered_map<int,int>mp;
                int indx = 0;
                for(auto u:vp){
                    mp[u] = indx++;
                }
                indx = 0;
                indx = 0;
                for(auto u:s){
                  
                    if(u == vp[indx]){
                        indx++;
                        continue;
                    }
                    int cnt = mp[u];
                    int i = mp[vp[indx]];
                    mp[vp[indx]] = cnt;
                    swap(vp[cnt],vp[i]);
                    mp[u] = i; 
                    
                    answer++;
                    indx++;
                }
              
            }
        return answer;
    }
};