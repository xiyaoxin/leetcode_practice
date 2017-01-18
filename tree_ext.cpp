#include <cstddef>
#include <vector>
#include <limits>
#include <algorithm>
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

// 124 Binary Tree Maximum Path Sum Given a binary tree, find the maximum path
// sum For this problem, a path is defined as any sequence of nodes from
// starting node to any node in the tree along the parent-child connections.
// The path must contain at least one node and does not need to go through the
// root
int maxPathSumHelper(TreeNode* root, int& result) {
    if (NULL == root) return 0;
    else {
        int leftSum = maxPathSumHelper(root->left, result);
        int rightSum = maxPathSumHelper(root->right, result);

        leftSum = leftSum > 0 ? leftSum : 0;
        rightSum = rightSum > 0 ? rightSum : 0;

        result = std::max(result, root->val + leftSum + rightSum);
        return root->val + std::max(leftSum, rightSum);
    }
}

int maxPathSum(TreeNode* root) {
    int result = std::numeric_limits<int>::min();
    maxPathSumHelper(root, result);
    return result;
}
