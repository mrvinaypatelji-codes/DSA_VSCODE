#include <iostream>
#include <vector>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Build Tree
Node* buildTree(vector<int>& preorder) {
    static int idx = -1;

    idx++;

    if (preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);

    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

// Sum of Nodes
int sum(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftSum = sum(root->left);
    int rightSum = sum(root->right);

    return root->data + leftSum + rightSum;
}

int main() {

    vector<int> preorder = {
        1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1
    };

    Node* root = buildTree(preorder);

    cout << "Sum : " << sum(root) << endl;

    return 0;
}