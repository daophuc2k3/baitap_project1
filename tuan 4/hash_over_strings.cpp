#include <bits/stdc++.h>

using namespace std;

// Hàm tính giá trị hash của chuỗi s modulo m
unsigned long long compute_hash_code(const string& s, int m) {
    int k = s.length();
    unsigned long long hash_code = 0;
    
    // Duyệt qua từng ký tự trong chuỗi
    for (int i = 0; i < k; i++) {
        // Cập nhật giá trị hash sử dụng công thức: (hash_code * 256 + s[i]) % m
        hash_code = (hash_code * 256 + s[i]) % m;
    }
    
    return hash_code;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Tạo vector để lưu trữ chuỗi đầu vào
    vector<string> strings(n);

    // Đọc các chuỗi đầu vào
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    // Tính và xuất giá trị hash cho mỗi chuỗi
    for (int i = 0; i < n; i++) {
        unsigned long long hash_code = compute_hash_code(strings[i], m);
        cout << hash_code << "\n";
    }

    return 0;
}
