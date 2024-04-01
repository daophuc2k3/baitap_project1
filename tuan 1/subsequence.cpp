#include <bits/stdc++.h>  // Thêm tất cả các thư viện của C++ để sử dụng
using namespace std;

int main() 
{ 
    int n, k;
    cin >> n >> k;  // Nhập số lượng phần tử và độ dài của k-subsequence

    int a[n], s[n], q = 0;  // Mảng a để lưu trữ dãy số, mảng s để lưu trữ tổng tích lũy, q để lưu số lượng k-subsequences có trọng số là số chẵn
    s[0] = 0;  // Khởi tạo tổng tích lũy đến phần tử 0

    for(int i = 1; i <= n; i++){
        cin >> a[i];  // Nhập dãy số
        s[i] = s[i-1] + a[i];  // Tính tổng tích lũy đến phần tử thứ i
    }

    for(int i = 1; i <= n; i++){
        if(i - 1 <= n - k){
            // Kiểm tra xem trọng số của k-subsequence có là số chẵn không
            if((s[i + k - 1] - s[i - 1]) % 2 == 0) 
                q++;  // Nếu là số chẵn, tăng giá trị của q
        }
    }

    cout << q;  // In ra số lượng k-subsequences có trọng số là số chẵn
    return 0;
}
