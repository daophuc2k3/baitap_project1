#include <bits/stdc++.h>

using namespace std;

// Cấu trúc để biểu diễn thông tin của mỗi cạnh
struct CauTrucCanh {
    int u, v, trongSo;
};

// Hàm so sánh hai cạnh theo trọng số tăng dần
bool SoSanhCanh(const CauTrucCanh& a, const CauTrucCanh& b) {
    return a.trongSo < b.trongSo;
}

// Cấu trúc dữ liệu Union-Find (DSU)
struct DSU {
    vector<int> cha, kichThuoc;

    // Khởi tạo DSU với n đỉnh
    DSU(int n) {
        cha.resize(n);
        kichThuoc.resize(n, 1);
        for (int i = 0; i < n; i++) {
            cha[i] = i;
        }
    }

    // Tìm cha của một đỉnh trong cây union-find
    int TimCha(int u) {
        if (u == cha[u]) {
            return u;
        }
        // Nén đường đi
        return cha[u] = TimCha(cha[u]);
    }

    // Hợp nhất hai tập hợp con trong union-find
    bool HopNhat(int u, int v) {
        u = TimCha(u);
        v = TimCha(v);
        if (u != v) {
            // Hợp nhất tập hợp con có kích thước nhỏ hơn vào tập hợp con có kích thước lớn hơn
            if (kichThuoc[u] < kichThuoc[v]) {
                swap(u, v);
            }
            cha[v] = u;
            kichThuoc[u] += kichThuoc[v];
            return true;  // Hợp nhất thành công
        }
        return false;  // Hai đỉnh đã thuộc cùng một tập hợp con
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<CauTrucCanh> cacCanh;

    // Nhập thông tin của các cạnh
    for (int i = 0; i < M; i++) {
        int u, v, trongSo;
        cin >> u >> v >> trongSo;
        cacCanh.push_back({u, v, trongSo});
    }

    // Sắp xếp các cạnh theo trọng số tăng dần
    sort(cacCanh.begin(), cacCanh.end(), SoSanhCanh);

    // Khởi tạo DSU với N đỉnh
    DSU dsu(N);
    long long trongSoTong = 0;

    // Thực hiện thuật toán Kruskal
    for (const CauTrucCanh& canh : cacCanh) {
        if (dsu.HopNhat(canh.u - 1, canh.v - 1)) {
            // Nếu hai đỉnh của cạnh thuộc hai tập hợp con khác nhau, hợp nhất và cộng trọng số của cạnh vào tổng trọng số của cây
            trongSoTong += canh.trongSo;
        }
    }

    // In ra tổng trọng số của cây bao trùm nhỏ nhất (MST)
    cout << trongSoTong << endl;
    return 0;
}



/*

Chương trình trên sử dụng cấu trúc dữ liệu là Union-Find (DSU) và thuật toán Kruskal để tìm Minimum Spanning Tree (MST) của đồ thị không hướng và liên thông.

Cấu trúc dữ liệu Union-Find (DSU):

DSU được sử dụng để theo dõi các tập hợp con (disjoint sets) và thực hiện các thao tác hợp nhất giữa chúng.
Mỗi tập hợp con được biểu diễn bằng một cây, trong đó mỗi đỉnh là một phần tử trong tập hợp và cha của mỗi đỉnh là đỉnh cha của nó trong cây.
Thuật toán Kruskal:

Thuật toán Kruskal được sử dụng để tìm Minimum Spanning Tree (MST) của đồ thị có trọng số không hướng và liên thông.
Ý tưởng chính là sắp xếp tất cả các cạnh theo trọng số tăng dần và sau đó thêm lần lượt từng cạnh vào cây bao trùm nếu nó không tạo chu trình.
Cấu trúc dữ liệu Union-Find (DSU) được sử dụng để kiểm tra xem việc thêm một cạnh mới có tạo chu trình hay không.
*/