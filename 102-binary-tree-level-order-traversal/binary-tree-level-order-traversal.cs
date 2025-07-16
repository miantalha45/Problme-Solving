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
    public IList<IList<int>> LevelOrder(TreeNode root) {
        if(root == null)
            return [];

        IList<IList<int>> result = new List<IList<int>>();
        Queue<TreeNode> q = new();

        q.Enqueue(root);
        while(q.Count > 0)
        {
            int n = q.Count;
            IList<int> res = new List<int>();
            for(int i = 1;i <= n; i++)
            {
                TreeNode node = q.Dequeue();
                res.Add(node.val);
                if(node.left != null)
                    q.Enqueue(node.left);
                if(node.right != null)
                    q.Enqueue(node.right);
            }
            result.Add(res);
        }

        return result;
    }
}