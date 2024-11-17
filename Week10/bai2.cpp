/*
Cài đặt giải thuật theo các yêu cầu sau:
+Cấu trúc dữ liệu lưu thông tin về file trong 1 folder 
+Sắp xếp file trong thư mục theo thứ tự tăng dần về dung lượng
+Xoá các file có dung lượng bé nhất và thời gian lưu lâu nhất (ưu tiên xoá trước) (Để tổng size <= 32MB)
*/
#include <iostream>
#include <string>
using namespace std;

struct File { // Cac thong tin cua File: anh.png 2024 10MB
    string nameFile; // .png
    short year; // year
    int size; // MB
};

struct Node { // Node 'file' trong list 'folder'
    File file;
    Node* link;
};

struct Folder {
    Node* first; // 'file' dau tien trong 'folder'
    Node* last; // 'file' cuoi cung trong 'folder'
};

void khoiTao (Folder* folder){ // khoi tao 1 'folder' (list cac Node 'file')
    folder->first = nullptr;
    folder->last = nullptr;
}

Node* taoFile (File F){ // dau vao la cac thong tin cua File 'F'
    Node* f = new Node;
    f->file = F;
    f->link = nullptr;
    return f;
}

void themFile(Folder** folder, File F) {
    Node* newFile = taoFile(F);

    if ((*folder)->first == nullptr) {
        (*folder)->first = newFile;
        (*folder)->last = newFile;
        return;
    }

    if (newFile->file.size < (*folder)->first->file.size || 
       (newFile->file.size == (*folder)->first->file.size && 
        newFile->file.year < (*folder)->first->file.year)) {
        newFile->link = (*folder)->first;
        (*folder)->first = newFile;
        return;
    }

    Node* current = (*folder)->first;
    while (current->link != nullptr && 
          (current->link->file.size < newFile->file.size || 
          (current->link->file.size == newFile->file.size && 
           current->link->file.year < newFile->file.year))) {
        current = current->link;
    }

    newFile->link = current->link;
    current->link = newFile;

    if (newFile->link == nullptr) {
        (*folder)->last = newFile;
    }
}


void xoaFile(Folder** folder) {
    int sumSize = 0;

    Node* current = (*folder)->first;
    while (current != nullptr) {
        sumSize += current->file.size;
        current = current->link;
    }

    while (sumSize > 32 && (*folder)->first != nullptr) {
        Node* temp = (*folder)->first;
        (*folder)->first = (*folder)->first->link;
        sumSize -= temp->file.size;
        delete temp;

        if ((*folder)->first == nullptr) {
            (*folder)->last = nullptr;
        }
    }
}


void hienThiFolder (Folder* folder){
    Node* current = folder->first; // con tro current de duyet folder
    int sumSize = 0; // tinh tong dung luong trong file
    while (current != nullptr) {
        cout << "File: " << current->file.nameFile << ", Year: " << current->file.year << ", Size: " << current->file.size << "MB" << endl;
        sumSize += current->file.size;
        current = current->link;
    }
    cout << "Tong dung luong: " << sumSize << "MB" << endl;
}

int main() {
    Folder* folder = new Folder;
    khoiTao(folder);

    File file1 = {"anh1.png", 2024, 8};
    File file2 = {"anh2.png", 2023, 5};
    File file3 = {"anh3.png", 2023, 18};
    File file4 = {"anh4.png", 2021, 5};

    themFile(&folder, file1);
    themFile(&folder, file2);
    themFile(&folder, file3);
    themFile(&folder, file4);
    
    hienThiFolder (folder);

    xoaFile (&folder);
    cout << "Folder sau khi xoa bot file:" << endl;
    hienThiFolder (folder);

    delete folder;
    return 0;
}
