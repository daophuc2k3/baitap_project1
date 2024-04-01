#include <bits/stdc++.h> 

using namespace std;

int n;
int a[30];  // Mảng để lưu trữ dãy nhị phân
bool xd[30];  // Mảng để kiểm tra xem số tương ứng đã được sử dụng hay chưa

void Print(int n)
{
	for(int i = 1; i <= n; i++)
	{
		cout << a[i];
	}
	cout << endl;
}

void Back_track(int i)
{
	for(int j = 0; j <= 1; j++)
	{
			a[i] = j;
			if(i == n) Print(i);  // In ra dãy nhị phân khi đã có đủ n ký tự
			else Back_track(i+1);	
	}
}

int main() 
{ 
	cin >> n;  // Nhập giá trị n từ bàn phím
	Back_track(1);  // Gọi hàm Back_track để sinh dãy nhị phân

	return 0;
}
