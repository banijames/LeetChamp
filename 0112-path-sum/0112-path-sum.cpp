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
private:
    bool solve(TreeNode* root, int targetSum,int ans){
        if(root == NULL) return false;

        ans+=root->val;

        if(root->left == NULL && root->right == NULL){
            return ans==targetSum;
        }

        bool left = solve(root->left,targetSum,ans);
        bool right = solve(root->right,targetSum,ans);
        return left||right;    
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,targetSum,0);
    }
};