#include <bits/stdc++.h>

using namespace std;

// Định nghĩa cấu trúc của một nút trong cây
struct TreeNode {
    int id; // Mã số của nút
    TreeNode* parent; // Con trỏ đến nút cha
    vector<TreeNode*> children; // Danh sách con của nút
};

// Biến toàn cục lưu trữ nút gốc của cây
TreeNode* root = nullptr;

// Danh sách tất cả các nút trong cây
vector<TreeNode*> nodes;

// Hàm tìm nút có mã số là id
TreeNode* findNode(int id) {
    for (TreeNode* node : nodes) {
        if (node->id == id) {
            return node;
        }
    }
    return nullptr;
}

// Hàm thêm một nút mới vào cây
void insertNode(int u, int v) {
    TreeNode* newNode = new TreeNode(); // Tạo một nút mới
    newNode->id = u; // Thiết lập mã số cho nút mới
    TreeNode* parentNode = findNode(v); // Tìm nút cha có mã số là v

    // Nếu nút cha tồn tại, thêm nút mới vào danh sách con của nó
    if (parentNode != nullptr) {
        parentNode->children.push_back(newNode);
        newNode->parent = parentNode;
    }

    // Thêm nút mới vào danh sách tất cả các nút
    nodes.push_back(newNode);
}

// Hàm duyệt cây theo thứ tự trước (PreOrder)
void preOrder(TreeNode* node) {
    if (node != nullptr) {
        cout << node->id << " "; // In mã số của nút hiện tại
        for (TreeNode* child : node->children) {
            preOrder(child); // Duyệt các nút con
        }
    }
}

// Hàm duyệt cây theo thứ tự giữa (InOrder)
void inOrder(TreeNode* node) {
    if (node != nullptr) {
        if (!node->children.empty()) {
            inOrder(node->children[0]); // Duyệt nút con đầu tiên
        }
        cout << node->id << " "; // In mã số của nút hiện tại
        for (size_t i = 1; i < node->children.size(); i++) {
            inOrder(node->children[i]); // Duyệt các nút con còn lại
        }
    }
}

// Hàm duyệt cây theo thứ tự sau (PostOrder)
void postOrder(TreeNode* node) {
    if (node != nullptr) {
        for (TreeNode* child : node->children) {
            postOrder(child); // Duyệt các nút con
        }
        cout << node->id << " "; // In mã số của nút hiện tại
    }
}

// Hàm main
int main() {
    string command;
    int u, v;

    // Đọc và xử lý lần lượt các lệnh từ đầu vào
    while (cin >> command) {
        if (command == "MakeRoot") {
            cin >> u; // Đọc mã số của nút gốc
            root = new TreeNode(); // Tạo một nút mới làm nút gốc
            root->id = u; // Thiết lập mã số cho nút gốc
            nodes.push_back(root);
        } else if (command == "Insert") {
            cin >> u >> v; // Đọc mã số của nút mới và mã số của nút cha
            insertNode(u, v); // Thêm nút mới vào cây
        } else if (command == "PreOrder") {
            preOrder(root); // Duyệt cây theo thứ tự trước và in ra màn hình
            cout << endl;
        } else if (command == "InOrder") {
            inOrder(root); // Duyệt cây theo thứ tự giữa và in ra màn hình
            cout << endl;
        } else if (command == "PostOrder") {
            postOrder(root); // Duyệt cây theo thứ tự sau và in ra màn hình
            cout << endl;
        } else if (command == "*") {
            break; // Kết thúc đọc dữ liệu nếu gặp dấu "*"
        }
    }

    return 0;
}



/*
Chương trình sử dụng các cấu trúc dữ liệu như struct TreeNode để biểu diễn các nút trong cây và vector<TreeNode*> để lưu trữ tất cả các nút trong cây. Cụ thể:

struct TreeNode: Đây là một cấu trúc dữ liệu để biểu diễn mỗi nút trong cây. Nó có các trường sau:

int id: Mã số của nút.
TreeNode* parent: Con trỏ đến nút cha của nút hiện tại.
vector<TreeNode*> children: Một vector chứa con trỏ đến tất cả các nút con của nút hiện tại.
vector<TreeNode*> nodes: Đây là một vector để lưu trữ tất cả các nút trong cây. Mỗi khi một nút mới được tạo, con trỏ đến nút đó được thêm vào vector này.

TreeNode* root: Biến con trỏ này được sử dụng để theo dõi nút gốc của cây.

Các hàm như findNode, insertNode, preOrder, inOrder, postOrder sử dụng các cấu trúc và dữ liệu trên để thực hiện các thao tác trên cây.

Chương trình sử dụng các cấu trúc dữ liệu này để xây dựng cây và thực hiện các thao tác duyệt cây theo các phương pháp PreOrder, InOrder, và PostOrder.
*/