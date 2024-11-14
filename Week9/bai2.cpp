/*
Bài 2: Một câu tiếng việt cấu thành từ nhiều từ khác nhau. Mỗi từ được lưu thành một node trong một danh sách liên kết đơn
    + Khai báo cấu trúc danh sách liên kết. Các thông tin chứa ở mỗi node sinh viên tự đưa vào để đảm bảo các nội dung sau được thực hiện 
    + Xác định từ xuất hiện nhiều nhất trong câu  
    + Nếu xuất hiện từ láy (cấu thành từ hai từ giống nhau ví dụ: xanh xanh), thực hiện loại bỏ một từ 
    + Thực hiện đếm số từ vựng xuất hiện trong câu. 
*/
#include <iostream>
#include <string>
using namespace std;

//List cac Node la 1 cau gom cac 'word'
struct Node {
    string word;
    int count; // dem tan suat xuat hien cua 1 word trong cau
    Node* next;
    // ham tao 
    Node (const string& W): word(W), count(1), next(nullptr){}
};

void themWord (Node*& node, const string& word){
    Node* temp = node;
    while (temp != nullptr){
        if (temp->word == word){
            temp->count ++;
        }
        temp = temp->next;
    }

    Node* newNode = new Node (word);
    if (node == nullptr){
        node = newNode;
    }
    else {
        Node* p = node;
        while (p->next != nullptr){
            p = p->next;
        }
        p->next = newNode;
    }
}

void hienThiCau (Node* node){
    Node* temp = node;
    while (temp != nullptr){
        cout << temp->word;
        if (temp->next != nullptr){
            cout << " ";
        }
        temp = temp->next;
    }
    cout << "\n";
}

int demSoTuTrongCau (Node* node){
    int Count = 0;
    Node* temp = node;
    while (temp != nullptr){
        Count++;
        temp = temp->next;
    }
    return Count;
}

void timTuXuatHienNhieuNhat (Node* node){
    Node* temp = node;
    Node* tuXuatHienNhieuNhat = nullptr;
    int maxCount = 0;

    while (temp != nullptr){
        if (temp->count > maxCount){
            maxCount = temp->count;
            tuXuatHienNhieuNhat = temp;
        }
        temp = temp->next;
    }

    if (maxCount == 1) cout << "Tat ca cac tu trong cau chi xuat hien duy nhat mot lan!" << endl;
    else if (tuXuatHienNhieuNhat != nullptr){
        cout << "Tu " << '"' << tuXuatHienNhieuNhat->word << '"' << " xuat hien nhieu nhat voi " << tuXuatHienNhieuNhat->count << " lan" << endl;
    }
}

//xoa node phia sau node (xoa tieng thu 2 cua tu lay)
void xoaMotNode (Node*& node){
    Node* temp = node->next;
    node->next = temp->next;
    delete temp;
}

void timVaXoaTuLay(Node*& node){
    Node* temp = node;
    bool coTuLayToanBo = 0;
    while (temp != nullptr && temp->next != nullptr){
        if (temp->word == temp->next->word){
            coTuLayToanBo = 1;
            xoaMotNode(temp);  // xoa tieng thu 2 cua tu lay
        } else temp = temp->next;
    }
    if (coTuLayToanBo == 1){
        cout << "\nCau sau khi xoa mot tieng trong tu lay la:" << endl;
        hienThiCau (node);
    }
    else cout << "Khong co tu lay toan bo nao trong cau!" << endl;
}


int main (){
    Node* node = nullptr;
    string cau;

    cout << "Nhap mot cau tieng Viet (viet thuong khong dau): ";
    getline (cin, cau);

    string word;
    for (size_t i=0; i<=cau.size(); i++){
        if (i == cau.size() || cau[i] == ' '){
            if (!word.empty()){
                themWord (node, word);
                word.clear();
            }
        }
        else word += cau[i];
    }

    cout << "So tu xuat hien trong cau la: " << demSoTuTrongCau(node) << " tu" << endl;

    timTuXuatHienNhieuNhat (node);

    timVaXoaTuLay (node);

    return 0;
}