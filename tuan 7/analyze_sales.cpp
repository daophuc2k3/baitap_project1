#include <bits/stdc++.h>
using namespace std;

// Hàm chuyển đổi thời gian từ dạng HH:MM:SS sang giây
int timeToSecond(string time) {
    return stoi(time.substr(0, 2)) * 3600 + stoi(time.substr(3, 2)) * 60 + stoi(time.substr(6, 2));
}

int main() {
    int numOrders = 0;  // Số lượng đơn hàng
    int totalRevenue = 0;  // Tổng doanh thu của cả công ty
    unordered_map<string, int> revenueByShop;  // Doanh thu từng cửa hàng
    unordered_map<string, int> customerShopConsume;  // Doanh thu từng khách hàng tại từng cửa hàng
    vector<int> revenueInTime(86400, 0);  // Doanh thu tích lũy theo thời gian

    string customerId, productId, shopId, orderTime;
    int orderPrice;

    // Đọc dữ liệu đầu tiên về đơn hàng, sử dụng dấu # để kết thúc
    cin >> customerId;
    while (customerId != "#") {
        cin >> productId >> orderPrice >> shopId >> orderTime;
        numOrders++;
        totalRevenue += orderPrice;
        revenueByShop[shopId] += orderPrice;
        customerShopConsume[customerId + shopId] += orderPrice;
        revenueInTime[timeToSecond(orderTime)] += orderPrice;
        cin >> customerId;
    }

    // Tính tổng doanh thu theo thời gian tích lũy
    for (int i = 1; i < 86400; i++) {
        revenueInTime[i] += revenueInTime[i - 1];
    }

    // Đọc và xử lý các truy vấn, sử dụng dấu # để kết thúc
    string query;
    cin >> query;
    while (query != "#") {
        if (query == "?total_number_orders") {
            // In ra số lượng đơn hàng
            cout << numOrders << "\n";
        } else if (query == "?total_revenue") {
            // In ra tổng doanh thu của cả công ty
            cout << totalRevenue << "\n";
        } else if (query == "?revenue_of_shop") {
            // In ra doanh thu của một cửa hàng cụ thể
            string shopId;
            cin >> shopId;
            cout << revenueByShop[shopId] << "\n";
        } else if (query == "?total_consume_of_customer_shop") {
            // In ra doanh thu từ một khách hàng tại một cửa hàng cụ thể
            string customerId, shopId;
            cin >> customerId >> shopId;
            cout << customerShopConsume[customerId + shopId] << "\n";
        } else if (query == "?total_revenue_in_period") {
            // In ra tổng doanh thu trong một khoảng thời gian
            int result = 0;
            string startTime, endTime;
            cin >> startTime >> endTime;
            int secondFrom = timeToSecond(startTime);
            int secondTo = timeToSecond(endTime);
            if (secondFrom != 0) {
                result = revenueInTime[secondTo] - revenueInTime[secondFrom - 1];
            } else {
                result = revenueInTime[secondTo];
            }
            cout << result << "\n";
        }
        cin >> query;
    }
}
