#include <bits/stdc++.h>  // Thêm tất cả các thư viện của C++ để sử dụng
using namespace std;

int main() {
    string text;
    string line;

    // Đọc dòng dữ liệu từ bàn phím và thêm vào chuỗi text
    while (getline(cin, line)) {
        text += line + "\n";
    }
 
    // Sử dụng stringstream để chia từng từ từ chuỗi text
    stringstream ss(text);
    string word;
    int wordCount = 0;

    // Đếm số từ trong chuỗi sử dụng stringstream
    while (ss >> word) {
        wordCount++;
    }

    // In ra số lượng từ
    cout << wordCount << endl;

    return 0;
}
