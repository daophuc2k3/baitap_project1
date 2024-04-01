#include <bits/stdc++.h>  // Thêm tất cả các thư viện của C++ để sử dụng
using namespace std;

int main() 
{ 
	int n, Q;  // Khai báo biến n (số phần tử trong dãy) và Q (tổng của dãy)
	cin >> n;  // Nhập số phần tử trong dãy
	Q = 0;  // Khởi tạo tổng Q ban đầu
	int a[n];  // Khai báo mảng a có n phần tử để lưu dãy số
	for(int i = 0; i < n; i++) {
		cin >> a[i];  // Nhập từng phần tử của dãy và lưu vào mảng a
	}
	for(int i = 0; i < n; i++) {
		Q += a[i];  // Tính tổng các phần tử của dãy và lưu vào biến Q
	}
	cout << Q << endl;  // Xuất giá trị tổng Q ra màn hình
	return 0;  // Kết thúc chương trình
}
