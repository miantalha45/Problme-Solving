/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */

public class Solution {
    public TreeNode LowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(p.val < root.val && q.val < root.val)
            root = LowestCommonAncestor(root.left, p, q);
        else if(p.val > root.val && q.val > root.val)
            root = LowestCommonAncestor(root.right, p, q);
        
        return root;
    }
}