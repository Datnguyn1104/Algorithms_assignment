#include <iostream>
using namespace std;

struct Ngay{
    int ngay, thang, nam;
};

struct SinhVien{
    char maSV[9];
    char hoTen[50];
    int gioiTinh;
    Ngay ngaySinh;
    char diaChi[100];
    char lop[12];
    char khoa[7];    
};

struct Node{
    SinhVien data;
    Node* link;
};

struct List{
    Node* first;
    Node* last;
};

void khoiTao (List& listSV){
    listSV.first = nullptr;
    listSV.last = nullptr;
}

Node* taoNode (SinhVien sv){
    Node* p = new Node;
    p->data = sv;
    p->link = nullptr;
    return p;
}

// Hàm so sánh MSSV. Nếu maSV1 < maSV2 thì trả về 1 và ngược lại. nếu là 1 thì ghép vào đầu listSV
bool soSanhMSSV (char maSV1[], char maSV2[]){
    int i = 0;
    while (maSV1[i] != '\0' && maSV2[i] != '\0'){
        if (maSV1[i] < maSV2[i]) return 1;
        if (maSV1[i] > maSV2[i]) return 0;
        i++;
    }
    return maSV1[i] == '\0' && maSV2[i] != '\0';
}

void themSinhVien (List& listSV, SinhVien sv){
    // p là sinh viên cần thêm
    Node* p = taoNode(sv);

    // nếu listSV trống thì p vừa là đầu vừa là cuối
    if (listSV.first == nullptr){
        listSV.first = listSV.last = p;
    }
    // nếu p bé hơn MSSV đầu listSV thì chèn p vào đầu
    else if (soSanhMSSV(sv.maSV, listSV.first->data.maSV)){
        p->link = listSV.first;
        listSV.first = p;
    }
    else {
        //p1 và p2 là 2 sinh viên trong listSV trước. Chạy p1 và p2 để tìm vị trí cho p: (p1 p p2)
        Node* p1 = listSV.first;
        Node* p2 = listSV.first->link;
        
        while (p2 != nullptr && soSanhMSSV (p2->data.maSV, sv.maSV)){
            p1 = p2;
            p2 = p2->link;
        }
        
        p->link = p2;
        p1->link = p;

        if (p2 == nullptr){
            listSV.last = p;
        }
    }
}

void hienThiDanhSach (const List& listSV){
    Node* p = listSV.first;
    while (p != nullptr) {
        cout << "MSSV: " << p->data.maSV << ", HO TEN: " << p->data.hoTen << ", GIOI TINH: ";
        switch (p->data.gioiTinh){
            case 0:
                cout << "Nu";
                break;
            case 1:
                cout << "Nam";
                break;
        }
        cout << ", NGAY SINH: " << p->data.ngaySinh.ngay << "/" << p->data.ngaySinh.thang << "/" << p->data.ngaySinh.nam;
        cout << ", DIA CHI: " << p->data.diaChi;
        cout << ", LOP: " << p->data.lop << ", KHOA: " << p->data.khoa << endl;
        p = p->link;
    }
}

SinhVien nhapSinhVien() {
    SinhVien sv;

    cout << "Nhap ma sinh vien (8 chu so): ";
    cin.ignore();
    cin.getline(sv.maSV, 9);

    cout << "Nhap ho va ten: ";
    cin.getline(sv.hoTen, 50);

    cout << "Nhap gioi tinh (1 - Nam, 0 - Nu): ";
    cin >> sv.gioiTinh;

    cout << "Nhap ngay sinh:" << endl;
    cout << "  Ngay: ";
    cin >> sv.ngaySinh.ngay;
    cout << "  Thang: ";
    cin >> sv.ngaySinh.thang;
    cout << "  Nam: ";
    cin >> sv.ngaySinh.nam;

    cin.ignore();
    cout << "Nhap dia chi: ";
    cin.getline(sv.diaChi, 100);

    cout << "Nhap lop: ";
    cin.getline(sv.lop, 12);

    cout << "Nhap khoa: ";
    cin.getline(sv.khoa, 7);

    return sv;
}

void timSinhVienCungNgaySinh(const List& listSV) {
    Node* p = listSV.first;
    Ngay ngayDaXuatHien[100];
    int demNgay = 0;
    bool found = false;

    while (p != nullptr) {
        bool daXuatHien = false;
        for (int i = 0; i < demNgay; i++) {
            if (ngayDaXuatHien[i].ngay == p->data.ngaySinh.ngay &&
                ngayDaXuatHien[i].thang == p->data.ngaySinh.thang &&
                ngayDaXuatHien[i].nam == p->data.ngaySinh.nam) {
                daXuatHien = true;
                break;
            }
        }

        if (!daXuatHien) {
            int count = 0;
            Node* q = p;
            while (q != nullptr) {
                if (p->data.ngaySinh.ngay == q->data.ngaySinh.ngay &&
                    p->data.ngaySinh.thang == q->data.ngaySinh.thang &&
                    p->data.ngaySinh.nam == q->data.ngaySinh.nam) {
                    count++;
                }
                q = q->link;
            }
            if (count > 1) {
                cout << "Cac sinh vien co ngay sinh " << p->data.ngaySinh.ngay << "/"
                     << p->data.ngaySinh.thang << "/" << p->data.ngaySinh.nam << " la:" << endl;

                q = p;
                while (q != nullptr) {
                    if (p->data.ngaySinh.ngay == q->data.ngaySinh.ngay &&
                        p->data.ngaySinh.thang == q->data.ngaySinh.thang &&
                        p->data.ngaySinh.nam == q->data.ngaySinh.nam) {
                        cout << "Ma SV: " << q->data.maSV << ", Ho Ten: " << q->data.hoTen << ", Lop: " << q->data.lop << endl;
                    }
                    q = q->link;
                }
                cout << endl;
                found = true;
            }
            ngayDaXuatHien[demNgay++] = p->data.ngaySinh;
        }
        p = p->link;
    }

    if (!found) {
        cout << "Khong tim thay sinh vien cung ngay sinh!" << endl;
    }
}

void xoaSinhVienCungNgaySinh(List& listSV) {
    Node* p = listSV.first;
    Ngay ngayDaXoa[100];
    int demNgay = 0;

    while (p != nullptr) {
        bool daXoa = false;
        for (int i = 0; i < demNgay; i++) {
            if (ngayDaXoa[i].ngay == p->data.ngaySinh.ngay &&
                ngayDaXoa[i].thang == p->data.ngaySinh.thang &&
                ngayDaXoa[i].nam == p->data.ngaySinh.nam) {
                daXoa = true;
                break;
            }
        }

        if (!daXoa) {
            int count = 0;
            Node* q = p;
            while (q != nullptr) {
                if (p->data.ngaySinh.ngay == q->data.ngaySinh.ngay &&
                    p->data.ngaySinh.thang == q->data.ngaySinh.thang &&
                    p->data.ngaySinh.nam == q->data.ngaySinh.nam) {
                    count++;
                }
                q = q->link;
            }

            if (count > 1) {
                cout << "Xoa cac sinh vien co ngay sinh " << p->data.ngaySinh.ngay << "/"
                     << p->data.ngaySinh.thang << "/" << p->data.ngaySinh.nam << endl;

                Node* prev = nullptr;
                Node* current = listSV.first;

                while (current != nullptr) {
                    if (current->data.ngaySinh.ngay == p->data.ngaySinh.ngay &&
                        current->data.ngaySinh.thang == p->data.ngaySinh.thang &&
                        current->data.ngaySinh.nam == p->data.ngaySinh.nam) {
                        Node* temp = current;
                        if (prev == nullptr) {
                            listSV.first = current->link;
                        } else {
                            prev->link = current->link;
                        }
                        current = current->link;
                        delete temp;
                    } else {
                        prev = current;
                        current = current->link;
                    }
                }
                if (prev != nullptr && prev->link == nullptr) {
                    listSV.last = prev;
                }
                ngayDaXoa[demNgay++] = p->data.ngaySinh;
            }
        }
        p = p->link;
    }

    cout << "Hoan tat xoa cac sinh vien co ngay sinh trung lap." << endl;
}


int main (){
    List listSV;
    khoiTao(listSV);
    
    SinhVien sv1 = {"20221234", "Nguyen Van A", 1, {1, 1, 2004}, "Bac Giang", "ET1", "ET"};
    SinhVien sv2 = {"20224321", "Nguyen Van B", 0, {2, 2, 2004}, "Ha Noi", "ET2", "IT"};
    SinhVien sv3 = {"20229876", "Nguyen Van C", 1, {3, 3, 2004}, "Thanh Hoa", "ET3", "ET"};
    
    themSinhVien(listSV, sv1);
    themSinhVien(listSV, sv2);
    themSinhVien(listSV, sv3);

    cout << "Danh sach sinh vien:" << endl;
    hienThiDanhSach(listSV);
    cout << endl;

    bool ask = 1;
    while (ask == 1){
        cout << "Ban co muon nhap them sinh vien khong? (1 - Co, 0 - Khong) ";
        cin >> ask;
        if (ask == 0) break;
        SinhVien sv = nhapSinhVien ();
        themSinhVien (listSV, sv);
    }

    cout << "Danh sach sinh vien moi: " << endl;
    hienThiDanhSach(listSV);
    cout << endl;

    ask = 1;
    while (ask == 1){
        cout << "Ban co muon tim cac sinh vien co cung ngay sinh khong? (1 - Co, 0 - Khong) ";
        cin >> ask;
        if (ask == 0) break;
        timSinhVienCungNgaySinh (listSV);
        ask = 0;
    }

    ask = 1;
    while (ask == 1){
        cout << "Ban co muon xoa cac sinh vien co cung ngay sinh khong? (1 - Co, 0 - Khong) ";
        cin >> ask;
        if (ask == 0) break;
        xoaSinhVienCungNgaySinh (listSV);
        ask = 0;
    }

    cout << "Danh sach sinh vien moi: " << endl;
    hienThiDanhSach (listSV);

    return 0;
}