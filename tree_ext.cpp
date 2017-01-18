#include <cstddef>
#include <vector>
#include "tree.h"

TreeNode* buildTreeSub(std::vector<int>& inorder, int inBegin, int inEnd, std::vector<int>& postorder, int postBegin, int postEnd) {
    if (0 == postorder.size()) return NULL;

    int rootVal = postorder[postEnd - 1];

    int rootPos;
    for(rootPos = inBegin; rootPos < inEnd; rootPos++) {
        if (inorder[rootPos] == rootVal) break;
    }
    if (rootPos == inEnd) return NULL;

    TreeNode* rootNode = new TreeNode(rootVal);

    int leftNum = rootPos - inBegin;
    int rightNum = inEnd - rootPos - 1;

    rootNode->left = leftNum <= 0 ? NULL : buildTreeSub(inorder, inBegin, rootPos, postorder, postBegin, postBegin + leftNum);
    rootNode->right = rightNum <= 0 ? NULL : buildTreeSub(inorder, rootPos + 1, inEnd, postorder, postBegin + leftNum, postEnd - 1);

    return rootNode;
}

TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
    return buildTreeSub(inorder, 0, inorder.size(), postorder, 0, postorder.size());
}

// 437 Path Sum III You are given a binary tree in which each node contains an
// integer value Find the number of paths that sum to a given value The path
// does not need to start or end at the root or a leaf, but it must go
// downwards (travelling only from parent nodes to child nodes) The tree has no
// more than 1,000 nodes and the value are in the range -1,000,000 to 1,000,000
void pathSumSub(TreeNode* root, std::vector<int>& trace, int& result, int sum) {
    if (NULL == root) return;
    trace.push_back(root->val);
    for(int traceSum = 0, i = trace.size() - 1; i >= 0; i--) {
        traceSum += trace[i];
        if (traceSum == sum) result++;
    }
    pathSumSub(root->left, trace, result, sum);
    pathSumSub(root->right, trace, result, sum);
    trace.pop_back();
}

int pathSum(TreeNode* root, int sum) {
    int result = 0;
    std::vector<int> trace;
    pathSumSub(root, trace, result, sum);
    return result;
}
