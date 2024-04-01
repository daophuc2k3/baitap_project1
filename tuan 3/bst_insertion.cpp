#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Hàm để chèn một khóa vào cây BST
TreeNode* insert(TreeNode* root, int key) {
    if (root == NULL) {
        return new TreeNode(key);
    }
    if (key < root->val) {
        root->left = insert(root->left, key);
    } else if (key > root->val) {
        root->right = insert(root->right, key);
    }
    return root;
}

// Hàm duyệt cây theo thứ tự trước (pre-order traversal)
void preOrder(TreeNode* root) {
    if (root != NULL) {
        cout << root->val << " ";  // In giá trị của nút hiện tại
        preOrder(root->left);  // Duyệt nút con bên trái
        preOrder(root->right);  // Duyệt nút con bên phải
    }
}

int main() {
    TreeNode* root = NULL;  // Khởi tạo cây BST

    string command;
    int key;

    // Đọc các lệnh từ input
    while (cin >> command) {
        if (command == "insert") {
            cin >> key;
            root = insert(root, key);  // Gọi hàm chèn để thêm khóa vào BST
        } else if (command == "#") {
            break;  // Kết thúc input nếu gặp dấu #
        }
    }

    preOrder(root);  // In ra kết quả theo thứ tự trước
    return 0;
}



/*
-Cấu trúc dữ liệu TreeNode:

Định nghĩa một cấu trúc dữ liệu TreeNode để biểu diễn mỗi nút trong cây BST.
Mỗi nút bao gồm:
val: Giá trị của nút.
left: Con trỏ tới nút con bên trái.
right: Con trỏ tới nút con bên phải.
Hàm khởi tạo TreeNode được sử dụng để tạo một nút mới với giá trị được đặt theo đối số truyền vào.

-Hàm insert:
Hàm insert thực hiện chèn một khóa mới vào cây BST.
Nếu cây rỗng (NULL), nó trả về một nút mới với giá trị là khóa mới.
Nếu không, nó thực hiện duyệt cây để xác định vị trí chính xác cho khóa mới và chèn nó vào cây.

-Hàm preOrder:
Hàm preOrder thực hiện duyệt cây theo thứ tự trước (pre-order traversal) và in giá trị của các nút.
Duyệt từ nút gốc xuống nút con bên trái, sau đó xuống nút con bên phải.

-Hàm main:
Tạo một con trỏ root để đại diện cho gốc của cây BST.
Đọc các lệnh từ input, và nếu lệnh là "insert", thực hiện việc chèn khóa mới vào cây bằng cách gọi hàm insert.
Kết thúc khi gặp dấu "#" trong input.
In ra kết quả của pre-order traversal để hiển thị giá trị của các nút trong cây.

Cấu trúc dữ liệu BST được thiết kế để cung cấp việc tìm kiếm, chèn và xóa với hiệu suất tốt, 
giữ cho giá trị ở mỗi nút bên trái nhỏ hơn giá trị ở nút gốc và giá trị ở mỗi nút bên phải lớn hơn giá trị ở 
nút gốc. Chính vì vậy, việc duyệt cây theo thứ tự trước cung cấp kết quả in ra theo thứ tự tăng dần.
*/