#ifndef TREE_H
#define TREE_H

// Definition for binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// delete a tree
void deleteTree(TreeNode* root);

// inorder traverse a tree
std::vector<int> inorderTraverseTree(TreeNode* root);

// preorder traverse a tree
std::vector<int> preorderTraverseTree(TreeNode* root);

// postorder traverse a tree
std::vector<int> postorderTraverseTree(TreeNode* root);

#endif
