#include <bits/stdc++.h> 
using namespace std;

int main() {
    // Khai báo biến n để lưu số lượng phần tử ban đầu của danh sách
    int n;
    cin >> n;

    // Khai báo một danh sách liên kết được xây dựng từ thư viện <list> trong C++
    list<int> linkedList;

    // Đọc dãy phần tử ban đầu từ input và thêm vào danh sách liên kết
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        linkedList.push_back(num);
    }

    // Khai báo biến command để lưu tên lệnh
    string command;

    // Duyệt qua các lệnh thao tác từ input
    while (cin >> command) {
        // Kiểm tra và thực hiện từng lệnh theo yêu cầu đề bài
        if (command == "addlast") {
            int k;
            cin >> k;
            // Kiểm tra xem phần tử k đã tồn tại trong danh sách chưa, nếu chưa thì thêm vào cuối
            if (find(linkedList.begin(), linkedList.end(), k) == linkedList.end()) {
                linkedList.push_back(k);
            }
        } else if (command == "addfirst") {
            int k;
            cin >> k;
            // Kiểm tra xem phần tử k đã tồn tại trong danh sách chưa, nếu chưa thì thêm vào đầu
            if (find(linkedList.begin(), linkedList.end(), k) == linkedList.end()) {
                linkedList.push_front(k);
            }
        } else if (command == "addafter") {
            int u, v;
            cin >> u >> v;
            // Tìm phần tử v trong danh sách và thêm phần tử u vào sau nếu u chưa tồn tại
            auto it = find(linkedList.begin(), linkedList.end(), v);
            if (it != linkedList.end() && find(linkedList.begin(), linkedList.end(), u) == linkedList.end()) {
                it++;
                linkedList.insert(it, u);
            }
        } else if (command == "addbefore") {
            int u, v;
            cin >> u >> v;
            // Tìm phần tử v trong danh sách và thêm phần tử u vào trước nếu u chưa tồn tại
            auto it = find(linkedList.begin(), linkedList.end(), v);
            if (it != linkedList.end() && find(linkedList.begin(), linkedList.end(), u) == linkedList.end()) {
                linkedList.insert(it, u);
            }
        } else if (command == "remove") {
            int k;
            cin >> k;
            // Loại bỏ phần tử k khỏi danh sách
            linkedList.remove(k);
        } else if (command == "reverse") {
            // Đảo ngược thứ tự các phần tử trong danh sách
            linkedList.reverse();
        } else if (command == "#") {
            // Kết thúc khi gặp ký tự #
            break;
        }
    }

    // In ra dãy phần tử của danh sách sau khi thực hiện tất cả các lệnh
    for (int num : linkedList) {
        cout << num << " ";
    }

    return 0;
}



/*

-Chương trình sử dụng cấu trúc dữ liệu là list từ thư viện tiêu chuẩn của C++. Đây là một cấu trúc dữ liệu liên kết kép, cho phép thêm, xóa phần tử một 
cách hiệu quả ở cả đầu và cuối danh sách. Ngoài ra, list cũng hỗ trợ các hàm và phương thức để thực hiện các thao tác cơ bản như find, insert, và remove.

Dưới đây là một số điểm về cấu trúc dữ liệu list:

Ưu điểm:
-Linh họat: Có khả năng chèn và xóa ở cả hai đầu của danh sách mà không làm thay đổi địa chỉ bộ nhớ của các phần tử khác.
-Hiệu quả: Các thao tác thêm/xóa phần tử có độ phức tạp thời gian là O(1) với list, đặc biệt là khi thêm/xóa ở đầu hoặc cuối danh sách.
-Stable Iterators: Các vị trí iterators không bị thay đổi khi thêm/xóa phần tử, giúp duyệt danh sách một cách an toàn.

Nhược điểm:
-Khả năng cache miss cao: Do cấu trúc dữ liệu không liên tục trong bộ nhớ, có thể dẫn đến hiện tượng cache miss trong một số trường hợp.

Sử dụng thích hợp: list thích hợp khi cần thực hiện nhiều thao tác thêm/xóa phần tử, và không cần truy cập ngẫu nhiên nhiều vào các phần tử.

Trong chương trình này, việc sử dụng list giúp làm giảm độ phức tạp thời gian của các thao tác thêm/xóa so với một số cấu trúc dữ liệu khác như vector.






*/