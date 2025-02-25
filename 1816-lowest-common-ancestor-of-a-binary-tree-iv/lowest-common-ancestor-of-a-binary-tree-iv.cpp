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
    pair<int, TreeNode*> recursion (TreeNode* root, set<int> &target) {
        pair<int, TreeNode*> left = {-1, nullptr};
        pair<int, TreeNode*> right = {-1, nullptr};
        if (root->left != nullptr) left = recursion(root->left, target);
        if (root->right != nullptr) right = recursion(root->right, target);

        pair<int, TreeNode*> ret = {0, root};
        if (left.first == target.size() || right.first == target.size()) {
            ret.first = target.size();
            if (left.first == target.size()) {
                ret.second = left.second;
            }
            else {
                ret.second = right.second;
            }
        }
        else {
            if (root->left != nullptr) ret.first += left.first;
            if (root->right != nullptr) ret.first += right.first;
            if (target.find(root->val) != target.end()) ret.first++;
        }

        return ret;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        set<int> target;
        for (auto node : nodes) target.insert(node->val);
        return recursion(root, target).second;
    }
};