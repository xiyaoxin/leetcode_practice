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
