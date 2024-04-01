#include <bits/stdc++.h>

unsigned long long power(unsigned long long x, int y, int p)
{
	unsigned long long res = 1; 

	x = x % p; 

	while (y > 0)
	{
		if (y & 1)	res = (res * x) % p;  // Nếu y là số lẻ, nhân thêm x vào kết quả
		y = y >> 1; // y = y/2
		x = (x * x) % p;  // Bình phương x
	}
	return res;
}

unsigned long long modInverse(unsigned long long n, int p)
{
	return power(n, p - 2, p);  // Tính nghịch đảo modulo p của n bằng cách sử dụng định lý Fermat's Little
}

unsigned long long nCrModPFermat(unsigned long long n, int r, int p)
{
	if (n < r)	return 0;  // Trường hợp n < r, không có cách chọn r phần tử từ n phần tử
	if (r == 0)	return 1;  // Trường hợp r = 0, chỉ có một cách chọn

	unsigned long long fac[n + 1];
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = (fac[i - 1] * i) % p;  // Tính giai thừa modulo p

	return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;  // Tính toán nCr theo công thức
}

int main()
{
	int k, n;
	int p = 1000000007;  // Modulo p theo yêu cầu đề bài
	std::cin >> k >> n;
	std::cout << nCrModPFermat(n, k, p);  // In ra giá trị C(k, n) modulo 10^9 + 7
	
	return 0;
}
