#ifndef TREE_EXT
#define TREE_EXT

TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder);

// 437 Path Sum III You are given a binary tree in which each node contains an
// integer value Find the number of paths that sum to a given value The path
// does not need to start or end at the root or a leaf, but it must go
// downwards (travelling only from parent nodes to child nodes) The tree has no
// more than 1,000 nodes and the value are in the range -1,000,000 to 1,000,000
void pathSum(TreeNode* root, std::vector<int>& trace, int& result, int sum); 

// 124 Binary Tree Maximum Path Sum Given a binary tree, find the maximum path
// sum For this problem, a path is defined as any sequence of nodes from
// starting node to any node in the tree along the parent-child connections.
// The path must contain at least one node and does not need to go through the
// root
int maxPathSum(TreeNode* root); 
#endif
