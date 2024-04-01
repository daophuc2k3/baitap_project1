#include <bits/stdc++.h> 

using namespace std;

// Hàm kiểm tra xem đồ thị có là đồ thị Hamilton không
bool isHamiltonian(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& path, int pos, int n) {
    // Nếu đã duyệt hết tất cả các đỉnh
    if (pos == n) {
        // Nếu đỉnh cuối cùng có kết nối với đỉnh đầu tiên
        if (find(adj[path[n - 1]].begin(), adj[path[n - 1]].end(), path[0]) != adj[path[n - 1]].end()) {
            return true;
        }
        return false;
    }

    // Duyệt qua tất cả các đỉnh
    for (int v = 0; v < n; v++) {
        // Nếu đỉnh chưa được duyệt
        if (!visited[v]) {
            // Nếu đang ở vị trí thứ 2 trở đi
            if (pos > 0) {
                // Kiểm tra xem có kết nối giữa đỉnh trước đó và đỉnh hiện tại không
                if (find(adj[path[pos - 1]].begin(), adj[path[pos - 1]].end(), v) == adj[path[pos - 1]].end()) {
                    continue;
                }
            }
            visited[v] = true;
            path[pos] = v;
            // Nếu tiếp tục từ đỉnh hiện tại vẫn tạo thành đồ thị Hamilton
            if (isHamiltonian(adj, visited, path, pos + 1, n)) {
                return true;
            }
            visited[v] = false;
        }
    }
    return false;
}

int main() {
    // Đọc số lượng bộ test
    int T;
    cin >> T;
    
    // Duyệt qua từng bộ test
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n);
        vector<int> path(n);
        vector<bool> visited(n, false);

        // Đọc danh sách cạnh và xây dựng đồ thị
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }

        // Bắt đầu từ đỉnh đầu tiên
        visited[0] = true;
        path[0] = 0;

        // Kiểm tra xem đồ thị có là đồ thị Hamilton không
        if (isHamiltonian(adj, visited, path, 1, n)) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    }

    return 0;
}




/*
Chương trình sử dụng thuật toán "Backtracking" để kiểm tra xem đồ thị có là đồ thị Hamilton không.

Thuật toán "Backtracking" là một kỹ thuật giải quyết vấn đề thông qua việc thử nghiệm 
lần lượt từng giải pháp tiềm ẩn và từ chối những giải pháp không phù hợp để tìm ra giải pháp 
cuối cùng. Trong trường hợp của chương trình, thuật toán thử nghiệm từng đỉnh để xem liệu có
thể tạo thành chu trình Hamilton hay không.

Chu trình Hamilton là một chuỗi các đỉnh trong đồ thị sao cho mỗi đỉnh trong đồ thị đều được ghé 
thăm đúng một lần và quay lại đỉnh xuất phát. Nếu tồn tại chu trình Hamilton, đồ thị được coi là đồ thị Hamilton.

Cấu trúc dữ liệu được sử dụng bao gồm vector và unordered_set. Vector được sử dụng để lưu trữ danh sách
kề của đồ thị, còn unordered_set được sử dụng để kiểm tra đỉnh đã được ghé thăm hay chưa.

Chương trình đọc dữ liệu, xây dựng đồ thị, và thực hiện thuật toán "Backtracking" để kiểm tra xem đồ thị
có là đồ thị Hamilton không. Kết quả được xuất ra theo yêu cầu của đề bài.
*/