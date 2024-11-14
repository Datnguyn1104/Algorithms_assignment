/*
Bài 1: Định nghĩa một cấu trúc danh sách liên kết đơn để lưu trữ các file trong một thư mục D>Document trên máy tính.
Các file được sắp xếp theo trật tự thời gian.
    Sau đó thực hiện tao tác:
        + Khai báo cấu trúc của danh sách liên kết.
    Các thông tin chứa ở mỗi node sinh viên tự đưa vào để đảm bảo các nội dung sau được thực hiện 
        + Copy paste một file từ thư mục khác sang thư mục trên sao do file luôn được chèn vào theo trật tự thời gian  
        + Thực hiện tính toán kích thước các file trong thư mục 
        + Người ta muốn sao lưu các file trong thư mục trên vào một ổ USB có kích thước 32G.
    Hãy thực hiện loại bỏ dần nếu cần một số file có kích thước nhỏ nhất để có thể thực hiện được thao tác trên.  
*/
// Em xin lỗi cô, nhưng em chưa hiểu ý của đề bài ạ!

#include <iostream>
#include <string>
using namespace std;

struct Date {
    int YYYY, MM, DD;
};

struct File {
    string fileName;
    long size;
    Date date;
    File* next;
    
    File(const string& name, long s, const Date& d)
        : fileName(name), size(s), date(d), next(nullptr) {}
};

void hienThi(File* file) {
    File* temp = file;
    while (temp != nullptr) {
        cout << "File Name: " << temp->fileName << endl;
        cout << "File Size: " << temp->size << " bytes" << endl;
        cout << "Date: " << temp->date.YYYY << "-" << temp->date.MM << "-" << temp->date.DD << endl;
        temp = temp->next;
    }
}

int main() {
    File testFile("test.cpp", 1024, {2022, 1, 11});
    hienThi(&testFile);
    return 0;
}
