#include <bits/stdc++.h>

using namespace std;

// Hàm kiểm tra tính đúng đắn của biểu thức
bool isCorrectExpression(const string& expression) {
    // Sử dụng stack để theo dõi các dấu mở ngoặc
    stack<char> st;

    // Duyệt qua từng ký tự trong biểu thức
    for (char ch : expression) {
        // Nếu là dấu mở ngoặc, đẩy vào stack
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        } 
        // Nếu là dấu đóng ngoặc
        else if (!st.empty() &&
                   ((ch == ')' && st.top() == '(') ||
                    (ch == ']' && st.top() == '[') ||
                    (ch == '}' && st.top() == '{'))) {
            // Nếu có dấu mở ngoặc tương ứng ở trên cùng của stack, loại bỏ nó
            st.pop();
        } 
        // Nếu là ký tự khác, biểu thức không đúng
        else {
            return false;
        }
    }

    // Kiểm tra xem stack có rỗng không sau khi duyệt hết biểu thức
    return st.empty();
}

int main() {
    // Khai báo và đọc chuỗi biểu thức từ người dùng
    string expression;
    cin >> expression;

    // Gọi hàm kiểm tra đúng đắn và xuất kết quả
    if (isCorrectExpression(expression)) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}

/*
Stack (Ngăn xếp):
-Mục đích sử dụng: Stack được sử dụng để theo dõi các dấu mở ngoặc trong biểu thức và 
    kiểm tra sự tương ứng giữa các dấu mở và đóng ngoặc.
-Hoạt động trong chương trình:
    Khi gặp dấu mở ngoặc ('(', '[', '{'), chúng ta đẩy nó vào đỉnh của stack.
    Khi gặp dấu đóng ngoặc, chúng ta kiểm tra xem stack có rỗng không và nếu có, kiểm tra xem dấu đóng ngoặc 
        có tương ứng với dấu mở ngoặc trên đỉnh của stack không. Nếu có, loại bỏ dấu mở ngoặc đó khỏi stack. Nếu không, biểu thức không đúng.
    Sau khi duyệt hết biểu thức, chúng ta kiểm tra xem stack có rỗng không. Nếu rỗng, biểu thức là đúng; ngược lại, là không đúng.
Stack là một cấu trúc dữ liệu linh động, phù hợp để theo dõi thứ tự và tương ứng giữa các dấu mở và đóng ngoặc trong biểu thức. 
Chúng ta sử dụng stack để duyệt qua biểu thức một cách hiệu quả và kiểm tra tính đúng đắn của nó.
*/
