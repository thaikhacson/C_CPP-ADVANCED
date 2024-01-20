#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cấu trúc dữ liệu của mỗi người
struct Person {
    char name[50];
    int age;
    char phone[15];
};

// Cấu trúc dữ liệu của mỗi node trong cây
struct TreeNode {
    struct Person person;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Hàm để tạo một node mới trong cây
struct TreeNode* create_node(struct Person person) {
    struct TreeNode* new_node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (new_node == NULL) {
        printf("Khong du bo nho.\n");
        exit(EXIT_FAILURE);
    }

    new_node->person = person;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

// Hàm để thêm một người mới vào cây
struct TreeNode* insert(struct TreeNode* root, struct Person person) {
    if (root == NULL) {
        return create_node(person);
    }

    if (strcmp(person.name, root->person.name) < 0) {
        root->left = insert(root->left, person);
    } else if (strcmp(person.name, root->person.name) > 0) {
        root->right = insert(root->right, person);
    }

    return root;
}

// Hàm để hiển thị thông tin của tất cả người trong cây (duyệt cây theo thứ tự in-order)
void display_tree(struct TreeNode* root) {
    if (root != NULL) {
        display_tree(root->left);
        printf("Name: %s, Age: %d, Phone: %s\n", root->person.name, root->person.age, root->person.phone);
        display_tree(root->right);
    }
}

// Hàm để giải phóng bộ nhớ của cây
void free_tree(struct TreeNode* root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int main() {
    struct TreeNode* root = NULL;

    // Khởi tạo và thêm người vào cây
    struct Person alice = {"Alice", 25, "123-456-7890"};
    struct Person bob = {"Bob", 30, "987-654-3210"};
    struct Person charlie = {"Charlie", 22, "555-123-4567"};

    root = insert(root, alice);
    root = insert(root, bob);
    root = insert(root, charlie);

    // Hiển thị thông tin của tất cả người trong cây
    display_tree(root);

    // Giải phóng bộ nhớ của cây khi không cần sử dụng nữa
    free_tree(root);

    return 0;
}
