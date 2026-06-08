#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int diameter = 0;

int height(Node* root) {
    if (root == NULL)
        return 0;

    int leftH = height(root->left);
    int rightH = height(root->right);

    if (leftH + rightH > diameter)
        diameter = leftH + rightH;

    return 1 + (leftH > rightH ? leftH : rightH);
}

int countNode(Node* root) {
    if (root == NULL)
        return 0;

    return 1 + countNode(root->left) + countNode(root->right);
}

int main() {

    cout << "=========================================\n";
    cout << "     PROGRAM DIAMETER BINARY SEARCH TREE\n";
    cout << "=========================================\n\n";

    int N;
    cout << "Masukkan jumlah node : ";
    cin >> N;

    Node* root = NULL;

    cout << "Masukkan " << N << " angka unik:\n";

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    cout << "\n=========================================\n";
    cout << "BST berhasil dibuat\n";
    cout << "=========================================\n";

    cout << "Traversal Inorder : ";
    inorder(root);

    cout << "\nJumlah Node      : " << countNode(root);

    height(root);

    cout << "\nDiameter BST     : " << diameter << " edge";

    cout << "\n=========================================\n";
    cout << "Jarak terjauh antar dua node = "
         << diameter << " edge\n";
    cout << "=========================================\n";

    return 0;
}