/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public bool IsBalanced(TreeNode root) {
        if(root == null)
            return true;

        return checkHeight(root) != -1;
    }

    private int checkHeight(TreeNode root) 
    {
        if(root == null)    return 0;
        int lh = checkHeight(root.left);
        int rh = checkHeight(root.right);

        if(lh == -1 || rh == -1)
            return -1;
        
        if (Math.Abs(lh - rh) > 1) return -1;

        return Math.Max(lh, rh) + 1;
    }
}