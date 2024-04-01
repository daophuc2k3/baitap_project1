#include <bits/stdc++.h>  // Thêm tất cả các thư viện của C++ để sử dụng


using namespace std;

int main() {
    string P1, P2, T;  // Khai báo các biến lưu trữ xâu P1, P2 và văn bản T
    getline(cin, P1);  // Nhập xâu P1 từ bàn phím
    getline(cin, P2);  // Nhập xâu P2 từ bàn phím
    getline(cin, T);   // Nhập văn bản T từ bàn phím

    size_t found = T.find(P1);  // Tìm vị trí xuất hiện đầu tiên của xâu P1 trong văn bản T

    // Thực hiện thay thế các xâu P1 bằng xâu P2 trong văn bản T
    while (found != string::npos) {
        T.replace(found, P1.length(), P2);  // Thay thế xâu P1 bằng xâu P2 từ vị trí found
        found = T.find(P1, found + P2.length());  // Tìm vị trí xuất hiện tiếp theo của xâu P1 sau vị trí đã thay thế
    }

    cout << T << endl;  // In ra màn hình văn bản T sau khi thay thế

    return 0;
}
