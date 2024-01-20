#ifndef RESIDENT_MANAGEMENT_H
#define RESIDENT_MANAGEMENT_H

#include <stdio.h>
#include <string.h>

// Cấu trúc để lưu trữ thông tin cơ bản của cư dân
typedef struct {
    char uid[20];           // UID của RFID
    char roomNumber[10];    // Số Phòng
    char name[50];           // Tên
    char licensePlate[20];  // Biển Số Xe
} Member;

// Node trong linked list chứa thông tin Member
typedef struct MemberNode {
    Member data;
    struct MemberNode* next;
} MemberNode;

// Hàm tạo một MemberNode mới
MemberNode* createMemberNode(Member member);

// Hàm thêm thành viên vào cuối file CSV
void addMember(const char* filename, Member member);

// Hàm xóa thông tin của thành viên dựa trên UID từ file CSV
void deleteMember(const char* filename, const char* uid);

// Hàm cập nhật thông tin của thành viên dựa trên UID trong file CSV
void editMember(const char* filename, Member updatedMember, const char* uid);

// Hàm tìm kiếm thông tin thành viên dựa trên UID hoặc biển số xe
int searchByUID(const Member* member, const char* uid);

int searchByLicensePlate(const Member* member, const char* licensePlate);

Member searchMember(const char* filename, const char* searchValue, int (*searchFunc)(const Member*, const char*));

#endif // RESIDENT_MANAGEMENT_H
