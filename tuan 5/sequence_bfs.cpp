#include <bits/stdc++.h>
using namespace std;

// Khai báo biến toàn cục
vector<vector<int>> adj;   // Ma trận kề biểu diễn đồ thị
vector<bool> visited;       // Mảng đánh dấu đỉnh đã được duyệt

int main() {
    // Nhập số đỉnh (n) và số cạnh (m)
    int n, m;
    cin >> n >> m;

    // Khởi tạo ma trận kề và mảng visited
    adj.resize(n + 1);
    visited.assign(n + 1, false);

    // Nhập thông tin về các cạnh và cập nhật ma trận kề
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Sắp xếp danh sách kề của mỗi đỉnh theo thứ tự tăng dần
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    // Khởi tạo hàng đợi và mảng lưu trữ đỉnh đã được duyệt
    queue<int> q;
    vector<int> nodes;

    // Duyệt qua tất cả các đỉnh của đồ thị
    for (int i = 1; i <= n; i++) {
        // Nếu đỉnh chưa được duyệt, thực hiện BFS từ đỉnh đó
        if (!visited[i]) {
            q.push(i);
            visited[i] = true;

            // Duyệt qua từng đỉnh kề của đỉnh hiện tại
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                nodes.push_back(node);  // Lưu đỉnh vào mảng kết quả

                // Duyệt qua tất cả đỉnh kề của đỉnh hiện tại
                for (int neighbor : adj[node]) {
                    // Nếu đỉnh kề chưa được duyệt, thêm vào hàng đợi và đánh dấu đã duyệt
                    if (!visited[neighbor]) {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
        }
    }

    // In ra kết quả
    for (int i = 0; i < nodes.size(); i++) {
        cout << nodes[i];
        if (i < nodes.size() - 1) {
            cout << " ";
        }
    }

    cout << endl;

    return 0;
}




/*
Cấu trúc dữ liệu:

vector<vector<int>> adj: Ma trận kề để biểu diễn đồ thị vô hướng.
vector<bool> visited: Mảng đánh dấu để theo dõi các đỉnh đã được duyệt.
Thuật toán:

Breadth-First Search (BFS): Để duyệt qua các đỉnh của đồ thị và thu thập dãy đỉnh theo thứ tự lexicographic.
Cụ thể, chương trình thực hiện BFS từ mỗi đỉnh chưa được duyệt và sử dụng một hàng đợi (queue) để theo dõi các đỉnh kề và duyệt qua chúng 
theo chiều rộng. Khi một đỉnh được duyệt, nó được đánh dấu và thêm vào mảng nodes, đại diện cho dãy đỉnh đã được duyệt. Mỗi đỉnh được in ra 
theo thứ tự từ điển sau khi BFS kết thúc.

Do đó, cấu trúc dữ liệu chính là ma trận kề để biểu diễn đồ thị và thuật toán chính là BFS để duyệt qua các đỉnh theo chiều rộng.


*/