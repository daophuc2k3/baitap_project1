#include <bits/stdc++.h>
int const N = 9;  // Định nghĩa kích thước của bảng Sudoku

using namespace std;

// Hàm kiểm tra xem việc đặt số num tại vị trí (row, col) có hợp lệ hay không
bool check(int a[N][N], int row, int col, int num) {
    // Kiểm tra xem num có xuất hiện trong hàng hoặc cột đang xét không
    for (int i = 0; i < N; i++) {
        if (a[row][i] == num || a[i][col] == num) {
            return false;
        }
    }

    // Kiểm tra xem num có xuất hiện trong sub-square 3x3 đang xét không
    int start_row = 3 * (row / 3);
    int start_col = 3 * (col / 3);
    for (int i = start_row; i < start_row + 3; i++) {
        for (int j = start_col; j < start_col + 3; j++) {
            if (a[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

// Hàm đệ quy để đếm số lượng cách điền số vào bảng Sudoku
int Count(int a[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (a[row][col] == 0) {  // Nếu gặp ô trống
                int cnt = 0;
                for (int num = 1; num <= 9; num++) {
                    if (check(a, row, col, num)) {
                        a[row][col] = num;  // Đặt số num vào ô trống
                        cnt += Count(a);  // Gọi đệ quy để tiếp tục điền số
                        a[row][col] = 0;  // Quay lui để thử các giá trị khác
                    }
                }
                return cnt;  // Trả về tổng số cách điền khi đã đủ số ở mỗi ô
            }
        }
    }

    return 1;  // Trường hợp cơ bản, đã điền đầy đủ số, trả về 1 cách
}

int main() {
    int a[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) 
            cin >> a[i][j];  // Nhập bảng Sudoku từ input
    }

    cout << Count(a);  // In ra số lượng cách điền

    return 0;
}
