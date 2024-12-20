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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            vector<TreeNode*> node;
            for(int i = 0 ; i < sz;i++){
                TreeNode * current = q.front();
                q.pop();
                node.push_back(current);
                if(current->left!=nullptr){
                    q.push(current->left);
                }
                if(current->right != nullptr){
                    q.push(current->right);
                }
            }
            if(level % 2 ==1){
                for(int i = 0 ; i < sz/2;i++){
                    swap(node[i]->val,node[sz-i-1]->val);
                }
            }
            level++;
        }
        return root;
    }
};