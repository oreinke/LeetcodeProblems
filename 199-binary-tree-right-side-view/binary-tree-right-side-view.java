/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> result = new ArrayList<Integer>();
        
        if (root == null)
        {
            return result;
        }

        result.add(root.val);

        treeTraversal(root.right, 1, result);
        treeTraversal(root.left, 1, result);
        return result;
    }

    public static void treeTraversal(TreeNode node, int numNode, List<Integer> result)
    {
        if (node == null)
        {
            return;
        }
        
        numNode++;
        if (result.size() < numNode)
        {
            result.add(node.val);
        }

        treeTraversal(node.right, numNode, result);
        treeTraversal(node.left, numNode, result);
    }
}