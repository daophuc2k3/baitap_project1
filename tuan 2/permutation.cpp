#include <bits/stdc++.h> 
using namespace std;

int n;
int a[30];  // Mảng để lưu trữ hoán vị
bool check[30];  // Mảng kiểm tra xem số đã được sử dụng trong hoán vị hay chưa

void Print(int n)
{
	for(int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";  // In ra từng phần tử của hoán vị, cách nhau bởi dấu cách
	}
	cout << endl;
}

// Hàm đệ quy để sinh hoán vị
void Back_track(int i)
{
	for(int j = 1; j <= n; j++)
	{
		if(check[j]){
			a[i] = j;  // Gán giá trị cho phần tử thứ i trong hoán vị
			check[j] = false;  // Đánh dấu số j đã được sử dụng
			if(i == n) Print(i);  // Nếu đã đủ n phần tử, in ra hoán vị
			else Back_track(i+1);  // Nếu chưa, tiếp tục sinh phần tử tiếp theo
			check[j] = true;  // Bỏ đánh dấu để thử các giá trị khác của số j
		}				
	}
}

int main() 
{ 
	cin >> n;  // Nhập giá trị n từ bàn phím
	for(int i = 1; i <= n; i++) check[i] = true;  // Khởi tạo mảng check
	Back_track(1);  // Gọi hàm Back_track để sinh hoán vị

	return 0;
}
