/*
Bài 2: Thiết kế giải thuật và cài đặt để tạo ra một mảng số nửa nguyên tố (Blum) nhỏ hơn một số N cho trước và thực hiện hai yêu cầu sau
- Tìm ra tất cả các cặp số Blum có tổng cũng là một số Blum nhỏ hơn N
- Kiểm tra xem một số Blum M có tồn tại trong dãy số Blum được tạo ra hay không.
*/

/*
blum integer n = p x q
p and q are prime numbers formed 4t+3 (integer t)
*/

/*
Giải thuật
1. Tạo ra 1 dãy Blums < N:
        + Kiểm tra các số từ 1 đến N có phải primes hay không
        + Chọn các Primes mod 4 = 3 rồi push_back vào vector Primes_4tplus3
        + Nhân lần lượt 2 phần tử của Primes_4tplus3 rồi push_back vào Blums (với điều kiện <N)
        + Sắp xếp Blums theo Selection Sort
2. Tìm cặp Blums có tổng cũng là Blum < N:
        + Cộng lần lượt 2 phần tử của Blums rồi kiểm tra xem có trùng với phần tử nào trong Blums không
3. Kiểm tra xem M có trùng với phần tử nào trong Blums không
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool check_Prime (int n){
    if (n < 2) return 0;
    for (int i=2; i<=sqrt(n); i++){
        if (n%i == 0) return 0;
    }
    return 1;
}

bool check_form_4tplus3 (int n){
    if (n%4 == 3) return 1;
    else return 0;
}

vector<int> Primes_4tplus3;
vector<int> Blums;

void find_Primes_4tplus3 (int N){
    for (int i=2; i<N; i++){
        if (check_Prime(i) && check_form_4tplus3(i)){
            Primes_4tplus3.push_back(i);
        }
    }
}

void generate_Blums (int N){
    int size = Primes_4tplus3.size();
    for (int i=0; i<size; i++){
        for (int j=i; j<size; j++){
            int blum = Primes_4tplus3[i] * Primes_4tplus3[j];
            if (blum < N) Blums.push_back(blum);
        }
    }
    for (int i=0; i<Blums.size(); i++){
        int min = Blums[i];
        int id = i;
        for (int j=i+1; j<Blums.size(); j++){
            if (min > Blums[j]){
                id = j;
                min = Blums[j];
            }
        }
        Blums[id] = Blums[i];
        Blums[i] = min;
    }        
}

bool check_Blums_Sum(const vector<int>& Blums, int sum) {
    for (int blum : Blums) {
        if (blum == sum) {
            return 1;
        }
    }
    return 0;
}

bool check_Blums(const vector<int>& Blums, int M) {
    for (int blum : Blums) {
        if (blum == M) {
            return 1;
        }
    }
    return 0;
}

int main (){
    int N;
    cout << "N = ";
    cin >> N;
    
    find_Primes_4tplus3 (N);
    generate_Blums (N);
    
    cout << "The Blums < " << N << " are: ";
    for (int blum : Blums) {
        cout << blum << " ";
    }
    cout << endl;
    
    cout << "The couples Blums whose sum is Blum < " << N << " are:" << endl;
    for (int i = 0; i < Blums.size(); i++) {
        for (int j = i + 1; j < Blums.size(); j++) {
            int sum = Blums[i] + Blums[j];
            if (sum < N && check_Blums_Sum(Blums, sum)) {
                cout << Blums[i] << " + " << Blums[j] << " = " << sum << endl;
            }
        }
    }

    int M;
    cout << "M = ";
    cin >> M;
    if (check_Blums(Blums, M)) cout << M << " is exist in the Blums < " << N << endl;
    else cout << M << " is not exist in the Blums < " << N << endl;

    return 0;
}