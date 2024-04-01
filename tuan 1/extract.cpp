#include <bits/stdc++.h>  // Thêm tất cả các thư viện của C++ để sử dụng
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;  // Khai báo biến s để lưu trữ chuỗi đầu vào
    cin >> s;  // Nhập chuỗi từ bàn phím

    if (s.length() != 10 || s[4] != '-' || s[7] != '-') {  // Kiểm tra định dạng chuỗi
        cout << "INCORRECT" << endl;  // Nếu chuỗi không đúng định dạng, in ra "INCORRECT"
    } else {
        string year = s.substr(0, 4);  // Lấy 4 ký tự đầu tiên là năm
        string month = s.substr(5, 2);  // Lấy 2 ký tự tiếp theo là tháng
        string day = s.substr(8, 2);  // Lấy 2 ký tự cuối cùng là ngày

        int yearInt = stoi(year);  // Chuyển đổi năm từ chuỗi sang số nguyên
        int monthInt = stoi(month);  // Chuyển đổi tháng từ chuỗi sang số nguyên
        int dayInt = stoi(day);  // Chuyển đổi ngày từ chuỗi sang số nguyên

        if (yearInt < 1 || monthInt < 1 || monthInt > 12 || dayInt < 1 || dayInt > 31) {  // Kiểm tra giá trị hợp lệ của năm, tháng và ngày
            cout << "INCORRECT" << endl;  // Nếu không hợp lệ, in ra "INCORRECT"
        } else {
            if (month[0] == '0') {
                month = month.substr(1, 1);  // Nếu tháng có chữ số đầu tiên là 0, bỏ đi
            }
            if (day[0] == '0') {
                day = day.substr(1, 1);  // Nếu ngày có chữ số đầu tiên là 0, bỏ đi
            }

            cout << yearInt << " " << month << " " << day << endl;  // In ra năm, tháng và ngày đã lấy được
        }
    }

    return 0;  // Kết thúc chương trình
}
