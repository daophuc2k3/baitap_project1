#include <bits/stdc++.h>
using namespace std;

// Hàm kiểm tra xem có chu kỳ chuyển khoản từ tài khoản acc1 với độ dài k không
int inspect_cycle(map<string, vector<string>> inspect, string acc1, string acc2, int k, set<string>& visited){
    if (k < 0) return 0; // Nếu độ dài âm, không có chu kỳ
    if (k == 0) {
        return (acc1 == acc2) ? 1 : 0; // Nếu độ dài là 0, kiểm tra xem acc1 có bằng acc2 không
    }
    if (visited.find(acc1) != visited.end()) return 0; // Nếu tài khoản đã được xem xét, không tiếp tục kiểm tra
    for (int i = 0; i < inspect[acc1].size(); i++) {
        string curAcc = inspect[acc1][i];
        if (visited.find(curAcc) != visited.end()) continue; // Nếu tài khoản đã được xem xét, không tiếp tục kiểm tra
        map<string, vector<string>> current = inspect;
        current[acc1].erase(current[acc1].begin()+i);
        visited.insert(curAcc);
        if (inspect_cycle(current, curAcc, acc2, k-1, visited)) return 1; // Nếu có chu kỳ từ tài khoản hiện tại
        visited.erase(curAcc);
    }
    return 0; // Không có chu kỳ
}

int main(){
    int number_transactions = 0; // Số lượng giao dịch
    int total_money_transaction = 0; // Tổng số tiền của tất cả các giao dịch
    set<string> accounts; // Danh sách tài khoản xuất hiện trong giao dịch
    map<string, int> transaction_from; // Tổng số tiền chuyển từ mỗi tài khoản
    map<string, vector<string>> inspect; // Danh sách tài khoản nhận được từng tài khoản
    string acc1, acc2, time, atm; // Thông tin giao dịch
    int money; // Số tiền chuyển
    cin >> acc1; // Đọc tên tài khoản acc1 từ dữ liệu đầu vào
	while (acc1 != "#") { 
    	cin >> acc2 >> money >> time >> atm; // Đọc thông tin giao dịch từ dữ liệu đầu vào
    	number_transactions++; // Tăng số lượng giao dịch lên 1
    	total_money_transaction += money; // Cộng số tiền giao dịch vào tổng số tiền
    	accounts.insert(acc1); // Thêm tài khoản acc1 vào danh sách tất cả các tài khoản xuất hiện
    	accounts.insert(acc2); // Thêm tài khoản acc2 vào danh sách tất cả các tài khoản xuất hiện
    	transaction_from[acc1] += money; // Cộng số tiền giao dịch từ tài khoản acc1 vào tổng số tiền của tài khoản đó
    	inspect[acc1].push_back(acc2); // Thêm tài khoản acc2 vào danh sách các tài khoản nhận được từ tài khoản acc1
		cin >> acc1; // Đọc tiếp tên tài khoản acc1 cho giao dịch tiếp theo
	}

    
    string query;
    cin >> query;
    
    while (query != "#") {
        if (query == "?number_transactions") cout << number_transactions << "\n";
        else if (query == "?total_money_transaction") cout << total_money_transaction << "\n";
        else if (query == "?list_sorted_accounts") {
            for (string acc : accounts) cout << acc << " ";
            cout << "\n";
        }
        else if (query == "?total_money_transaction_from") {
            string acc;
            cin >> acc;
            cout << transaction_from[acc] << "\n";
        }
        else if (query == "?inspect_cycle") {
            string acc;
            int k;
            cin >> acc >> k;
            set<string> visited;
            cout << inspect_cycle(inspect, acc, acc, k, visited) << "\n";
        }
        cin >> query;
    }
    return 0;
}
