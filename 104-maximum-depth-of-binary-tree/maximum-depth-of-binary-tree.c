/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
   
    if (root == NULL)
        return 0;
    else
    {
        int leftVal = maxDepth(root->left);
        int rightVal = maxDepth(root->right);
        if (leftVal > rightVal)
        {
            return leftVal + 1;
        }
        else
        {
            return rightVal + 1;
        }
    }
}