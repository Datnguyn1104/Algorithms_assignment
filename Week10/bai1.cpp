/*Cài đặt giải thuật xoá node trong 1 danh sách ở 3 vị trí: Đầu danh sách, cuối danh sách và sau 1 node cho trước*/
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

// xoa Node cuoi cung cua List
void xoaNodeCuoi (Node*& head){
    if (head != nullptr){
        Node* temp = head;
        while (temp->link->link != nullptr){
            temp = temp->link;
        }
        delete temp->link;
        temp->link = nullptr;
    }
    else cout << "Danh sach trong!" << endl;
}

void xoaNodeDau (Node*& head){
    if (head != nullptr){
        Node* temp = head;
        head = head->link;
        delete temp;
    }
    else cout << "Danh sach trong!" << endl;
}

// xoa Node sau node duoc chi dinh
void xoaNodeSauBefDel (Node*& head, int befDel){
    if (head == nullptr){
        cout << "Danh sach trong!" << endl;
        return;
    }

    Node* p = head; // tim node co data la befDel
    while (p->link != nullptr && p->data != befDel){
        p = p->link;
    }

    if (p->link != nullptr){
        Node* temp = p->link;
        p->link = temp->link;
        delete temp;
    }
    else {
        cout << "Khong ton tai Node " << befDel << " hoac khong con Node nao sau Node " << befDel << "!" << endl;
    }
}

void hienThiList (Node* head){
    if (head == nullptr){
        cout << "Danh sach trong!" << endl;
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

    // List: 5 6 7 8 9 10
    themVaoDau(&head, 10);
    themVaoDau(&head, 9);
    themVaoDau(&head, 8);
    themVaoDau(&head, 7);
    themVaoDau(&head, 6);
    themVaoDau(&head, 5);
    cout << "List ban dau la: ";
    hienThiList(head);

    bool n = 1;
    while (n==1){
        cout << "Ban co muon xoa node cuoi khong? (Co(1)/Khong(0))";
        cin >> n;
        if (n==1){
            xoaNodeCuoi(head);
            hienThiList(head);
        }
    }

    n=1;
    while (n==1){
        cout << "Ban co muon xoa node dau tien khong? (Co(1)/Khong(0))";
        cin >> n;
        if (n==1){
            xoaNodeDau(head);
            hienThiList(head);
        }
    }

    n=1;
    while (n==1){
        cout << "Ban co muon xoa 1 Node sau 1 Node chi dinh khong? (Co(1)/Khong(0))";
        cin >> n;
        if (n==1){
            int befDel;
            cout << "Node truoc Node muon xoa la: ";
            cin >> befDel;
            xoaNodeSauBefDel(head,befDel);
            hienThiList(head);
        }
    }
}