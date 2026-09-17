#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(vector<int>& arr, int& idx) {

    idx++;

    if (arr[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(arr[idx]);

    root->left = buildTree(arr, idx);
    root->right = buildTree(arr, idx);

    return root;
}

bool isSameTree(Node* p, Node* q) {

    if (p == NULL || q == NULL) {
        return p == q;
    }

    bool isLeftSame = isSameTree(p->left, q->left);

    bool isRightSame = isSameTree(p->right, q->right);

    return isLeftSame && isRightSame && p->val == q->val;
}

int main() {

    vector<int> tree1 = {
        1, 2, -1, -1, 3, -1, -1
    };

    vector<int> tree2 = {
        1, 2, -1, -1, 3, -1, -1
    };

    int idx1 = -1;
    int idx2 = -1;

    Node* p = buildTree(tree1, idx1);
    Node* q = buildTree(tree2, idx2);

    if (isSameTree(p, q)) {
        cout << "Both trees are same";
    }
    else {
        cout << "Both trees are not same";
    }

    return 0;
}