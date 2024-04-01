#include <bits/stdc++.h>
using namespace std;

int main () {
  int a, b, c;
  cin >> a >> b >> c;  // Nhập các hệ số a, b, c từ bàn phím

  int delta = b * b - 4 * a * c;  // Tính delta

  if (delta == 0) {
    float x0 = -b / (2.0 * a);  // Nếu delta = 0, có một nghiệm kép x0
    cout << setprecision(2) << fixed << x0;  // In ra nghiệm x0 với độ chính xác 2 số sau dấu thập phân
  }

  if (delta > 0) {
    float x1 = (-b - sqrt(delta)) / (2.0 * a);  // Nếu delta > 0, có hai nghiệm phân biệt x1 và x2
    float x2 = (-b + sqrt(delta)) / (2.0 * a);
    cout << setprecision(2) << fixed << x1 << " " << setprecision(2) << fixed << x2;  // In ra hai nghiệm x1 và x2
  }

  if (delta < 0) {
    cout << "NO SOLUTION";  // Nếu delta < 0, không có nghiệm
  }

  return 0;
}
