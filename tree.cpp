#include <cstddef>
#include <vector>
#include "tree.h"

// delete a tree
void deleteTree(TreeNode *root) {
    if (NULL == root) return;
    else {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

// inorder traverse tree
void inorderHelper(TreeNode* root, std::vector<int>& vec) {
    if (NULL == root) return;
    else {
        inorderHelper(root->left, vec);
        vec.push_back(root->val);
        inorderHelper(root->right, vec);
    }
}
std::vector<int> inorderTraverseTree(TreeNode* root) {
   std::vector<int> result;
   inorderHelper(root, result);
   return result;
}

// preorder traverse tree
void preorderHelper(TreeNode* root, std::vector<int>& vec) {
    if (NULL == root) return;
    else {
        vec.push_back(root->val);
        inorderHelper(root->left, vec);
        inorderHelper(root->right, vec);
    }
}
std::vector<int> preorderTraverseTree(TreeNode* root) {
    std::vector<int> result;
    preorderHelper(root, result);
    return result;
}

// postorder traverse tree
void postorderHelper(TreeNode* root, std::vector<int>& vec) {
    if (NULL == root) return;
    else {
        postorderHelper(root->left, vec);
        postorderHelper(root->right, vec);
        vec.push_back(root->val);         
    }
}
std::vector<int> postorderTraverseTree(TreeNode* root, std::vector<int>& vec) {
    std::vector<int> result;
    postorderHelper(root, result);
    return result;
}
