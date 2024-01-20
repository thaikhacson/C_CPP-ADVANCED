#include <stdio.h>
#include <string.h>

typedef struct Student {
    char* name;
    int id;
    char* city;
} Student;

// Hàm kiểm tra xem một sinh viên có tồn tại trong file hay không
int IsStudentExist(FILE *fp, Student student) {
    rewind(fp); // Di chuyển con trỏ đọc/ghi về đầu file

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Tách thông tin từ dòng đọc được
        int existingID;
        char existingName[50], existingCity[50];
        sscanf(buffer, "%d,%49[^,],%49[^,\n]", &existingID, existingName, existingCity);

        // So sánh thông tin sinh viên
        if (existingID == student.id && strcmp(existingName, student.name) == 0 && strcmp(existingCity, student.city) == 0) {
            return 1; // Sinh viên đã tồn tại
        }
    }

    return 0; // Sinh viên không tồn tại
}

// Hàm thêm sinh viên vào file nếu sinh viên chưa tồn tại
int AddStudent(FILE *fp, Student student) {
    if(fp == NULL) {
        return 0;
    }

    // Kiểm tra xem sinh viên đã tồn tại hay chưa
    if (IsStudentExist(fp, student)) {
        printf("Student already exists.\n");
        return 0; // Sinh viên đã tồn tại, không thêm vào
    }

    // Không in dòng mới trước dòng đầu tiên
    if (ftell(fp) != 0) {
        fprintf(fp, "\n");
    }

    fprintf(fp, "%d,%s,%s", student.id, student.name, student.city);

    return 1; // Thêm thành công
}

int main() {
    FILE *fp = fopen("MyFile.csv", "a+");

    if(fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // In tiêu đề cho ID, Name và City nếu file rỗng
    if (ftell(fp) == 0) {
        fprintf(fp, "ID,Name,City");
    }

    Student student1;
    student1.name = "John";
    student1.city = "HCM";
    student1.id = 1;

    AddStudent(fp, student1);

    fclose(fp);

    return 0;
}
