/*
Quản lý kho gỗ (xếp chồng các thanh gỗ trong kho): loại gỗ, kích thước, tuổi gỗ
Cài đặt danh sách loại gỗ trong kho kiểu stack
-> Đếm số lượng thanh gỗ cùng tuổi gỗ
*/
#include <iostream>
#include <string>
using namespace std;
#define MAX 10

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

void pushVaoDay(khoGo* kho, CayGo cay) { // Xếp cây gỗ mới vào đáy
    if (isFull(kho)) {
        cout << "Kho go da day!" << endl;
    } else {
        for (int i = kho->top; i > 0; i--) { // Dịch các phần tử lên trên
            kho->cayGo[i] = kho->cayGo[i - 1];
        }
        kho->cayGo[0] = cay;
        kho->top++; 
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

void nhapGoVaoDay(khoGo* kho) {
    if (isFull(kho)) {
        cout << "Kho go da day, khong the nhap them" << endl;
    } else {
        CayGo cay_push;
        cout << "Nhap thong tin cay go" << endl;
        cout << "Loai go ";
        cin.ignore();
        getline(cin, cay_push.loaiGo);
        cout << "Chu vi cay go cm ";
        cin >> cay_push.chuVi;
        cout << "Tuoi cua cay go ";
        cin >> cay_push.tuoiGo;
        pushVaoDay(kho, cay_push);
    }
}

void hienThiKho(khoGo* kho) {
    if (isEmpty(kho)) {
        cout << "Kho go trong!" << endl;
        return;
    }
    cout << "Cac cay go trong kho" << endl;
    for (int i = 0; i < kho->top; i++) {
        cout << "Go " << kho->cayGo[i].loaiGo
             << ", Chu vi " << kho->cayGo[i].chuVi << " cm"
             << ", " << kho->cayGo[i].tuoiGo << " tuoi" << endl;
    }
}

void hienThiKhoTuTop (khoGo* kho){
    if (isEmpty (kho)){
        cout << "Kho go trong!" << endl;
        return;
    }
    cout << "Cac cay go theo thu tu tu tren xuong" << endl;
    for (int i=kho->top-1; i>=0; i--){
        cout << "Go " << kho->cayGo[i].loaiGo
             << ", Chu vi " << kho->cayGo[i].chuVi << " cm"
             << ", " << kho->cayGo[i].tuoiGo << " tuoi" << endl;
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
    CayGo cay1 = {"Gu", 50, 10};
    CayGo cay2 = {"Lim", 70, 20};
    CayGo cay3 = {"Soi", 100, 10};
    CayGo cay4 = {"Soi", 45, 35};
    push(Kho, cay1);
    push(Kho, cay2);
    push(Kho, cay3);
    push(Kho, cay4);

    int luaChon;
    do {
        cout << "\nQuan ly kho go" << endl;
        cout << "1. Nhap go vao kho" << endl;
        cout << "2. Hien thi go trong kho (nhap truoc hien thi truoc)" << endl;
        cout << "3. Hien thi go trong kho (theo thu tu tu tren xuong)" << endl;
        cout << "4. Dem so luong go cung tuoi" << endl;
        cout << "5. Nhap go vao day kho go" << endl;
        cout << "6. Thoat" << endl;
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
                hienThiKhoTuTop(Kho);
                break;
            }
            case 4: {
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
            case 5: {
                cout << "Nhap go vao day kho" << endl;
                nhapGoVaoDay (Kho);
                break;
            }
            case 6: {
                cout << "Thoat chuong trinh" << endl;
                break;
            }
            default: {
                cout << "Lua chon khong hop le!" << endl;
                break;
            }
        }
    } while (luaChon != 6);

    delete Kho;

    return 0;
}
