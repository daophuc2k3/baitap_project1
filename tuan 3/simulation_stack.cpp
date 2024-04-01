#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    // Khai báo một ngăn xếp chứa các số nguyên
    stack<int> myStack;

    // Biến lưu trữ dòng nhập từ người dùng
    string line;

    // Đọc dòng đầu tiên từ người dùng
    while (getline(cin, line)) {
        // Kiểm tra nếu dòng trống hoặc là dấu kết thúc
        if (line.empty() || line == "#") {
            break;
        }

        // Xử lý lệnh PUSH
        if (line.find("PUSH") != string::npos) {
            // Trích xuất giá trị để đẩy vào ngăn xếp
            int value;
            if (sscanf(line.c_str(), "PUSH %d", &value) == 1) {
                myStack.push(value);
            }
        } 
        // Xử lý lệnh POP
        else if (line == "POP") {
            // Kiểm tra nếu ngăn xếp không trống
            if (!myStack.empty()) {
                // Lấy giá trị trên đỉnh ngăn xếp, in ra và loại bỏ nó
                int poppedValue = myStack.top();
                cout << poppedValue << endl;
                myStack.pop();
            } 
            // Nếu ngăn xếp trống, in ra "NULL"
            else {
                cout << "NULL" << endl;
            }
        }
    }

    return 0;
}



/*
Chương trình sử dụng cấu trúc dữ liệu ngăn xếp (stack) để thực hiện các thao tác PUSH và POP.

-Dòng lệnh stack<int> myStack; khai báo một ngăn xếp (stack) chứa các số nguyên.
-Các thao tác myStack.push(value); và myStack.pop(); được sử dụng để thêm giá trị vào đỉnh ngăn xếp và loại bỏ giá trị ở đỉnh ngăn xếp, tương ứng.
Ngăn xếp là một cấu trúc dữ liệu LIFO (Last-In-First-Out), có nghĩa là phần tử được thêm vào cuối cùng là phần tử đầu tiên được loại bỏ.
Cấu trúc dữ liệu ngăn xếp thường được sử dụng khi ta cần theo dõi thứ tự của các phần tử và muốn thực hiện các thao tác thêm và loại bỏ ở đầu của dãy một cách hiệu quả.
*/