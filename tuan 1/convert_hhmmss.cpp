#include <bits/stdc++.h>  // Thêm tất cả các thư viện của C++ để sử dụng
using namespace std;

int main() {
    string s;  // Khai báo biến s để lưu trữ chuỗi đầu vào
    cin >> s;  // Nhập chuỗi từ bàn phím

    if (s.length() != 8 || s[2] != ':' || s[5] != ':') {  // Kiểm tra định dạng chuỗi
        cout << "INCORRECT" << endl;  // Nếu chuỗi không đúng định dạng, in ra "INCORRECT"
    } else {
        int hours = stoi(s.substr(0, 2));  // Lấy 2 ký tự đầu tiên là giờ
        int minutes = stoi(s.substr(3, 2));  // Lấy 2 ký tự tiếp theo là phút
        int seconds = stoi(s.substr(6, 2));  // Lấy 2 ký tự cuối cùng là giây

        if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59 || seconds < 0 || seconds > 59) {  // Kiểm tra giá trị hợp lệ của giờ, phút và giây
            cout << "INCORRECT" << endl;  // Nếu không hợp lệ, in ra "INCORRECT"
        } else {
            int result = hours * 3600 + minutes * 60 + seconds;  // Chuyển đổi giờ, phút và giây thành giây và tính tổng
            cout << result << endl;  // In ra màn hình giá trị đã chuyển đổi
        }
    }

    return 0;  // Kết thúc chương trình
}
