#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "D:\Desktop\Embedded Interview\Home Work\HomeWork\C\Apartment Resident Management\Header\resident_management.h"


/*
* Function: Thêm thành viên vào cuối file CSV
* Description: Node trong linked list chứa thông tin Member.
* Input:
*   Dữ liệu Member
* Output:
*   Node chứa thông tin Member
*/
MemberNode* createMemberNode(Member member) {
    MemberNode* newNode = (MemberNode*)malloc(sizeof(MemberNode));
    newNode->data = member;
    newNode->next = NULL;
    return newNode;
}

/*
* Function: Thêm thành viên vào cuối file CSV
* Description: Ghi thông tin mới của thành viên vào cuối file CSV
* Input:
*   Member mới.
* Output:
*   File CSV cập nhật
*/
void addMember(const char* filename, Member member) {
    
    FILE* file = fopen(filename, "a");
    
    if(file == NULL) {
        return;
    }

    if(ftell(file) != 0) {
        fprintf(file, "\n");
    }

    fprintf(file, "%s,%s,%s,%s", member.uid, member.roomNumber, member.name, member.licensePlate);

    fclose(file);
}

/*
* Function: Hàm xóa thông tin của thành viên dựa trên UID từ file CSV
* Description: Cập nhật thông tin của thành viên dựa trên UID trong file CSV.
* Input:
*   Member cập nhật và UID.
* Output:
*   File CSV cập nhật
*/
// void deleteMember(const char* filename, const char* uid) {

//     // Mở file để đọc    
//     FILE* file = fopen(filename, "a");

//     if(file == NULL) {
//         printf("Cannot open file %s for reading.\n", filename);
//         return;
//     }

//     while(fgets(&line, sizeof(line), file) != -1) {
//         if(strstr(line, uid) != NULL) {
//             found = 1;
//             continue;
//         }
//         fputs(line, tempFile);
//     }

    // // Tạo tên file tạm để lưu dữ liệu mới sau khi xóa
    // const char *tempFilename = "tempFilename.csv";

    // //Copy filename vào tempFilename
    // strcpy(tempFilename, filename);

    // FILE* tempFile = fopen(tempFilename, "w");

    // if (tempFile == NULL) {
    //     printf("Cannot create temporary file.\n");
    //     fclose(tempFile);
    //     return;
    // }

    // char* line = NULL;   // Dùng để đọc từng dòng trong file
    // //size_t len = 0;      // Độ dài của dòng được đọc

    // int found = 0;   // Biến để kiểm tra xem UID đã được tìm thấy chưa

    // while(fgets(&line, sizeof(line), file) != -1) {
    //     if(strstr(line, uid) != NULL) {
    //         found = 1;
    //         continue;
    //     }
    //     fputs(line, tempFile);
    // }

    // // Giải phóng bộ nhớ của line
    // free(line);

    // // Đóng cả hai file
    // fclose(file);
    // fclose(tempFile);

    // // Sao chép dữ liệu từ file tạm vào file gốc
    // // FILE *source = fopen(tempFile, "r");
    // // FILE *copy = fopen(filename, "w");
    // if (tempFile == NULL || file == NULL) {
    //     printf("Error when copying data.\n");
    //     free(tempFile);  // Giải phóng bộ nhớ nếu có lỗi
    //     return;
    // }

    // // Sao chép từng ký tự từ file tạm sang file gốc
    // int ch;
    // while ((ch = fgetc(file)) != EOF) {
    //     fputc(ch, tempFile);
    // }

    // // Đóng cả hai file sao chép
    // fclose(file);
    // fclose(tempFile);

    // // Xóa file tạm 
    // remove(tempFilename);

    // if (found) {
    //     printf("Removed member with UID %s.\n", uid);
    // } else {
    //     printf("No members found with UID %s.\n", uid);
    // }
} 

/*
* Function: Chỉnh Sửa Thông Tin Thành Viên (Edit Member)
* Description: Cập nhật thông tin của thành viên dựa trên UID trong file CSV.
* Input:
*   Member cập nhật và UID.
* Output:
*   File CSV cập nhật
*/
// void editMember(const char* filename, Member updatedMember, const char* uid) {

//     // Mở file để đọc
//     FILE* file = fopen(filename, "r");
//     if(file == NULL) {
//         printf("Cannot open file %s for reading.\n", filename);
//         return;
//     }

//     // Tạo tên file tạm để lưu dữ liệu mới sau khi xóa
//     const char *tempFilename = "tempFilename.csv";
//     FILE* tempFile = fopen(tempFilename, "w");
//     if (tempFile == NULL) {
//         printf("Error while allocating memory for temporary file name.\n");
//         fclose(file);
//         return;
//     }

//     //Copy filename vào tempFilename
//     strcpy(tempFile, filename);

//     FILE* tempFile = fopen(tempFile, "w");
//     if(tempFile == NULL) {
//         printf("Cannot create temporary file.\n");
//         free(tempFile);  // Giải phóng bộ nhớ nếu có lỗi
//         fclose(file);
//         return;
//     }

//     char* line = NULL;   // Dùng để đọc từng dòng trong file
//     //size_t len = 0;      // Độ dài của dòng được đọc

//     int found = 0;   // Biến để kiểm tra xem UID đã được tìm thấy chưa

//     while(fgets(&line, sizeof(line), file) != -1) {
//         if(strstr(line, uid) != NULL) {
//             found = 1;
//             fprintf(tempFile, "%s,%s,%s,%s", updatedMember.uid, updatedMember.roomNumber, updatedMember.name, updatedMember.licensePlate);
//             continue;
//         }
//         fputs(line, tempFile);
//     }

//     // Giải phóng bộ nhớ của line
//     free(line);

//     // Đóng cả hai file
//     fclose(file);
//     fclose(tempFile);

//     // Sao chép dữ liệu từ file tạm vào file gốc
//     FILE *source = fopen(tempFile, "r");
//     FILE *copy = fopen(filename, "w");
//     if (source == NULL || copy == NULL) {
//         printf("Error when copying data.\n");
//         free(tempFile);  // Giải phóng bộ nhớ nếu có lỗi
//         return;
//     }

//     // Sao chép từng ký tự từ file tạm sang file gốc
//     int ch;
//     while ((ch = fgetc(source)) != EOF) {
//         fputc(ch, copy);
//     }

//     // Đóng cả hai file sao chép
//     fclose(source);
//     fclose(copy);

//     // Xóa file tạm 
//     remove(tempFilename);

//     if (found) {
//         printf("Updated member with UID %s.\n", uid);
//     } else {
//         printf("No members found with UID %s.\n", uid);
//     }
// }

// Hàm tìm kiếm thông tin thành viên dựa trên UID hoặc biển số xe
int searchByUID(const Member* member, const char* uid);

int searchByLicensePlate(const Member* member, const char* licensePlate);

Member searchMember(const char* filename, const char* searchValue, int (*searchFunc)(const Member*, const char*));
