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
    public int KthSmallest(TreeNode root, int k) {
        int n = 0;
        Stack<TreeNode> s = new();
        TreeNode cur = root;
        while(s.Count > 0 || cur != null)
        {
            while(cur != null)
            {
                s.Push(cur);
                cur = cur.left;
            }
            cur = s.Pop();
            n += 1;
            if(n == k)
                return cur.val;
            cur = cur.right;
        }

        return -1;
    }
}