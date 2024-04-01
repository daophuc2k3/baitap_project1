#include <bits/stdc++.h>

using namespace std;

int main() {
    // Khởi tạo một hàng đợi chứa các số nguyên
    queue<int> myQueue;

    string line;
    while (true) {
        // Đọc từng dòng từ đầu vào
        getline(cin, line);

        // Kiểm tra nếu dòng là trống hoặc kết thúc chương trình
        if (line.empty() || line == "#") {
            break;
        }
        
        // Xử lý lệnh PUSH
        if (line.find("PUSH") != string::npos) {
            // Trích xuất giá trị để đẩy vào hàng đợi
            int value;
            if (sscanf(line.c_str(), "PUSH %d", &value) == 1) {
                myQueue.push(value);
            }
        } 
        // Xử lý lệnh POP
        else if (line == "POP") {
            // Kiểm tra nếu hàng đợi không trống
            if (!myQueue.empty()) {
                // Lấy giá trị ở đầu hàng đợi, in ra stdout và loại bỏ nó
                int poppedValue = myQueue.front();
                cout << poppedValue << endl;
                myQueue.pop();
            } 
            // Nếu hàng đợi trống, in ra "NULL"
            else {
                cout << "NULL" << endl;
            }
        }
    }

    return 0;
}
