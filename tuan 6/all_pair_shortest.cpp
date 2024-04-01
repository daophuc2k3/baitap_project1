#include <bits/stdc++.h>
using namespace std;

const int N = 1e9;

int main() {
    // Nhập số đỉnh và số cạnh
    int so_dinh, so_canh;
    cin >> so_dinh >> so_canh;

    // Khởi tạo ma trận đường đi với giá trị lớn đại diện cho vô cùng (không có đường đi)
    vector<vector<int>> duong_di(so_dinh + 1, vector<int>(so_dinh + 1, N));

    // Thiết lập đường đi trực tiếp từ một đỉnh đến chính nó là 0
    for (int i = 1; i <= so_dinh; ++i) {
        duong_di[i][i] = 0;
    }

    // Nhập thông tin về cạnh và trọng số của chúng
    for (int i = 0; i < so_canh; ++i) {
        int u, v, trong_so;
        cin >> u >> v >> trong_so;
        duong_di[u][v] = trong_so;
    }

    // Thuật toán Floyd-Warshall để tính toán đường đi ngắn nhất
    for (int k = 1; k <= so_dinh; ++k) {
        for (int i = 1; i <= so_dinh; ++i) {
            for (int j = 1; j <= so_dinh; ++j) {
                if (duong_di[i][k] != N && duong_di[k][j] != N) {
                    if (duong_di[i][j] == N || duong_di[i][j] > duong_di[i][k] + duong_di[k][j]) {
                        duong_di[i][j] = duong_di[i][k] + duong_di[k][j];
                    }
                }
            }
        }
    }

    // In ra ma trận đường đi ngắn nhất
    for (int i = 1; i <= so_dinh; ++i) {
        for (int j = 1; j <= so_dinh; ++j) {
            cout << duong_di[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}




/*
Cấu trúc dữ liệu:
vector<vector<int>> duong_di: Một ma trận 2D để lưu trữ độ dài của đường đi ngắn nhất giữa các cặp đỉnh. 
Giá trị N được sử dụng để biểu thị rằng không có đường đi giữa hai đỉnh.
Thuật toán:
Floyd-Warshall Algorithm: Đây là một thuật toán để tìm đường đi ngắn nhất giữa mọi cặp đỉnh trong đồ thị 
có hướng và có trọng số. Thuật toán này hoạt động bằng cách cập nhật ma trận duong_di lặp qua tất cả các 
đỉnh trung gian. Mỗi lần cập nhật, thuật toán kiểm tra xem có tồn tại một đường đi ngắn hơn giữa hai đỉnh không và cập nhật ma trận nếu có.
*/