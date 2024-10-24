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
    bool calculation(TreeNode* root1, TreeNode* root2){
        if(root1 == nullptr && root2 == nullptr)return true;
        if(root1 == nullptr) return false;
        if(root2 == nullptr) return false;
        if(root1->val == root2->val){
            bool withoutFlip = calculation(root1->left,root2->left) && calculation(root1->right,root2->right);
            bool withFlip = calculation(root1->left,root2->right) && calculation(root1->right,root2->left);
            return withoutFlip | withFlip;
        }else{
            return false;
        }
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return calculation(root1,root2);
    }
};