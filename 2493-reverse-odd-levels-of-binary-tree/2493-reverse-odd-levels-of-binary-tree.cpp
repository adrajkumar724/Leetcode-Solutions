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
    void helper(TreeNode *node1,TreeNode* node2,int level){
        if(!node1 || !node2)
            return ;

        if(level & 1){
            int data=node1->val;
            node1->val=node2->val;
            node2->val=data;
        }
        helper(node1->left,node2->right,level+1);
        helper(node1->right,node2->left,level+1);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {

        helper(root->left,root->right,1);

        return root;
        
    }
};