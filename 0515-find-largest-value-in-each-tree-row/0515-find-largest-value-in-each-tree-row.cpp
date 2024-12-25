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
    vector<int> largestValues(TreeNode* root) {
        vector<int>res;
        if(root == nullptr){
            return res;
        }
        queue<pair<TreeNode* ,int>>q;
        q.push({root,0});
        int CurrentLevel = 0;
        int mx = INT_MIN;
        
        while(!q.empty()){
            auto [Current,Level] = q.front();
            q.pop();
            if(Level == CurrentLevel){
                mx = max(Current->val,mx);
            }else{
                res.push_back(mx);
                mx = Current->val;
                CurrentLevel = Level;
            }
            if(Current->left!= nullptr){
                q.push({Current->left,Level+1});
            }if(Current->right != nullptr){
                q.push({Current->right,Level+1});
            }
        }
        res.push_back(mx);
        return res;
    }
};