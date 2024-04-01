#include <bits/stdc++.h>
using namespace std;

// Hàm tính toán số đời của người tổ tiên từ một người được cho trước.
int calculateAncestor(map<pair<string, char>, pair<string, string>> family, string start) {
    int k = 0; // Biến k sẽ lưu trữ số đời của người tổ tiên
    queue<pair<string, int>> q; // Hàng đợi sẽ lưu trữ thông tin về người hiện tại và số đời của người đó
    q.push({start, k}); // Bắt đầu từ người được cho trước với số đời là 0
    while (!q.empty()) {
        string current = q.front().first; // Lấy thông tin về người hiện tại từ hàng đợi
        k = q.front().second; // Lấy số đời của người hiện tại từ hàng đợi
        q.pop(); // Loại bỏ người hiện tại khỏi hàng đợi vì chúng ta đã xem xét người này

        string father = family[{current, 'Y'}].first; // Lấy thông tin về cha của người hiện tại
        string mother = family[{current, 'Y'}].second; // Lấy thông tin về mẹ của người hiện tại
        if (father != "0000000") {
            q.push({father, k + 1}); // Nếu có thông tin về cha, thêm vào hàng đợi với số đời tăng lên 1
        }
        if (mother != "0000000") {
            q.push({mother, k + 1}); // Nếu có thông tin về mẹ, thêm vào hàng đợi với số đời tăng lên 1
        }
    }
    return k; // Trả về số đời của người tổ tiên
}


int main() {
    string code, birth, father, mother, region;
    char alive;
    int NUMBER_PEOPLE = 0; // Đếm số người trong DataBase
    map<string, int> birthCounts; // Đếm số người sinh vào mỗi ngày
    map<pair<string, char>, pair<string, string>> family; // Lưu thông tin gia đình
    vector<string> birthDates; // Lưu thông tin ngày sinh của từng người

    // Đọc dữ liệu về công dân từ bảng dữ liệu đầu vào
    cin >> code; // Đọc mã số của công dân
    while (code != "*") { // Lặp cho đến khi gặp ký tự '*'
        cin >> birth >> father >> mother >> alive >> region; // Đọc thông tin về ngày sinh, cha, mẹ, tình trạng sống, và khu vực của công dân
        NUMBER_PEOPLE++; // Tăng số lượng công dân lên 1
        birthCounts[birth]++; // Tăng số lượng người sinh ra vào ngày nhất định lên 1
        family[{code, alive}] = {father, mother}; // Lưu thông tin về cha và mẹ của công dân vào biểu đồ gia phả
        birthDates.push_back(birth); // Lưu ngày sinh của công dân vào danh sách ngày sinh
        cin >> code; // Đọc mã số của công dân tiếp theo
    }


    string query;
    cin >> query;
    while (query != "***") {
        if (query == "NUMBER_PEOPLE") 
            cout << NUMBER_PEOPLE << "\n";
            // Xử lý các truy vấn trong khối lệnh này
        else if (query == "NUMBER_PEOPLE_BORN_AT") {
            string date;
            cin >> date;
            cout << birthCounts[date] << "\n";
        }
        else if (query == "MOST_ALIVE_ANCESTOR") {
            string s;
            cin >> s; // Đọc mã số của người được tìm tổ tiên
            cout << calculateAncestor(family, s) << "\n"; // In ra kết quả tìm tổ tiên sống nhất và khoảng cách thế hệ
        }
        else if (query == "NUMBER_PEOPLE_BORN_BETWEEN") {
            string from, to;
            cin >> from >> to; // Đọc khoảng thời gian từ và đến
            int people = 0;
            for (string d : birthDates) {
                if (d >= from && d <= to) people++; // Đếm số người sinh ra trong khoảng thời gian
            }
            cout << people << "\n"; // In ra kết quả số người sinh ra trong khoảng thời gian
        }
        else if (query == "MAX_UNRELATED_PEOPLE") {
            set<string> unrelatedPeople;
            for (auto f : family) {
                if (!unrelatedPeople.count(f.second.first) && !unrelatedPeople.count(f.second.second)) 
                    unrelatedPeople.insert(f.first.first); // Thêm các người không có mối quan hệ cha-mẹ vào tập hợp
            }
            cout << unrelatedPeople.size() << "\n"; // In ra kết quả kích thước của tập hợp người không có mối quan hệ cha-mẹ lớn nhất
        }
        cin >> query; // Đọc truy vấn tiếp theo

    }

    return 0;
}




/*
Dùng map để lưu thông tin gia đình giúp tìm cha mẹ một cách nhanh chóng.
Dùng map để đếm số lượng người sinh ra theo từng ngày giúp thực hiện truy vấn NUMBER_PEOPLE_BORN_AT.
Sử dụng vector để lưu trữ ngày sinh giúp thực hiện truy vấn NUMBER_PEOPLE_BORN_BETWEEN.
Sử dụng set unrelatedPeople để lưu trữ những người không có mối quan hệ cha-mẹ, giúp thực hiện truy vấn MAX_UNRELATED_PEOPLE.
Sử dụng hàm calculateAncestor để tính số thế hệ giữa một người và tổ tiên sống nhất của người đó, giúp thực hiện truy vấn MOST_ALIVE_ANCESTOR.
*/