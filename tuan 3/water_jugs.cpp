#include <bits/stdc++.h>
using namespace std;

// Hàm tính ước chung lớn nhất của hai số nguyên
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Hàm thực hiện thuật toán để có chính xác c lít nước
int getStepsToDesiredVolume(int a, int b, int c) {
    // Kiểm tra điều kiện không thể có cách làm
    if (c > max(a, b) || c % gcd(a, b) != 0)
        return -1;

    // Cấu trúc dữ liệu để lưu trạng thái đã thăm
    set<pair<int, int>> visited;
    // Hàng đợi để thực hiện BFS
    queue<pair<int, int>> q;

    // Bắt đầu từ trạng thái (0, 0)
    visited.insert({0, 0});
    q.push({0, 0});

    int steps = 0; // Biến đếm số bước

    // Bắt đầu vòng lặp BFS
    while (!q.empty()) {
        int size = q.size();

        // Duyệt qua từng trạng thái trong cùng một bước
        for (int i = 0; i < size; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            // Kiểm tra nếu đã đạt được dung tích mong muốn
            if (x == c || y == c)
                return steps;

            // Thực hiện các thao tác fill, empty, và pour cho cả hai bình
            // Fill - đổ đầy a
            if (x < a && visited.count({a, y}) == 0) {
                q.push({a, y});
                visited.insert({a, y});
            }

            // Fill b
            if (y < b && visited.count({x, b}) == 0) {
                q.push({x, b});
                visited.insert({x, b});
            }

            // Empty -làm trống a
            if (x > 0 && visited.count({0, y}) == 0) {
                q.push({0, y});
                visited.insert({0, y});
            }

            // Empty b
            if (y > 0 && visited.count({x, 0}) == 0) {
                q.push({x, 0});
                visited.insert({x, 0});
            }

            // Pour - đổ from a to b
            int pour = min(x, b - y);
            if (pour > 0 && visited.count({x - pour, y + pour}) == 0) {
                q.push({x - pour, y + pour});
                visited.insert({x - pour, y + pour});
            }

            // Pour from b to a
            pour = min(a - x, y);
            if (pour > 0 && visited.count({x + pour, y - pour}) == 0) {
                q.push({x + pour, y - pour});
                visited.insert({x + pour, y - pour});
            }
        }

        steps++;
    }

    return -1; // Nếu không tìm được cách làm
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int result = getStepsToDesiredVolume(a, b, c);
    cout << result << endl;
    return 0;
}




/*
Chương trình sử dụng cấu trúc dữ liệu là set để theo dõi các trạng thái đã thăm trong quá trình tìm kiếm theo chiều rộng
(BFS - Breadth-First Search). Nó cũng sử dụng queue để lưu trữ các trạng thái cần kiểm tra và thực hiện BFS.

-Cấu trúc dữ liệu:
    set<pair<int, int>> visited: Dùng để lưu trữ các cặp (x, y) đại diện cho trạng thái của hai bình nước đã được kiểm tra. 
        Điều này giúp tránh việc kiểm tra lại các trạng thái đã thăm và tránh lặp vô hạn trong quá trình tìm kiếm.

    queue<pair<int, int>> q: Dùng để lưu trữ các trạng thái cần kiểm tra theo chiều rộng.

-Thuật toán: bfs
Bắt đầu từ trạng thái ban đầu (0, 0), thêm nó vào visited và q.
Thực hiện BFS:
    Mỗi bước, lấy một trạng thái từ q.
    Kiểm tra nếu đạt được dung tích mong muốn thì trả về số bước đã thực hiện.
    Nếu chưa đạt được, thực hiện các thao tác fill, empty, và pour cho cả hai bình.
    Kiểm tra các trạng thái mới và thêm vào visited và q.
    Nếu không tìm được cách làm nào để có dung tích mong muốn, trả về -1.

-Thuật toán sử dụng BFS để tìm kiếm tất cả các trạng thái có thể có và đảm bảo tìm ra giải pháp với số bước ít nhất.
*/