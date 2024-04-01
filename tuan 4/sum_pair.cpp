#include <bits/stdc++.h>

using namespace std;

int main() {
    // Đọc số phần tử và giá trị M
    int n, M;
    cin >> n >> M;
    
    // Khai báo mảng chứa các phần tử dãy
    int a[1000000];
    // Khai báo một unordered_set để lưu trữ các phần tử dãy, giúp tìm kiếm nhanh chóng
    unordered_set<int> elements_set;

    // Đọc dãy số và thêm vào unordered_set
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        elements_set.insert(a[i]);
    }
    
    // Biến đếm số cặp thoả mãn điều kiện
    int count = 0;

    // Duyệt qua từng phần tử trong dãy
    for (int i = 0; i < n; i++) {
        // Nếu tồn tại phần tử a[j] sao cho a[i] + a[j] = M
        if (elements_set.find(M - a[i]) != elements_set.end()) {
            count++;
        }
    }

    // Mỗi cặp được đếm 2 lần, nên chia đôi để tránh đếm trùng
    count /= 2;

    // Xuất kết quả
    cout << count << endl;

    return 0;
}
