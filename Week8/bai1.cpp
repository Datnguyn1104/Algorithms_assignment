#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *link;
};

// Them mot Node vao dau List
void themVaoDau (Node** head, int newData){
    Node* newNode = new Node();
    newNode -> data = newData;
    newNode -> link = *head;
    *head = newNode;
}

// Them mot Node vao sau mot Node chi dinh
void themVaoSauNode (Node* p, int newData, int beforeData){
    while (p != nullptr){
        if (p -> data == beforeData){
            Node* newNode = new Node ();
            newNode -> data = newData;
            newNode -> link = p -> link;
            p -> link = newNode;
            return;
        }
        p = p -> link;
    }
    cout << "Khong tim thay node " << beforeData << " can them vao sau" << endl;
}

// Xoa Node cuoi cung cua List
void xoaNodeCuoi (Node*& p){
    if (p != nullptr){
        Node* temp = p;
        while (temp->link->link != nullptr){
            temp = temp->link;
        }
        delete temp->link;
        temp->link = nullptr;
    }
    else cout << "Danh sach trong " << endl;
}

// Xoa Node duoc chi dinh
void xoaNodeChiDinh (Node*& head, int dataDel){
    
    if (head == nullptr){
        cout << "Danh sach trong" << endl;
        return;
    }

    if (head->data == dataDel) {
        Node* temp = head;
        head = head->link;
        delete temp;
        return;
    }

    Node* p = head;
    while (p->link != nullptr && p->link->data != dataDel) {
        p = p->link;
    }

    if (p->link != p) {
        Node* temp = p->link;
        p->link = temp->link;
        delete temp;
    }
    else {
        cout << "Khong tim thay gia tri " << dataDel << " trong danh sach." << endl;
    }
}

void hienThiList (Node* head){
    if (head == nullptr){
        cout << "Danh sach trong" << endl;
        return;
    }
    while (head != nullptr){
        cout << head -> data << "\t";
        head = head -> link;
    }
    cout << endl;
}

int main (){
    Node* head = nullptr;

    // List: 8 9 10
    themVaoDau(&head, 10);
    themVaoDau(&head, 9);
    themVaoDau(&head, 8);
    cout << "List ban dau la: ";
    hienThiList(head);

    bool n = 1;
    while (n==1){
        cout << "Ban co muon them node vao dau List tiep khong? (Co(1)/Khong(0))";
        cin >> n;
        if (n==1){
            int x;
            cout << "Nhap node vao dau List "; 
            cin >> x;
            themVaoDau (&head, x);
            hienThiList (head);
        }
    }
    n=1;
    while (n==1){
        cout << "Ban co muon them node tiep khong? (Co(1)/Khong(0))";
        cin >> n;
        if (n==1){
            int x;
            cout << "Nhap node muon them "; 
            cin >> x;
            int y;
            cout << "Them vao sau node ";
            cin >> y;
            themVaoSauNode(head, x, y);
            hienThiList (head);
        }
    }
    n=1;
    while (n==1){
        cout << "Ban co muon xoa node cuoi? (Co(1)/Khong(0))";
        cin >> n;
        if (n==1){
            xoaNodeCuoi(head);
            hienThiList(head);
        }
    }

    n=1;
    while (n==1){
        cout << "Ban co muon xoa 1 Node? (Co(1)/Khong(0))";
        cin >> n;
        if (n==1){
            int del;
            cout << "Node muon xoa ";
            cin >> del;
            xoaNodeChiDinh(head,del);
            hienThiList(head);
        }
    }
}