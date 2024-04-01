#include <bits/stdc++.h>  // Thêm tất cả các thư viện của C++ để sử dụng
using namespace std;

// Hàm tìm giá trị lớn nhất trong đoạn từ i đến j
int FindMax(int i, int j, int a[]){
    int max_val = -1000;
    for(int k = i; k <= j; k++)
        max_val = max(max_val, a[k]);
    return max_val;
}

int main() 
{ 
    int n;
    cin >> n;  // Nhập số lượng phần tử trong dãy

    int a[n];
    for(int i = 1; i <= n; i++) 
        cin >> a[i];  // Nhập dãy số

    int max_val = a[1];  // Khởi tạo giá trị lớn nhất bằng phần tử đầu tiên của dãy
    int min_val = a[1];  // Khởi tạo giá trị nhỏ nhất bằng phần tử đầu tiên của dãy
    int sum = 0;  // Khởi tạo tổng bằng 0

    // Tính giá trị lớn nhất, nhỏ nhất và tổng của dãy
    for(int i = 1; i <= n; i++){
        max_val = max(max_val, a[i]);
        min_val = min(min_val, a[i]);
        sum += a[i];
    }
    
    string lenh;
    while(getline(cin, lenh)){
        if(lenh == "*") continue;  // Bỏ qua dòng chứa "*"
        if(lenh == "***") break;  // Kết thúc khi gặp dòng chứa "***"
        
        // Các truy vấn
        if(lenh == "find-max") cout << max_val << endl;
        if(lenh == "find-min") cout << min_val << endl;
        if(lenh == "sum") cout << sum << endl;
        
        // Truy vấn đặc biệt
        if(lenh.find("find-max-segment") != -1){
            string lenhi, lenhj;
            bool t = false;
            
            // Trích xuất i và j từ dòng truy vấn find-max-segment
            for(int k = 17; k < lenh.length(); k++){
                if(lenh[k] == ' '){
                    t = true;
                    continue;
                }
                if(t) lenhj += lenh[k];
                else lenhi += lenh[k];
            }
            
            int i = stoi(lenhi);
            int j = stoi(lenhj);
            cout << FindMax(i, j, a) << endl;  // Gọi hàm FindMax và in ra giá trị lớn nhất trong đoạn
        }
    }
    return 0;
}
