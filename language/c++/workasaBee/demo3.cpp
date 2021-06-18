#include <iostream>
#include <vector>
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> c;
        preorder(root, c);
        cout << c[0];
        return c;
    }

    void preorder(TreeNode *ptr, vector<int> &c) {
        if (ptr != nullptr) {
            c.push_back(ptr->val);
        }
        preorder(ptr->left, c);
        preorder(ptr->right, c);
    }
};


void func2(vector<int> &c) {
    c.push_back(8);
}

void func1() {
    vector<int> c;
    func2(c);
//    c.push_back(3);
    cout << c[0];

}


int main() {
    func1();
}
