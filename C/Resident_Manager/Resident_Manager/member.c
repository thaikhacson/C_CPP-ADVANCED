#include <stdio.h>
#include <stdlib.h>
#include "member.h"

TreeNode* root = NULL;

/*
* Function: create_node
* Description: Tạo một nút mới trong cây và gán dữ liệu thành viên.
* Input:
*   - member: Dữ liệu thành viên cần gán cho nút mới.
* Output:
*   - Trả về con trỏ đến nút mới được tạo.
*   - Nếu không đủ bộ nhớ, hiển thị thông báo lỗi và thoát chương trình.
*/
TreeNode* create_node(Member memmber) {
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    if (new_node == NULL) {
        printf("Not enough memory.\n");
        exit(EXIT_FAILURE);
    }

    new_node->member = memmber;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

/*
* Function: insert
* Description: Thêm một thành viên mới vào cây nhị phân.
*              Hàm này được sử dụng để đảm bảo sự duy trì tính chất của cây nhị phân tìm kiếm.
* Input:
*   - rootPtr: con trỏ đến con trỏ của nút gốc của cây.
*   - member: dữ liệu thành viên cần thêm.
* Output:
*   - Trả về con trỏ đến nút chứa thông tin thành viên đã được thêm vào cây.
*/
TreeNode* insert(TreeNode** rootPtr, Member member) {
    if (*rootPtr == NULL) {
        *rootPtr = create_node(member);
        return *rootPtr;
    }

    if (strcmp(member.name, (*rootPtr)->member.name) < 0) {
        (*rootPtr)->left = insert(&((*rootPtr)->left), member);
    }
    else if (strcmp(member.name, (*rootPtr)->member.name) > 0) {
        (*rootPtr)->right = insert(&((*rootPtr)->right), member);
    }

    return *rootPtr;
}

/*
* Function: edit_member_info
* Description: Chỉnh sửa thông tin của một thành viên trong cây nhị phân dựa trên UID.
*              Tìm kiếm node chứa thành viên cần chỉnh sửa bằng cách sử dụng UID,
*              sau đó cập nhật thông tin thành viên từ một struct Member được cung cấp.
* Input:
*   - root: con trỏ đến nút gốc của cây.
*   - uid: chuỗi UID của thành viên cần chỉnh sửa.
*   - updated_member: con trỏ đến struct Member chứa thông tin mới cần cập nhật.
* Output:
*   - Nếu tìm thấy thành viên với UID tương ứng, thông tin được cập nhật.
*   - Nếu không tìm thấy, in ra thông báo lỗi.
*/
void edit_member_info(TreeNode* root, const char* uid, const Member* updated_member) {
    TreeNode* node = find_by_uid(root, uid);
    if (node != NULL) {
        // Cập nhật thông tin từ updated_member vào node tìm được
        strcpy(node->member.roomNumber, updated_member->roomNumber);
        strcpy(node->member.name, updated_member->name);
        strcpy(node->member.licensePlate, updated_member->licensePlate);
        // Bạn có thể thêm các trường khác cần cập nhật tại đây
    }
    else {
        printf("Khong tim thay thanh vien voi UID: %s\n", uid);
    }
}

/*
* Function: find_by_uid
* Description: Tìm kiếm thông tin thành viên trong cây nhị phân dựa vào UID.
*              Cây được duyệt một cách có thứ tự dựa trên UID, với giả định rằng cây
*              đã được sắp xếp theo trường UID của thành viên.
* Input:
*   - root: con trỏ đến nút gốc của cây.
*   - uid: chuỗi UID cần tìm kiếm.
* Output:
*   - Trả về con trỏ đến nút chứa thông tin thành viên có UID tương ứng.
*   - Nếu không tìm thấy, trả về NULL.
*/
TreeNode* find_by_uid(TreeNode* root, const char* uid) {
    if (root == NULL || strcmp(uid, root->member.uid) == 0) {
        return root;
    }

    if (strcmp(uid, root->member.uid) < 0) {
        return find_by_uid(root->left, uid);
    }
    else {
        return find_by_uid(root->right, uid);
    }
}

/*
* Function: find_by_license_plate
* Description: Tìm kiếm thông tin của thành viên trong cây nhị phân dựa trên biển số xe.
*              Cây được duyệt theo cả hai hướng (trái và phải) để tìm kiếm thông tin,
*              do không có sắp xếp cụ thể nào dựa trên biển số xe.
* Input:
*   - root: con trỏ đến nút gốc của cây.
*   - licensePlate: chuỗi biển số xe cần tìm kiếm.
* Output:
*   - Trả về con trỏ đến nút chứa thông tin thành viên có biển số xe tương ứng.
*   - Nếu không tìm thấy, trả về NULL.
*/
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

/*
* Function: display_tree
* Description: Hiển thị thông tin của tất cả thành viên trong cây nhị phân.
*              Duyệt cây theo thứ tự in-order (trái, nút gốc, phải),
*              đảm bảo thông tin được hiển thị theo thứ tự tên thành viên.
* Input:
*   - root: con trỏ đến nút gốc của cây.
* Output:
*   - Không có giá trị trả về. Thông tin của mỗi thành viên được in ra màn hình,
*     bao gồm UID, số phòng, tên, và biển số xe.
*/
void display_tree(TreeNode* root) {
    if (root != NULL) {
        display_tree(root->left);
        printf("UID: %s, Room Number: %s, Name: %s, License Plate: %s\n",
            root->member.uid, root->member.roomNumber, root->member.name, root->member.licensePlate);
        display_tree(root->right);
    }
}

/*
* Function: free_tree
* Description: Giải phóng bộ nhớ được cấp phát cho tất cả các nút trong cây nhị phân.
*              Hàm này sử dụng phương pháp duyệt cây theo thứ tự post-order để đảm bảo
*              mọi nút con được giải phóng trước khi giải phóng nút cha, tránh gặp phải
*              lỗi truy cập bộ nhớ không hợp lệ.
* Input:
*   - root: con trỏ đến nút gốc của cây.
* Output:
*   - Không có giá trị trả về. Tất cả bộ nhớ của cây được giải phóng.
*/
void free_tree(TreeNode* root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}