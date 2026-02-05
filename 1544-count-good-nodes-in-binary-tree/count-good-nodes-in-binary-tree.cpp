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
    int goodNodes(TreeNode* root) {
        return maxNode(root, root->val);
    }
    int maxNode(TreeNode* root, int maxVal) {
        if(!root) return 0;

        int res = 0;
        if(maxVal <= root->val) {
            res++;
        }
        maxVal = max(maxVal, root->val);
        res += maxNode(root->left, maxVal);
        res += maxNode(root->right, maxVal);

        return res;
    }
};