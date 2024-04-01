#include <bits/stdc++.h>
using namespace std;

int main() {
    // Khai báo biến n để lưu số lượng phần tử trong dãy
    int n;
    // Đọc giá trị n từ đầu vào
    cin >> n;

    // Khai báo mảng A để lưu dãy số
    int A[n];

    // Sử dụng unordered_map để lưu trữ giá trị đã xuất hiện trước đó và kiểm tra sự trùng lặp
    unordered_map<int, bool> previous_values;

    // Đọc giá trị của từng phần tử trong dãy và kiểm tra sự trùng lặp
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        // Nếu giá trị đã xuất hiện trước đó, in ra 1, ngược lại in ra 0
        if (previous_values.find(A[i]) != previous_values.end()) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }

        // Lưu giá trị hiện tại vào unordered_map để kiểm tra sự trùng lặp ở các vòng lặp sau
        previous_values[A[i]] = true;
    }

    return 0;
}




/*

Bảng băm (hash table) trong chương trình này được triển khai bằng unordered_map từ thư viện chuẩn C++. Dưới đây là mô tả về cách bảng băm được sử dụng:
-Bảng băm (unordered_map) - previous_values:
    Bảng băm được sử dụng để lưu trữ các giá trị đã xuất hiện trước đó trong dãy số.
    unordered_map<int, bool> previous_values; khai báo một bảng băm với khóa kiểu int và giá trị kiểu bool.
    Trong trường hợp này, giá trị của khóa là các phần tử trong dãy số, và giá trị là một biến kiểu bool chỉ đơn giản để kiểm tra sự xuất hiện của phần tử.
-Kiểm tra và Cập nhật bảng băm:
    Trong mỗi vòng lặp, chương trình kiểm tra xem giá trị hiện tại đã xuất hiện trước đó hay chưa bằng cách sử dụng hàm find() của unordered_map.
    Nếu giá trị đã xuất hiện, chương trình in ra 1; ngược lại, in ra 0.
    Sau đó, giá trị hiện tại được thêm vào bảng băm để duyệt qua các giá trị trong các vòng lặp tiếp theo.
-Ưu điểm của Bảng băm:
    Bảng băm là một cấu trúc dữ liệu linh hoạt và hiệu quả để kiểm tra sự xuất hiện của các giá trị với độ phức tạp thời gian trung bình là O(1).
    Trong trường hợp này, unordered_map giúp chương trình thực hiện các thao tác kiểm tra và cập nhật bảng băm một cách dễ dàng và hiệu quả.
*/