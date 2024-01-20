#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Member{
    char uid[20];
    char roomNumber[10];
    char name[50];
    char licensePlate[20];
} Member;

typedef struct TreeNode {
    struct Member member;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

// Hàm để tạo một node mới trong cây
TreeNode* create_node(Member memmber) {
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    if (new_node == NULL) {
        printf("Khong du bo nho.\n");
        exit(EXIT_FAILURE);
    }

    new_node->member = memmber;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

// Hàm để thêm một người mới vào cây
TreeNode* insert(TreeNode* root, Member member) {
    if (root == NULL) {
        return create_node(member);
    }

    if (strcmp(member.name, root->member.name) < 0) {
        root->left = insert(root->left, member);
    } else if (strcmp(member.name, root->member.name) > 0) {
        root->right = insert(root->right, member);
    }

    return root;
}

// Hàm để hiển thị thông tin của tất cả người trong cây (duyệt cây theo thứ tự in-order)
void display_tree(TreeNode* root) {
    if (root != NULL) {
        display_tree(root->left);
        printf("UID: %s, Room Number: %s, Name: %s, License Plate: %s\n", 
                root->member.uid, root->member.roomNumber, root->member.name, root->member.licensePlate);
        display_tree(root->right);
    }
}

//Hàm để tìm thông tin người trong cây dựa vào uid
TreeNode* find_by_uid(TreeNode* root, const char* uid) {
    if (root == NULL || strcmp(uid, root->member.uid) == 0) {
        return root;
    }

    if (strcmp(uid, root->member.uid) < 0) {
        return find_by_uid(root->left, uid);
    } else {
        return find_by_uid(root->right, uid);
    }
}

// Hàm để tìm thông tin người trong cây dựa vào licensePlate
TreeNode* find_by_license_plate(TreeNode* root, const char* licensePlate) {
    if (root == NULL) {
        return NULL;
    }

    // Kiểm tra nút hiện tại
    if (strcmp(licensePlate, root->member.licensePlate) == 0) {
        return root;
    }

    // Tìm kiếm trong cây con bên trái và bên phải
    TreeNode* leftSearch = find_by_license_plate(root->left, licensePlate);
    if (leftSearch != NULL) {
        return leftSearch;
    }

    return find_by_license_plate(root->right, licensePlate);
}

// Hàm để chỉnh sửa thông tin của một thành viên
void edit_member_info(TreeNode* root, const char* uid, const Member* updated_member) {
    TreeNode* node = find_by_uid(root, uid);
    if (node != NULL) {
        // Cập nhật thông tin từ updated_member vào node tìm được
        strcpy(node->member.roomNumber, updated_member->roomNumber);
        strcpy(node->member.name, updated_member->name);
        strcpy(node->member.licensePlate, updated_member->licensePlate);
        // Bạn có thể thêm các trường khác cần cập nhật tại đây
    } else {
        printf("Khong tim thay thanh vien voi UID: %s\n", uid);
    }
}

// Hàm để giải phóng bộ nhớ của cây
void free_tree(TreeNode* root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int main() {
    TreeNode* root = NULL;

    // Khởi tạo và thêm người vào cây
    Member alice = {"1234", "A101", "Hai Ha", "37A-12345"};
    Member bob = {"1235", "A102", "Hai Yen", "37A-12346"};
    Member charlie = {"1236", "A103", "Hai Anh", "37A-12347"};

    root = insert(root, alice);
    root = insert(root, bob);
    root = insert(root, charlie);

    // Hiển thị thông tin của tất cả người trong cây
    display_tree(root);

    // Tìm người thông qua UID
    const char* search_uid = "1235";
    TreeNode* found_node = find_by_uid(root, search_uid);

    if (found_node != NULL) {
        printf("\nFound person with UID %s:\n", search_uid);
        printf("Name: %s, Room Number: %s, License Plate: %s\n", 
               found_node->member.name, found_node->member.roomNumber, found_node->member.licensePlate);
    } else {
        printf("\nPerson with UID %s not found.\n", search_uid);
    }

    // Giải phóng bộ nhớ của cây khi không cần sử dụng nữa
    free_tree(root);

    return 0;
}