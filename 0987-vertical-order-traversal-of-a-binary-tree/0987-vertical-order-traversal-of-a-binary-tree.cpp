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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes;
        //used multiset because automatically sort nodes at the exact same position
        queue<pair<TreeNode*,pair<int,int>>> q;
        vector<vector<int>> ans;

        if(root == NULL) return ans;
        q.push(make_pair(root,make_pair(0,0)));

        while(!q.empty()){
            pair<TreeNode*,pair<int,int>>temp = q.front();
            q.pop();
            TreeNode* frontNode = temp.first;

            int horizontalDis = temp.second.first;
            int lvl = temp.second.second;
            // Use .insert() instead of .push_back() for multiset
            nodes[horizontalDis][lvl].insert(frontNode->val);

            if(frontNode->left)
                q.push(make_pair(frontNode->left,make_pair(horizontalDis-1,lvl+1)));

            if(frontNode->right)
                q.push(make_pair(frontNode->right,make_pair(horizontalDis+1,lvl+1)));
        }
        for(auto i:nodes){
            vector<int> col;
            for(auto j:i.second){
                for(auto k:j.second){
                    col.push_back(k);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};