/*
Cài đặt cây AVL với các hàm theo yêu cầu sau:
Khai báo cấu trúc cây AVL
Cài đặt hàm thực hiện các phép xoay đơn, xoay kép để cân bằng cây 
Cài đặt hàm bổ sung thêm một node mới trên cây AVL 
Sử dụng mảng cho trên lớp (240 73 101 21 13 25 11 37 89 30 15 51)
để làm bộ kiểm tra đầu vào, in ra cây AVL theo từng bước bổ sung thêm phân tử theo các phép duyệt cây 
*/

#include <iostream>
using namespace std;

struct AvlNode {
    int elem;
    AvlNode* left;
    AvlNode* right;
    int height;

    AvlNode(int e, AvlNode* l = nullptr, AvlNode* r = nullptr, int h = 0)
        : elem(e), left(l), right(r), height(h) {}
};

int height(AvlNode* t){
    return t == nullptr ? -1 : t->height;
}

// xoay don trai trai
void rotateWithLeftChild(AvlNode*& k2){
    AvlNode* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), height(k2)) + 1;
    k2 = k1;
}

// xoay don phai phai
void rotateWithRightChild(AvlNode*& k2){
    AvlNode* k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->right), height(k2)) + 1;
    k2 = k1;
}

// xoay kep trai phai
void doubleWithLeftChild(AvlNode*& k3){
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

// xoay kep phai trai
void doubleWithRightChild(AvlNode*& k3){
    rotateWithLeftChild(k3->right);
    rotateWithRightChild(k3);
}

// can bang
void balance(AvlNode*& t){
    if (t == nullptr) return;

    if (height(t->left) - height(t->right) > 1) {
        if (height(t->left->left) >= height(t->left->right)) {
            rotateWithLeftChild(t);
        } else {
            doubleWithLeftChild(t);
        }
    } else if (height(t->right) - height(t->left) > 1) {
        if (height(t->right->right) >= height(t->right->left)) {
            rotateWithRightChild(t);
        } else {
            doubleWithRightChild(t);
        }
    }

    t->height = max(height(t->left), height(t->right)) + 1;
}

// chen 1 phan tu
void insert(int x, AvlNode*& t){
    if (t == nullptr) {
        t = new AvlNode(x);
    } else if (x < t->elem) {
        insert(x, t->left);
    } else if (x > t->elem) {
        insert(x, t->right);
    }

    balance(t);
}

// in cay AVL (goc tu ben trai, cac node con ben phai)
void printTree(AvlNode* t, int space = 0, int indent = 4) {
    if (t == nullptr) return;

    space += indent;
    printTree(t->right, space);

    cout << endl;
    for (int i = indent; i < space; ++i) cout << " ";
    cout << t->elem << "\n";

    printTree(t->left, space);
}

int main() {
    AvlNode* root = nullptr;

    int arr[] = {240, 73, 101, 21, 13, 25, 11, 37, 89, 30, 15, 51};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; ++i){
        insert(arr[i], root);
        cout << "Sau khi chen " << arr[i] << ":\n";
        printTree(root);
        cout << "\n";
    }

    return 0;
}
