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
    public IList<string> BinaryTreePaths(TreeNode root) {
        if(root == null)
            return null;

        IList<string> result = new List<string>();
        rec(root, "", result);
        return  result;

    }

    private void rec(TreeNode current, string path, IList<string> result) 
    {
        if(current == null)
            return;

        if(current.left == null && current.right == null)
        {
            result.Add(path + current.val);
            return;
        }

        
        rec(current.left, path + current.val + "->", result);
        rec(current.right, path + current.val + "->", result);
    }
}