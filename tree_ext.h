#ifndef TREE_EXT
#define TREE_EXT

TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder);

// 437 Path Sum III You are given a binary tree in which each node contains an
// integer value Find the number of paths that sum to a given value The path
// does not need to start or end at the root or a leaf, but it must go
// downwards (travelling only from parent nodes to child nodes) The tree has no
// more than 1,000 nodes and the value are in the range -1,000,000 to 1,000,000
void pathSum(TreeNode* root, std::vector<int>& trace, int& result, int sum); 
#endif
