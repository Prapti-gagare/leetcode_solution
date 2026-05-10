#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        traverse(root, ans);

        return ans;
    }

private:
    void traverse(TreeNode* root, vector<int>& ans) {
        if (root == NULL)
            return;
        traverse(root->left, ans);
        ans.push_back(root->val);
        traverse(root->right, ans);
    }
};

int main() {

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;

    vector<int> result = obj.inorderTraversal(root);

    cout << "Inorder Traversal: ";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}