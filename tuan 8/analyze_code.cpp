#include <bits/stdc++.h>
using namespace std;
// Hàm chuyển đổi thời gian từ dạng HH:MM:SS thành số giây.
inline int time_to_second(string time) {
    return stoi(time.substr(0,2))*3600 + stoi(time.substr(3,2))*60 + stoi(time.substr(6,2));
}

int main(){
    string userid, pid, time, status;
    int point;
    int submissions = 0; // Số lượng giao dịch tổng cộng
    int errors = 0; // Số lượng giao dịch có trạng thái ERR
    unordered_map<string, int> errors_of; // Số lượng giao dịch có trạng thái ERR của từng người dùng
    map<pair<string, string>, int> points_in; // Số điểm cao nhất mà mỗi người dùng đạt được cho mỗi bài toán
    unordered_map<string, int> points_of; // Tổng số điểm của mỗi người dùng
    vector<int> submission_before(86400, 0); // Số lượng giao dịch trước mỗi khoảng thời gian
    
    // Đọc thông tin về các giao dịch từ dữ liệu đầu vào
	cin >> userid; // Đọc thông tin về người dùng

	while(userid != "#") {
    cin >> pid >> time >> status >> point; // Đọc thông tin về bài toán, thời gian, trạng thái, và điểm
    submissions += 1; // Tăng số lượng giao dịch tổng cộng

    // Nếu trạng thái là "ERR", tăng số lượng giao dịch có lỗi và số lượng lỗi của người dùng tương ứng
    if (status == "ERR") {
        errors += 1;
        errors_of[userid] += 1;
    }
	// Nếu điểm của lần nộp hiện tại lớn hơn điểm đã lưu trữ, cập nhật điểm mới
    if (point > points_in[{userid, pid}]) points_in[{userid, pid}] = point;
	// Tăng số lượng giao dịch trước mỗi khoảng thời gian
    submission_before[time_to_second(time)] += 1;
	// Đọc thông tin về người dùng tiếp theo
    cin >> userid;
}


    // Tính tổng số điểm của từng người dùng
    for(pair<pair<string, string>, int> p : points_in){
        points_of[p.first.first] += p.second;
    }

    // Cộng dồn số lượng giao dịch trước mỗi khoảng thời gian
    for(int i = 1; i < 86400; i++) {
        submission_before[i] += submission_before[i-1];
    }

    string query;
    cin >> query;
    while(query != "#") {
        if (query == "?total_number_submissions") cout << submissions << "\n";
        else if (query == "?number_error_submision") cout << errors << "\n";
        else if (query == "?number_error_submision_of_user") {
            string uid;
            cin >> uid;
            cout << errors_of[uid] << "\n";
        }
        else if (query == "?total_point_of_user") {
            string uid;
            cin >> uid;
            cout << points_of[uid] << "\n";            
        }
        else if (query == "?number_submission_period") {
            string from, to;
            cin >> from >> to;
            int second_from = time_to_second(from);
            int second_to = time_to_second(to);
            int totalSubmit = (second_from == 0) ? submission_before[second_to] : (submission_before[second_to] - submission_before[second_from - 1]); // Tính toán tổng số lượng giao dịch trong khoảng thời gian cụ thể
            cout << totalSubmit << '\n';
        }
        cin >> query;
    }
    return 0;
}




/*
unordered_map: Được sử dụng để lưu trữ số lượng lỗi của từng người dùng (errors_of), và điểm tối đa đạt được cho mỗi vấn đề của mỗi người dùng (points_in).

map: Sử dụng để lưu trữ tổng số điểm của mỗi người dùng (points_of). Map này giữ các cặp người dùng và điểm tối đa của họ.

vector: Dùng để lưu trữ số lượng giao dịch trước mỗi khoảng thời gian (submission_before). Vector này giúp tính tổng số lượng giao dịch trong mỗi khoảng thời gian.

set và string: Sử dụng để lưu trữ danh sách các tài khoản người dùng để trả lời câu hỏi ?list_sorted_accounts.
*/