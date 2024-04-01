#include <bits/stdc++.h>

using namespace std;

// Khai báo biến lưu trữ danh sách kề và trạng thái đã ghé thăm của mỗi đỉnh
vector<vector<int>> adj;
vector<bool> visited;

// Hàm thực hiện DFS từ một đỉnh
void dfs(int node) {
    // Đánh dấu đỉnh hiện tại đã ghé thăm và in ra màn hình
    visited[node] = true;
    cout << node << " ";

    // Duyệt qua các đỉnh kề chưa ghé thăm
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            // Gọi đệ quy DFS cho đỉnh kề chưa ghé thăm
            dfs(neighbor);
        }
    }
}

int main() {
    // Đọc số đỉnh và số cạnh của đồ thị
    int n, m;
    cin >> n >> m;

    // Khởi tạo danh sách kề và trạng thái đã ghé thăm
    adj.resize(n + 1);
    visited.assign(n + 1, false);

    // Đọc thông tin về các cạnh và xây dựng danh sách kề
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Sắp xếp danh sách kề của mỗi đỉnh để thực hiện DFS theo thứ tự lexicographically
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    // Thực hiện DFS từ mỗi đỉnh chưa ghé thăm
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Xuống dòng để kết thúc kết quả
    cout << endl;

    return 0;
}



/*
Chương trình trên đã sử dụng thuật toán Depth-First Search (DFS) để duyệt qua các đỉnh của đồ thị và in ra màn hình theo thứ tự từ điển. 
Dưới đây là mô tả về thuật toán và cấu trúc dữ liệu được sử dụng:

-Thuật toán Depth-First Search (DFS): DFS là một thuật toán duyệt đồ thị theo chiều sâu. Nó bắt đầu từ một đỉnh xuất phát, ghé thăm đỉnh đó, 
    sau đó chọn một đỉnh kề chưa ghé thăm để tiếp tục quá trình này. Nó sử dụng ngăn xếp (stack) để duyệt qua các đỉnh.

-Cấu trúc dữ liệu vector<vector<int>> adj: Đây là danh sách kề của đồ thị. Mỗi đỉnh được biểu diễn bằng một vector chứa các đỉnh kề của nó.

-Cấu trúc dữ liệu vector<bool> visited: Dùng để theo dõi trạng thái đã ghé thăm của các đỉnh trong quá trình DFS.

-Hàm DFS: Hàm này thực hiện DFS từ một đỉnh. Nó đánh dấu đỉnh đã ghé thăm, in ra màn hình, và tiếp tục gọi đệ quy DFS cho các đỉnh kề chưa ghé thăm.

-Sắp xếp danh sách kề: Trước khi thực hiện DFS, chương trình sắp xếp danh sách kề của mỗi đỉnh để duyệt theo thứ tự lexicographically.

Tổng cộng, chương trình sử dụng DFS để thăm các đỉnh và duyệt qua chúng theo thứ tự từ điển, giúp in ra dãy đỉnh theo yêu cầu của bài toán.






*/