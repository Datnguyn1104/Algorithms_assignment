/*
Quản lý kho gỗ (xếp chồng các thanh gỗ trong kho): loại gỗ, kích thước, tuổi gỗ
Cài đặt danh sách loại gỗ trong kho kiểu stack
-> Đếm số lượng thanh gỗ cùng tuổi gỗ
*/
#include <iostream>
#include <string>
using namespace std;
#define MAX 5

struct CayGo { // Các thông tin của một cây gỗ
    string loaiGo;
    short chuVi;
    short tuoiGo;
};

struct khoGo { // Kho chứa các cây gỗ
    int top;
    CayGo cayGo[MAX];
};

void khoiTao(khoGo* kho) {
    kho->top = 0;
}

bool isEmpty(khoGo* kho) {
    return kho->top == 0;
}

bool isFull(khoGo* kho) {
    return kho->top == MAX;
}

void push(khoGo* kho, CayGo cay) { // Xếp 1 cây gỗ mới lên trên
    if (isFull(kho)) {
        cout << "Kho go da day" << endl;
    } else {
        kho->cayGo[kho->top++] = cay;
    }
}

CayGo pop(khoGo* kho) { // Lấy ra cây ở trên cùng của khoGo
    if (isEmpty(kho)) {
        cout << "Kho go trong" << endl;
    } else {
        return kho->cayGo[--kho->top];
    }
}

void nhapGo(khoGo* kho) {
    if (isFull(kho)) {
        cout << "Kho go da day khong the nhap them" << endl;
        return;
    }
    CayGo cay_push;
    cout << "Nhap thong tin cay go" << endl;
    cout << "Loai go ";
    cin.ignore();
    getline(cin, cay_push.loaiGo);
    cout << "Chu vi cay go cm ";
    cin >> cay_push.chuVi;
    cout << "Tuoi cua cay go ";
    cin >> cay_push.tuoiGo;
    push(kho, cay_push);
}

void hienThiKho(khoGo* kho) {
    if (isEmpty(kho)) {
        cout << "Kho go trong" << endl;
        return;
    }
    cout << "Cac cay go trong kho" << endl;
    for (int i = 0; i < kho->top; i++) {
        cout << "Go " << kho->cayGo[i].loaiGo
             << " Chu vi " << kho->cayGo[i].chuVi << " cm"
             << " " << kho->cayGo[i].tuoiGo << " tuoi" << endl;
    }
}

int demGoCungTuoi(khoGo* kho, short tuoi) {
    int count = 0;
    for (int i = 0; i < kho->top; i++) {
        if (kho->cayGo[i].tuoiGo == tuoi) {
            count++;
        }
    }
    return count;
}

int main() {
    khoGo* Kho = new khoGo;
    khoiTao(Kho);
    CayGo cay1 = {"Sua do", 50, 100};
    CayGo cay2 = {"Mun", 68, 86};
    CayGo cay3 = {"Dan huong", 48, 66};
    push(Kho, cay1);
    push(Kho, cay2);
    push(Kho, cay3);

    int luaChon;
    do {
        cout << "Quan ly kho go" << endl;
        cout << "1. Nhap go vao kho" << endl;
        cout << "2. Hien thi go trong kho" << endl;
        cout << "3. Dem so luong go cung tuoi" << endl;
        cout << "4. Thoat" << endl;
        cout << "Nhap lua chon ";
        cin >> luaChon;

        switch (luaChon) {
            case 1: {
                nhapGo(Kho);
                break;
            }
            case 2: {
                hienThiKho(Kho);
                break;
            }
            case 3: {
                if (isEmpty(Kho)) {
                    cout << "Kho go trong!" << endl;
                } else {
                    short tuoi;
                    cout << "Nhap tuoi go can dem ";
                    cin >> tuoi;
                    int soLuong = demGoCungTuoi(Kho, tuoi);
                    cout << "So luong go cung tuoi la " << soLuong << endl;
                }
                break;
            }
            case 4: {
                cout << "Thoat chuong trinh" << endl;
                break;
            }
            default: {
                cout << "Lua chon khong hop le!" << endl;
                break;
            }
        }
    } while (luaChon != 4);

    delete Kho;

    return 0;
}
