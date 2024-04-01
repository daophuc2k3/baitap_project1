#include <bits/stdc++.h>  // Thêm tất cả các thư viện của C++ để sử dụng
using namespace std;

int main() {
    int n;  // Khai báo biến n để lưu giá trị nhập vào từ bàn phím
    cin >> n;  // Nhập giá trị của n từ bàn phím

    for (int i = 100; i <= 999; i++) {  // Duyệt qua tất cả các số có 3 chữ số từ 100 đến 999
        if (i % n == 0) {  // Kiểm tra xem số hiện tại có chia hết cho n không
            cout << i << " ";  // In ra màn hình số thỏa mãn điều kiện
        }
    }
    
    cout << endl;  // Xuống dòng sau khi in xong tất cả các số
    return 0;  // Kết thúc chương trình
}
