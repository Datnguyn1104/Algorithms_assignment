/*
Bài 1:  Nhập vào n đối tượng có màu đỏ (red), trắng (white) và xanh (blue),
sắp xếp theo trật tự như sau: các đối tượng cùng mầu nằm kế tiếp nhau và theo thứ tự đỏ, trắng, xanh.
Input {xanh, đỏ, xanh, đỏ, đỏ, trắng, đỏ, xanh, trắng}
Output {đỏ, đỏ, đỏ, đỏ, trắng, trắng, xanh, xanh, xanh}
Gợi ý:
Có thể mã hóa các mầu bằng các số nguyên 0, 1, 2 để biểu diễn lần lượt mầu đỏ, trắng và xanh tương ứng.
Chú ý: Không sử dụng các thư viện hàm sắp xếp có sẵn để giải quyết bài toán trên khi cài đặt chương trình
Bài 2: Thiết kế giải thuật và cài đặt để tạo ra một mảng số nửa nguyên tố (Blum) nhỏ hơn một số N cho trước và thực hiện hai yêu cầu sau
- Tìm ra tất cả các cặp số Blum có tổng cũng là một số Blum nhỏ hơn N
- Kiểm tra xem một số Blum M có tồn tại trong dãy số Blum được tạo ra hay không.
*/
#include <iostream>
using namespace std;

enum color {red = 0, white = 1, blue = 2};

void Arrange (color Colors[9]){
    for (int i=0; i<9; i++){
        color min = Colors[i];
        int id_min;
        for (int j=i+1; j<9; j++){
            if (min > Colors[j]){
                min = Colors[j];
                id_min = j;
            }
        }
        if (Colors[i] == min) continue;
        Colors[id_min] = Colors[i];
        Colors[i] = min;
    }
}

void Display (color Colors[9]){
    for (int i=0; i<9; i++){
        if (Colors[i] == red) {
            cout << "red ";
        } else if (Colors[i] == white) {
            cout << "white ";
        } else if (Colors[i] == blue) {
            cout << "blue ";
        }
    }
}

int main (){
    color Colors[9] = {blue, red, blue, red, red, white, red, blue, white};
    Arrange (Colors);
    Display (Colors);
    return 0;
}