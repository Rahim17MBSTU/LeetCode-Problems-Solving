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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        root->val = 0;
        while(!q.empty()){
            int sz = q.size();
            vector<TreeNode*>Level;
            int totalSum = 0;
            for(int i = 0 ; i < sz; i++){
                TreeNode* temp = q.front();
                q.pop();
                Level.push_back(temp);
                if(temp->left){

                    totalSum += temp->left->val;
                    q.push(temp->left);

                }if(temp->right){

                    totalSum += temp->right->val;
                    q.push(temp->right);

                }
            }

            for(auto temp:Level){
                int sum = totalSum;
                if(temp->left){
                    sum -= temp->left->val;
                }if(temp->right){
                    sum -= temp->right->val;
                }
                
                if(temp->left){
                    temp->left->val = sum;
                }if(temp->right){
                    temp->right->val = sum;
                }
            }
        }
        return root;
    }
};