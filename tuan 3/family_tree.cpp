#include <bits/stdc++.h>

using namespace std;

// Map lưu trữ mối quan hệ child-parent
map<string, string> family_tree;

// Hàm đệ quy để đếm số lượng descendants của một người
int countDescendants(string name) {
    int descendants = 0;
    // Duyệt qua mọi cặp child-parent
    for (const auto& entry : family_tree) {
        // Nếu parent của một người là người đang xét, tăng số lượng descendants
        if (entry.second == name) {
            descendants += 1 + countDescendants(entry.first);
        }
    }
    return descendants;
}

// Hàm đệ quy để đếm số lượng generations của một người
int countGenerations(string name) {
    int generations = 0;
    // Duyệt qua mọi cặp child-parent
    for (const auto& entry : family_tree) {
        // Nếu parent của người đang xét là người đang xét, tăng số lượng generations
        if (entry.second == name) {
            generations = max(generations, 1 + countGenerations(entry.first));
        }
    }
    return generations;
}

int main() {
    string child, parent;
    
    // Đọc dữ liệu về mối quan hệ child-parent
    while (true) {
        cin >> child;
        if (child == "***") break;
        cin >> parent;
        family_tree[child] = parent;
    }

    // Đọc và xử lý các truy vấn
    while (true) {
        string command, param;
        cin >> command;
        if (command == "***") break;
        cin >> param;

        // Thực hiện truy vấn và in kết quả ra màn hình
        if (command == "descendants") {
            cout << countDescendants(param) << endl;
        } else if (command == "generation") {
            cout << countGenerations(param) << endl;
        }
    }

    return 0;
}

/*
hương trình sử dụng một cấu trúc dữ liệu quan trọng là map từ thư viện C++. Dưới đây là mô tả về cách map được sử dụng trong chương trình và vai trò của nó:

map<string, string> family_tree:

map là một cấu trúc dữ liệu trong C++ giúp thực hiện ánh xạ giữa các phần tử của kiểu khóa (string trong trường hợp này) và giá trị (string trong trường hợp này).
Trong chương trình này, family_tree được sử dụng để lưu trữ mối quan hệ child-parent. Mỗi key (child) sẽ được ánh xạ đến giá trị tương ứng (parent).

-Hàm đệ quy countDescendants và countGenerations:
Hai hàm này được thiết kế để duyệt qua cây gia phả và đếm số lượng descendants và generations của một người cụ thể.
countDescendants: Duyệt qua mỗi cặp child-parent và nếu parent của người đang xét trùng với người cần đếm descendants, 
    tăng biến descendants và tiếp tục đệ quy với child làm người mới đang xét.
countGenerations: Tương tự như countDescendants, nhưng ở đây chỉ cần đếm số lượng thế hệ, không phải số lượng descendants.

Vòng lặp và kiểm soát luồng chương trình:
Chương trình sử dụng vòng lặp while (true) để liên tục đọc dữ liệu và thực hiện truy vấn cho đến khi gặp dòng "***".
Sử dụng cin để đọc từng dòng và kiểm tra điều kiện để thoát khỏi vòng lặp.
-Tóm lại, cấu trúc dữ liệu map trong C++ được sử dụng để lưu trữ thông tin về mối quan hệ child-parent, giúp dễ dàng truy cập và tìm kiếm thông tin trong gia phả.
Hàm đệ quy được sử dụng để duyệt qua cây gia phả và thực hiện các truy vấn liên quan.






*/