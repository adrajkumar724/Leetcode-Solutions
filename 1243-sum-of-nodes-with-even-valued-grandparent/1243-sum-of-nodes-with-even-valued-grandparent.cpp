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
    int sumEvenGrandparent(TreeNode* root) {

        int sum=0;
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root,NULL});


        while(!q.empty()){
            auto it=q.front();
            q.pop();

            TreeNode *node=it.first;


            TreeNode *par=it.second;



            if(par!=NULL && par->val%2==0){
                if(node->left)
                    sum+=node->left->val;

                if(node->right)
                    sum+=node->right->val;
            }

            if(node->left){
                q.push({node->left,node});
            }
            if(node->right){
                q.push({node->right,node});
            }
        }

        return sum;
        
    }
};