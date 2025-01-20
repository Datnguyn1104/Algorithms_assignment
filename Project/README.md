# Mô tả Thuật Toán Tìm Kích Thước Lớn Nhất Của Ma Trận Vuông Con Toàn Số 1

## Bài Toán: Cho một ma trận nhị phân (chỉ chứa các phần tử 0 và 1), hãy tìm kích thước lớn nhất của ma trận vuông con chỉ chứa số 1.

### Giải Thuật: Sử dụng quy hoạch động, với mảng lookup[i][j] lưu kích thứoc ma trận vuông lớn nhất kết thúc tại vị trí (i,j)
Input: Ma trận nhị phân mat kích thước M x N
Output: maxSize - kích thước lớn nhất của ma trận vuông con toàn số 1

#### 1. Nếu M = 0 hoặc N = 0: Trả về 0
#### 2. Tạo mảng lookup kích thước M x N
Khởi tạo maxSize = 0 để lưu kích thước của ma trận vuông con cần tìm
#### 3. Duyệt qua từng phần tử mat[i][j] với i,j lần lượt chạy từ M-1(//i),N-1(//j) theo đúng thứ tự 
   ##### - Nếu i = 0 or j = 0:
       lookup[i][j] = mat[i][j]
   ##### - Ngược lại, nếu mat[i][j] = 1:
       lookup[i][j] = min(lookup[i][j-1], lookup[i-1][j], lookup[i-1][j-1]) + 1
   ##### - Ngoài ra:
       lookup[i][j] = 0
   ##### - Cập nhật maxSize = max(maxSize, lookup[i][j])
#### 4. Trả về maxSize

### Ứng dụng: -Xử lí hình ảnh 
#### -Thị giác máy tính
### Mã Giả: Với ma trận mat[][], M,N
####  Kiểm tra ma trận
#### Nếu M=0 hoặc N=0 thì trả về 0
#### Tạo mảng lookup[][] để lưu trữ các kết quả với tạo mảng ban đầu với hệ số ma trận là M,N cùng mới maxsize =0
#### Duyệt các phần tử của ma trận sử dụng 2 vòng for lồng nhau
####    FOR i = 0 TO M-1 DO
####        FOR j = 0 TO N-1 DO
####            // Xử lý các phần tử ở vị trí đầu của cả hàng lẫn cột
####            IF i = 0 OR j = 0 THEN
####                lookup[i][j] = mat[i][j]
####            ELSE
####                IF mat[i][j] = 1 THEN
####                    lookup[i][j] = MIN(lookup[i-1][j],lookup[i][j-1],lookup[i-1][j-1])+ 1 // lần lượt là phần tử trên, trái, chéo
####                ELSE
####                    lookup[i][j] = 0
####                END IF
####            END IF
####            IF lookup[i][j] > maxSize THEN  // Update size lớn nhất của ma trận
####                maxSize = lookup[i][j]
####            END IF
####        END FOR
####    END FOR
####    RETURN maxsize
#### FUNCTION MIN(a, b, c) // tìm giá trị nhỏ nhất
####    min = a
####    IF b < min THEN
####        min = b
####    END IF
####    IF c < min THEN
####        min = c
####    END IF
####    RETURN min
#### END FUNCTION
