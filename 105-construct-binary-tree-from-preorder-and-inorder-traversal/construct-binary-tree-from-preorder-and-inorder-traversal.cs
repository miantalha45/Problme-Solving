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
    Dictionary<int, int> map = new();
    public TreeNode BuildTree(int[] preorder, int[] inorder) {
        for(int i = 0;i < inorder.Length; i++)
        {
            map.Add(inorder[i], i);
        }
        int preIdx = 0;
        return Build(preorder, inorder,ref preIdx, 0, inorder.Length - 1);
    }
    private TreeNode Build(int[] preorder, int[] inorder,ref int preIdx, int left, int right)
    {
        if(left > right)    return null;

        TreeNode root = new TreeNode(preorder[preIdx]);
        int inIdx = map[preorder[preIdx]];
        preIdx++;

        root.left = Build(preorder, inorder,ref preIdx, left, inIdx - 1);
        root.right = Build(preorder, inorder,ref preIdx, inIdx + 1, right);

        return root;
    }
}