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
// class Solution {
// public:
//     unordered_map<int, int> inorderMap;  // Stores inorder indices for quick lookup
//     int postIndex;  // Tracks the current root position in postorder array

//     // Recursive function to build the binary tree
//     TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int left, int right) {
//         if (left > right) return nullptr;  // Base case: If range is invalid, return NULL

//         // Select root value from postorder (last element in current range)
//         int rootVal = postorder[postIndex--];
//         TreeNode* root = new TreeNode(rootVal);

//         // Get root index from inorder map
//         int inIndex = inorderMap[rootVal];

//         // Build right subtree first (postorder visits left subtree last)
//         root->right = buildTreeHelper(inorder, postorder, inIndex + 1, right);
//         root->left = buildTreeHelper(inorder, postorder, left, inIndex - 1);

//         return root;
//     }

//     // Main function to construct the tree
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         postIndex = postorder.size() - 1;  // Start from the last element of postorder
//         for (int i = 0; i < inorder.size(); i++) {
//             inorderMap[inorder[i]] = i;  // Store inorder index for fast lookup
//         }
//         return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1);
//     }
// };

class Solution {
public:
    int postIndex;  // Tracks current index in postorder array

    // Helper function to find index of value in inorder array
    int search(vector<int>& inorder, int value, int left, int right) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == value) return i;
        }
        return -1; // Should never happen as the value is guaranteed to be present
    }
// 9126603466
// 3
    // Recursive function to construct tree
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int left, int right) {
        if (left > right) return nullptr;  // Base case

        // Pick the current root from postorder (last element)
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        // Find root index in inorder array
        int inIndex = search(inorder, rootVal, left, right);

        // Build right subtree first, then left subtree
        root->right = buildTreeHelper(inorder, postorder, inIndex + 1, right);
        root->left = buildTreeHelper(inorder, postorder, left, inIndex - 1);

        return root;
    }

    // Main function to build tree
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = postorder.size() - 1; // Start from the last element of postorder
        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1);
    }
};