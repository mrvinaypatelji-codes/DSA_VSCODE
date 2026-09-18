#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Check whether node is leaf
bool isLeaf(Node* node) {
    return (node->left == NULL && node->right == NULL);
}

// Add left boundary
void addLeftBoundary(Node* root, vector<int>& res) {
    Node* cur = root->left;

    while (cur) {
        if (!isLeaf(cur))
            res.push_back(cur->data);

        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

// Add right boundary
void addRightBoundary(Node* root, vector<int>& res) {
    Node* cur = root->right;
    vector<int> tmp;

    while (cur) {
        if (!isLeaf(cur))
            tmp.push_back(cur->data);

        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }

    // Reverse right boundary
    for (int i = tmp.size() - 1; i >= 0; i--) {
        res.push_back(tmp[i]);
    }
}

// Add all leaf nodes
void addLeaves(Node* root, vector<int>& res) {

    if (isLeaf(root)) {
        res.push_back(root->data);
        return;
    }

    if (root->left)
        addLeaves(root->left, res);

    if (root->right)
        addLeaves(root->right, res);
}

// Boundary Traversal
vector<int> printBoundary(Node* root) {

    vector<int> res;

    if (root == NULL)
        return res;

    // Root
    if (!isLeaf(root))
        res.push_back(root->data);

    // Left boundary
    addLeftBoundary(root, res);

    // Leaf nodes
    addLeaves(root, res);

    // Right boundary
    addRightBoundary(root, res);

    return res;
}

int main() {

    // Create tree
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Boundary traversal
    vector<int> ans = printBoundary(root);

    // Print answer
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}