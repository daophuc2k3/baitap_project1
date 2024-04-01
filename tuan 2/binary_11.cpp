#include <bits/stdc++.h> 

using namespace std;

int n;
int a[30];  // Mảng để lưu trữ dãy nhị phân
// Hàm kiểm tra xem dãy nhị phân có chứa 2 số 1 liên tiếp không
void Print(int n)
{
	bool check = true;
	for(int i = 1; i <= n-1; i++)
	{
		if(a[i] == 1 && a[i+1] == 1) 
		{
			check = false;
			break;
		}
	}
	// Nếu không có 2 số 1 liên tiếp, in ra dãy nhị phân
	if(check == true){
		for(int i = 1; i <= n; i++)
		{
			cout << a[i];
		}
		cout << endl;
	}
}

// Hàm đệ quy để sinh dãy nhị phân không có 2 số 1 liên tiếp
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
	Back_track(1);  // Gọi hàm Back_track để sinh dãy nhị phân không có 2 số 1 liên tiếp

	return 0;
}
