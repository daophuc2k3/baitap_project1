#include <bits/stdc++.h>
using namespace std;

int main() {
    // Khai báo một tập hợp không có thứ tự sử dụng để lưu trữ các chuỗi duy nhất
    unordered_set<string> key_set;

    // Đọc các khóa từ đầu vào và thêm chúng vào tập hợp
    while (true) {
        string key;
        cin >> key;
        // Kết thúc đọc khóa khi gặp dấu "*"
        if (key == "*") {
            break;
        }
        key_set.insert(key);
    }

    // Thực hiện các thao tác tìm kiếm và thêm mới trên tập hợp
    while (true) {
        string cmd, k;
        cin >> cmd >> k;
        // Kết thúc thao tác khi gặp dấu "***"
        if (cmd == "***") {
            break;
        }
        // Kiểm tra thao tác là "find" hay "insert" và thực hiện tương ứng
        if (cmd == "find") {
            // Nếu chuỗi k tồn tại trong tập hợp, in ra "1"; ngược lại, in ra "0"
            if (key_set.find(k) != key_set.end()) {
                cout << "1" << endl;
            } else {
                cout << "0" << endl;
            }
        } else if (cmd == "insert") {
            // Nếu chuỗi k đã tồn tại trong tập hợp, in ra "0"; ngược lại, thêm vào và in ra "1"
            if (key_set.find(k) != key_set.end()) {
                cout << "0" << endl;
            } else {
                key_set.insert(k);
                cout << "1" << endl;
            }
        }
    }

    return 0;
}



/*
Chương trình sử dụng cấu trúc dữ liệu unordered_set từ thư viện chuẩn C++.
unordered_set là một cấu trúc dữ liệu băm không theo thứ tự, giúp lưu trữ các phần tử mà không quan tâm đến thứ tự của chúng. 
Trong trường hợp này, nó được sử dụng để lưu trữ các chuỗi, và việc tìm kiếm và thêm mới có độ phức tạp trung bình là O(1).
*/