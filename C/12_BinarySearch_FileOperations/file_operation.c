#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char* name;
    int id;
    char* city;
} Student;

// ...

// Hàm xóa dòng dựa trên từ khóa
int Delete(FILE *fp, const char* keyword) {
    if(fp == NULL) {
        return 0;
    }

    // Tạo tên file tạm để lưu dữ liệu mới sau khi xóa
    char tempFilename[] = "tempfile.csv";

    FILE* tempFile = fopen(tempFilename, "w");
    if(tempFile == NULL) {
        printf("Cannot create temporary file.\n");
        return 0;
    }

    char line[256]; // Để đọc từng dòng trong file
    int found = 0;   // Biến để kiểm tra xem từ khóa đã được tìm thấy chưa

    while(fgets(line, sizeof(line), fp)) {
        // Nếu từ khóa không xuất hiện trong dòng, ghi dòng vào file tạm
        if (strstr(line, keyword) == NULL) {
            fputs(line, tempFile);
        } else {
            found = 1;
        }
    }

    // Đóng file gốc và file tạm
    fclose(fp);
    fclose(tempFile);

    // Sao chép dữ liệu từ file tạm vào file gốc
    FILE *source = fopen(tempFilename, "r");
    fp = fopen("MyFile.csv", "w");
    if (source == NULL || fp == NULL) {
        printf("Error when copying data.\n");
        return 0;
    }

    // Sao chép từng ký tự từ file tạm sang file gốc
    int ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, fp);
    }

    // Đóng cả hai file
    fclose(source);
    fclose(fp);

    // Xóa file tạm
    remove(tempFilename);

    if (found) {
        printf("Deleted lines with keyword %s.\n", keyword);
    } else {
        printf("No lines found with keyword %s.\n", keyword);
    }

    return 1;
}

int main() {
    FILE *fp = fopen("MyFile.csv", "a+");

    // ...

    // Gọi hàm xóa dòng dựa trên từ khóa
    Delete(fp, "John");

    // ...

    return 0;
}
