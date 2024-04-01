#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

struct Canh {
    int den, trong_so;
};

// Hàm thực hiện thuật toán Dijkstra để tìm đường đi ngắn nhất từ một đỉnh bắt đầu
void dijkstra(vector<vector<Canh>> &do_thi, vector<int> &khoang_cach, int dinh_bat_dau) {
    // Sử dụng priority_queue để lấy đỉnh có khoảng cách ngắn nhất trước
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> hang_doi;
    hang_doi.push({0, dinh_bat_dau});
    khoang_cach[dinh_bat_dau] = 0;

    while (!hang_doi.empty()) {
        int u = hang_doi.top().second;
        int khoang_cach_hien_tai = hang_doi.top().first;
        hang_doi.pop();

        if (khoang_cach_hien_tai > khoang_cach[u]) {
            continue;
        }

        // Duyệt qua tất cả các đỉnh kề của đỉnh hiện tại
        for (const Canh &c : do_thi[u]) {
            int v = c.den;
            int trong_so = c.trong_so;

            // Nếu có đường đi ngắn hơn đến đỉnh kề, cập nhật khoảng cách và thêm vào hàng đợi
            if (khoang_cach[u] + trong_so < khoang_cach[v]) {
                khoang_cach[v] = khoang_cach[u] + trong_so;
                hang_doi.push({khoang_cach[v], v});
            }
        }
    }
}

int main() {
    int so_dinh, so_canh;
    cin >> so_dinh >> so_canh;

    // Khởi tạo đồ thị và mảng lưu khoảng cách
    vector<vector<Canh>> do_thi(so_dinh + 1);
    vector<int> khoang_cach(so_dinh + 1, INF);

    // Nhập thông tin về các cạnh của đồ thị
    for (int i = 0; i < so_canh; ++i) {
        int u, v, trong_so;
        cin >> u >> v >> trong_so;
        do_thi[u].push_back({v, trong_so});
    }

    int dinh_bat_dau, dinh_ket_thuc;
    cin >> dinh_bat_dau >> dinh_ket_thuc;

    // Gọi hàm Dijkstra để tìm đường đi ngắn nhất
    dijkstra(do_thi, khoang_cach, dinh_bat_dau);

    // In ra kết quả
    if (khoang_cach[dinh_ket_thuc] == INF) {
        cout << -1 << endl;
    } else {
        cout << khoang_cach[dinh_ket_thuc] << endl;
    }

    return 0;
}



/*
-Cấu Trúc Dữ Liệu:
Vector và Struct:
    Sử dụng vector để lưu trữ danh sách kề của mỗi đỉnh trong đồ thị.
    Sử dụng struct Canh để biểu diễn thông tin về một cạnh, bao gồm đỉnh đến (den) và trọng số (trong_so).

-Thuật Toán:
Dijkstra:
    Dùng thuật toán Dijkstra để tìm đường đi ngắn nhất từ đỉnh bắt đầu đến tất cả các đỉnh khác trong đồ thị.
    Sử dụng hàng đợi ưu tiên (priority_queue) để luôn lựa chọn đỉnh có khoảng cách ngắn nhất trước.
    Cập nhật khoảng cách tới các đỉnh kề của đỉnh hiện tại nếu có đường đi ngắn hơn.
*/