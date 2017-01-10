#include <cstddef>
#include <vector>
#include <iostream>
#include "tree.h"
#include "tree_ext.h"
using namespace std;

int main() {
    vector<int> inorder = {1, 2, 3};
    vector<int> postorder = {1, 3, 2};

    TreeNode* tree = buildTree(inorder,  postorder);

    vector<int> traverseResult = preorderTraverseTree(tree);

    for(int i = 0; i < traverseResult.size(); i++) {
        cout << traverseResult[i] << " ";        
    }
    cout << endl;

    deleteTree(tree);

    return 0;
}
