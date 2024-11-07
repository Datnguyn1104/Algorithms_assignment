#include <iostream>
using namespace std;

struct soHang {
    int heso;
    int bac;
    soHang* link;
};

void themSoHang(soHang** head, int heso, int bac) {
    soHang* newSoHang = new soHang();
    newSoHang->heso = heso;
    newSoHang->bac = bac;
    newSoHang->link = nullptr;

    if (*head == nullptr) {
        *head = newSoHang;
    } else {
        soHang* temp = *head;
        while (temp->link != nullptr) {
            temp = temp->link;
        }
        temp->link = newSoHang;
    }
}

void nhapDaThuc(soHang** head, int bacDaThuc) {
    int heSo;
    for (int i = bacDaThuc; i >= 0; i--) {
        do {
            cout << "Nhap he so cho x^" << i << " = ";
            cin >> heSo;
        } while (i == bacDaThuc && heSo == 0);
        themSoHang(head, heSo, i);
    }
}

void hienThiDaThuc(soHang* head) {
    soHang* temp = head;
    if (head == nullptr){
        cout << " 0" << endl;
        return;
    }
    bool first = 1;
    while (temp != nullptr) {
        if (temp->heso != 0) {
            if (!first) {
                cout << (temp->heso > 0 ? " + " : " - ");
            } else if (temp->heso < 0) {
                cout << "- ";
            }
            if (abs(temp->heso) != 1 || temp->bac == 0) { 
                cout << abs(temp->heso); 
            }
            if (temp->bac > 0) {
                cout << "x";
                if (temp->bac > 1) cout << "^" << temp->bac;
            }
            first = 0;
        }
        temp = temp->link;
    }
    cout << endl;
}

soHang* tongDaThuc(soHang* f, soHang* g) {
    soHang* head = nullptr;
    soHang* p1 = f;
    soHang* p2 = g;

    while (p1 != nullptr || p2 != nullptr) {
        int bac = 0, heso = 0;
        if (p1 != nullptr && (p2 == nullptr || p1->bac > p2->bac)) {
            bac = p1->bac;
            heso = p1->heso;
            p1 = p1->link;
        } else if (p2 != nullptr && (p1 == nullptr || p2->bac > p1->bac)) {
            bac = p2->bac;
            heso = p2->heso;
            p2 = p2->link;
        } else {
            bac = p1->bac;
            heso = p1->heso + p2->heso;
            p1 = p1->link;
            p2 = p2->link;
        }
        if (heso != 0) {
            themSoHang(&head, heso, bac);
        }
    }
    return head;
}

int main() {
    soHang* f = nullptr;
    soHang* g = nullptr;
    soHang* h = nullptr;
    int bacDaThuc;

    cout << "Nhap bac cua f(x): ";
    cin >> bacDaThuc;
    cout << "Nhap da thuc f(x):" << endl;
    nhapDaThuc(&f, bacDaThuc);

    cout << "Nhap bac cua g(x): ";
    cin >> bacDaThuc;
    cout << "Nhap da thuc g(x):" << endl;
    nhapDaThuc(&g, bacDaThuc);

    h = tongDaThuc(f, g);

    cout << "f(x) = ";
    hienThiDaThuc(f);
    cout << "g(x) = ";
    hienThiDaThuc(g);
    cout << "h(x) = ";
    hienThiDaThuc(h);

    return 0;
}