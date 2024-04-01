#include <bits/stdc++.h>  // Thêm tất cả các thư viện của C++ để sử dụng
using namespace std;

int main() {
    string text;  // Khai báo biến text để lưu trữ chuỗi đầu vào

    string line;
    while (getline(cin, line)) {  // Đọc từng dòng của chuỗi đầu vào và thêm vào biến text
        text += line + "\n";
    }

    locale loc;  // Tạo một đối tượng locale để sử dụng trong hàm toupper
    for (char& c : text) {  // Duyệt qua từng ký tự trong chuỗi text
        c = toupper(c, loc);  // Chuyển đổi ký tự thành chữ in hoa
    }

    cout << text;  // In ra màn hình chuỗi sau khi đã chuyển đổi thành chữ in hoa

    return 0;  // Kết thúc chương trình
}
