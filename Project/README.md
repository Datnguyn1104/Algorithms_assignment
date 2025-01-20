# Mô tả Thuật Toán Tìm Kích Thước Lớn Nhất Của Ma Trận Vuông Con Toàn Số 1

## Bài Toán: Cho một ma trận nhị phân (chỉ chứa các phần tử 0 và 1), hãy tìm kích thước lớn nhất của ma trận vuông con chỉ chứa số 1.

### Giải Thuật: Thuật toán sử dụng quy hoạch động để tính kích thước ma trận vuông con tại mỗi vị trí trong ma trận.

Input: Ma trận nhị phân mat kích thước M x N
Output: maxSize - kích thước lớn nhất của ma trận vuông con toàn số 1

#### Nếu M = 0 hoặc N = 0: Trả về 0
#### Tạo mảng lookup kích thước M x N
#### maxSize = 0
#### Duyệt qua từng phần tử mat[i][j] với i từ 0 đến M-1, j từ 0 đến N-1:
   ##### Nếu i = 0 hoặc j = 0:
       lookup[i][j] = mat[i][j]
   ##### Ngược lại, nếu mat[i][j] = 1:
       lookup[i][j] = min(lookup[i][j-1], lookup[i-1][j], lookup[i-1][j-1]) + 1
   ##### Ngược lại:
       lookup[i][j] = 0
   ##### Cập nhật maxSize = max(maxSize, lookup[i][j])
#### Trả về maxSize

###Ứng dụng: Xử lý hình ảnh và thị giác máy tính, phát hiện các vùng có chung đặc điểm, phân loại vùng ảnh...