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
    #define ll long long 
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {

        priority_queue<ll,vector<ll>,greater<ll>>minheap;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            ll levelSum = 0;
            int size = q.size();
           // cout << "size = "<<size <<" -> ";
            for(int i = 0 ; i < size ;i++){
                TreeNode* curr = q.front();
                q.pop();
                levelSum += curr->val;
                //cout << curr->val <<" ";
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
           // cout<<endl;
            minheap.push(levelSum);
            if(minheap.size()>k)
                minheap.pop();
        }
        if(minheap.size() < k)
        return -1;
        return minheap.top();
    }
};