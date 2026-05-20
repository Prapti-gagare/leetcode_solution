#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    int minDepth(TreeNode* root) {

        if (root == NULL) {
            return 0;
        }

        if (root->left == NULL) {
            return minDepth(root->right) + 1;
        }

        if (root->right == NULL) {
            return minDepth(root->left) + 1;
        }

        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);

        return min(leftDepth, rightDepth) + 1;
    }
};

int main() {

   
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);

    Solution obj;

    cout << "Minimum Depth of Binary Tree: "
         << obj.minDepth(root);

    return 0;
}