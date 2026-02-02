class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Empty tree: no path
        if (root == nullptr) {
            return false;
        }
        
        // Leaf node: check if this node's value equals remaining target
        if (root->left == nullptr && root->right == nullptr) {
            return root->val == targetSum;
        }
        
        // Recurse on children with updated target (subtract current val)
        int remaining = targetSum - root->val;
        bool leftPath = hasPathSum(root->left, remaining);
        bool rightPath = hasPathSum(root->right, remaining);
        
        // True if ANY child path works
        return leftPath || rightPath;
    }
};
