#include <bits/stdc++.h>
using namespace std;

const int oo = 1 << 29;  // Đặt giá trị oo (vô cùng) là 2^29 để đảm bảo an toàn khi thực hiện các phép toán.

// Cấu trúc lưu trữ thông tin của một cạnh trong đồ thị dòng.
struct edge
{
    int x, y, cap, flow;  // Đỉnh xuất phát, đỉnh kết thúc, dung lượng của cạnh, và luồng đã trải qua cạnh.
};

// Lớp đối tượng biểu diễn đồ thị dòng và thuật toán Ford-Fulkerson.
struct Flow
{
    int n, S, T;  // Số đỉnh, đỉnh nguồn, và đỉnh đích của đồ thị.
    vector<vector<int>> a;  // Ma trận liên thông của đồ thị.
    vector<int> cur, d;  // Vector để theo dõi trạng thái của thuật toán DFS và BFS.
    vector<edge> e;  // Danh sách cạnh của đồ thị.

    // Hàm tạo của lớp Flow, khởi tạo các biến cơ bản.
    Flow(int _n, int _S, int _T)
    {
        n = _n;
        S = _S;
        T = _T;
        a = vector<vector<int>>(n + 1);
        cur = vector<int>(n + 1);
        d = vector<int>(n + 1);
    }

    // Phương thức thêm một cạnh vào đồ thị.
    void addEdge(int x, int y, int _cap)
    {
        edge e1 = {x, y, _cap, 0};  // Cạnh chính.
        edge e2 = {y, x, 0, 0};     // Cạnh nghịch.
        a[x].push_back(e.size());
        e.push_back(e1);
        a[y].push_back(e.size());
        e.push_back(e2);
    }

    // Phương thức thực hiện thuật toán BFS để tìm kiếm đường đi tăng trong mạng dòng.
    int bfs()
    {
        queue<int> q;
        for (int i = 1; i <= n; i++)
            d[i] = -1;
        q.push(S);
        d[S] = 0;
        while (!q.empty() && d[T] < 0)
        {
            int x = q.front();
            q.pop();
            for (int i = 0; i < int(a[x].size()); i++)
            {
                int id = a[x][i], y = e[id].y;
                if (d[y] < 0 && e[id].flow < e[id].cap)
                    q.push(y), d[y] = d[x] + 1;
            }
        }
        return d[T] >= 0;
    }

    // Phương thức thực hiện thuật toán DFS để tìm kiếm đường đi tăng trong mạng dòng.
    int dfs(int x, int val)
    {
        if (!val)
            return 0;
        if (x == T)
            return val;
        for (; cur[x] < int(a[x].size()); cur[x]++)
        {
            int id = a[x][cur[x]], y = e[id].y;
            if (d[y] != d[x] + 1)
                continue;
            int pushed = dfs(y, min(val, e[id].cap - e[id].flow));
            if (pushed)
            {
                e[id].flow += pushed;
                e[id ^ 1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

    // Phương thức thực hiện thuật toán Ford-Fulkerson để tính luồng tối đa trong mạng dòng.
    int maxFlow()
    {
        int res = 0;
        while (bfs())
        {
            for (int i = 1; i <= n; i++)
                cur[i] = 0;
            while (1)
            {
                int val = dfs(S, oo);
                if (!val)
                    break;
                res += val;
            }
        }
        return res;
    }
};

int main()
{
    int n, m, S, T, x, y, z;
    scanf("%d%d%d%d", &n, &m, &S, &T);
    Flow u(n, S, T);  // Khởi tạo một đối tượng Flow với số đỉnh, đỉnh nguồn, và đỉnh đích.
    while (m--)
    {
        scanf("%d%d%d", &x, &y, &z);
        u.addEdge(x, y, z);  // Thêm cạnh vào đồ thị dòng.
    }
    printf("%d", u.maxFlow());  // In ra giá trị luồng tối đa trong đồ thị.

    return 0;
}




/*
Chương trình trên sử dụng thuật toán Ford-Fulkerson để tìm luồng tối đa trong mạng dòng
Thuật toán này hoạt động bằng cách lặp đi lặp lại quá trình tìm đường tăng cường trong mạng dòng và cập nhật giá trị luồng trên các cạnh.
*/