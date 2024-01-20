#include <stdio.h>
#include <string.h>
#include "manager.h"
#include "member.h"

extern TreeNode* root;

/*
* Function: addMember
* Description: Thêm một thành viên mới vào tập tin và cây nhị phân tìm kiếm.
* Input:
*   - filename: Tên tập tin để thêm thông tin thành viên.
*   - member: Dữ liệu của thành viên cần thêm.
* Output:
*   - Ghi thông tin thành viên vào tập tin và thêm một node mới vào cây.
*   - Hiển thị thông báo nếu quá trình thêm thành công hoặc gặp lỗi.
*/
void addMember(const char* filename, Member member) {
    FILE* file = fopen(filename, "a");

    if (file == NULL) {
        printf("Cannot open File!\n");
        return;
    }

    // Kiểm tra kích thước của file để xác định xem file có rỗng hay không
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);

    if (fileSize > 0) {
        fprintf(file, "\n");  // Thêm skí tự xuống dòng trước khi thêm thành viên mới
    }

    // Ghi thông tin thành viên vào file
    fprintf(file, "%s,%s,%s,%s", member.uid, member.roomNumber, member.name, member.licensePlate);

    fclose(file);

    insert(&root, member);

    printf("Member added successfully!\n");
}

/*
* Function: deleteMember
* Description: Xóa thông tin thành viên từ file và cập nhật cây nhị phân tìm kiếm.
* Input:
*   - filename: Tên của file chứa thông tin thành viên.
*   - uid: Chuỗi định danh duy nhất (UID) của thành viên cần xóa.
* Output:
*   - Nếu thành viên được xóa thành công, thông báo và cập nhật cây nhị phân tìm kiếm.
*   - Nếu không tìm thấy thành viên, thông báo không tìm thấy.
*/
void deleteMember(const char* filename, const char* uid) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Cannot open File!\n");
        return;
    }

    // Tạo file tạm để lưu dữ liệu mới sau khi xóa
    const char* tempFileName = "tempFile.csv";
    FILE* tempFile = fopen(tempFileName, "w");
    if (tempFile == NULL) {
        printf("Cannot create temporary file.\n");
        fclose(file);  // Đóng file gốc trước khi thoát
        return;
    }

    char line[256]; // Để đọc từng dòng trong file
    int found = 0;   // Biến để kiểm tra xem từ khóa đã được tìm thấy chưa

    // Tìm uid
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, uid) == NULL) {
            fputs(line, tempFile);
        }
        else {
            found = 1;
        }
    }

    // Đóng file gốc và file tạm
    fclose(tempFile);
    fclose(file);

    // Sao chép dữ liệu từ file tạm vào file gốc
    file = fopen(filename, "w");
    tempFile = fopen(tempFileName, "r");
    if (file == NULL || tempFile == NULL) {
        printf("Error when copying data.\n");
        return;
    }

    // Sao chép từng ký tự từ file tạm sang file gốc
    int ch;
    while ((ch = fgetc(tempFile)) != EOF) {
        fputc(ch, file);
    }

    // Đóng cả hai file
    fclose(file);
    fclose(tempFile);

    // Xóa file tạm
    remove(tempFileName);

    if (found) {
        printf("Removed member with UID %s.\n", uid);
    }
    else {
        printf("No members found with UID %s.\n", uid);
    }
}

/*
* Function: editMember
* Description: Chỉnh sửa thông tin của thành viên trong tệp CSV dựa trên UID và cập nhật trong cây tìm kiếm nhị phân.
* Input:
*   - filename: Tên của tệp CSV chứa thông tin thành viên.
*   - updatedMember: Thông tin mới của thành viên cần cập nhật.
*   - uid: UID của thành viên cần chỉnh sửa.
* Output:
*   - Dữ liệu trong tệp CSV và cây tìm kiếm nhị phân sẽ được cập nhật nếu thành viên được tìm thấy và chỉnh sửa.
*   - Nếu không tìm thấy thành viên, hiển thị thông báo tương ứng.
*/
void editMember(const char* filename, Member updatedMember, const char* uid) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Cannot open File!\n");
        printf("Fail\n");
        return;
    }

    const char* tempFileName = "temFile.csv";
    FILE* tempFile = fopen(tempFileName, "w");
    if (tempFile == NULL) {
        printf("Cannot create temporary file.\n");
        fclose(file);
        return;
    }

    char line[256];
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, uid) == NULL) {
            fputs(line, tempFile);
        }
        else {
            fprintf(tempFile, "%s,%s,%s,%s", updatedMember.uid, updatedMember.roomNumber, updatedMember.name, updatedMember.licensePlate);
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    tempFile = fopen(tempFileName, "r");
    file = fopen(filename, "w");
    if (file == NULL || tempFile == NULL) {
        printf("Error when copying data.\n");
        return;
    }

    int ch;
    while ((ch = fgetc(tempFile)) != EOF) {
        fputc(ch, file);
    }

    fclose(file);
    fclose(tempFile);

    remove(tempFileName);

    edit_member_info(root, uid, updatedMember);

    if (found) {
        printf("Update member with UID %s.\n", uid);
    }
    else {
        printf("No Update member with UID %s.\n", uid);
    }
}


