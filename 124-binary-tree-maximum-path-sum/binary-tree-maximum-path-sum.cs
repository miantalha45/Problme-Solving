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
    public int MaxPathSum(TreeNode root) {
        int maxSum = int.MinValue;

        dfs(root, ref maxSum);
        return maxSum;
    }

    private int dfs(TreeNode node, ref int maxSum)
    {
        if(node == null)
            return 0;
        
        int leftMax = Math.Max(dfs(node.left, ref maxSum), 0);

        int rightMax = Math.Max(dfs(node.right, ref maxSum), 0);

        maxSum = Math.Max(maxSum, node.val + leftMax + rightMax);

        return node.val + Math.Max(leftMax, rightMax);
    }
}