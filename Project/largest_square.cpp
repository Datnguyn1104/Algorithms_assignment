#include <iostream>
using namespace std;

// tìm min (a, b, c)
int min(int a, int b, int c)
{
    int m = a;
    if (b < m) m = b;
    if (c < m) m = c;
    return m;
}

// Hàm tìm kích thước lớn nhất của ma trận vuông con toàn số 1
int findLargestSquare(int** mat, int M, int N)
{
    // trường hợp ma trận rỗng
    if (M == 0 || N == 0) {
        return 0;
    }

    // Cấp phát động mảng lưu kích thước lớn nhất của ma trận vuông kết thúc tại mat[i][j]
    int** lookup = new int*[M];
    for (int i = 0; i < M; i++) {
        lookup[i] = new int[N];
    }

    // Biến lưu kích thước lớn nhất của ma trận vuông con toàn số 1
    int maxSize = 0;

    // duyệt qua ma trận để điền giá trị vào mảng lookup
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // Nếu ở hàng đầu tiên hoặc cột đầu tiên
            if (i == 0 || j == 0) {
                lookup[i][j] = mat[i][j];
            }
            // Nếu phần tử hiện tại là 1
            else if (mat[i][j] == 1) {                                                                  
                lookup[i][j] = min(lookup[i][j - 1], lookup[i - 1][j], lookup[i - 1][j - 1]) + 1;       //size[i][j] = min(size[i-1][j], size[i][j-1], size[i-1][j-1]) + 1 bởi vì để tạo được hình vuông kích thước k+1, cần có 3 hình vuông kích thước k ở trên, trái và chéo trên 
            }
            else {
                lookup[i][j] = 0;
            }

            // update kích thước lớn nhất tìm được
            if (maxSize < lookup[i][j]) {
                maxSize = lookup[i][j];
            }
        }
    }

    // giải phóng bộ nhớ
    for (int i = 0; i < M; i++) {
        delete[] lookup[i];
    }
    delete[] lookup;

    // return kích thước lớn nhất của ma trận vuông con toàn số 1
    return maxSize;
}

int main()
{
    // kích thước của ma trận
    int M = 8, N = 6;

    // ma trận đầu vào
    int** mat = new int*[M];
    for (int i = 0; i < M; i++) {
        mat[i] = new int[N];
    }

    // Gán giá trị cho ma trận
    int input[8][6] = {
        { 0, 0, 1, 0, 1, 1 },
        { 0, 1, 1, 1, 0, 0 },
        { 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1 },
        { 1, 1, 0, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1 }
    };

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            mat[i][j] = input[i][j];
        }
    }

    cout << "Kich thuoc cua ma tran vuong toan so 1 lon nhat la: "
         << findLargestSquare(mat, M, N) << endl;

    // Giải phóng bộ nhớ cấp phát cho ma trận
    for (int i = 0; i < M; i++) {
        delete[] mat[i];
    }
    delete[] mat;

    return 0;
}
