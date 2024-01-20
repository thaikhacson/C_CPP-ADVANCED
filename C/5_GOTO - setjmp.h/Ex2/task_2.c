#include <stdio.h>
#include <setjmp.h>
#include <string.h>

#define MAX_ERRORS 100
#define TRY if (setjmp(buf) == 0)
#define CATCH(x) else if (current_error >= 0 && exceptions[current_error].code == (x))

jmp_buf buf;

typedef enum {
    NO_ERROR, 
    FILE_ERROR, 
    NETWORK_ERROR, 
    CALCULATION_ERROR 
}ErrorCodes;

// Cấu trúc lưu trữ thông tin lỗi
struct Exception {
    int code;
    char message[100];
};

struct Exception exceptions[MAX_ERRORS];
int current_error = -1;

// Hàm THROW cải tiến để nhận thông điệp lỗi và mã lỗi
void THROW(int code, const char *message) {
    if (current_error < MAX_ERRORS - 1) {
        current_error++;
        exceptions[current_error].code = code;
        strcpy(exceptions[current_error].message, message);
        longjmp(buf, 1);
    } else {
        // In ra nếu đạt đến giới hạn số lượng lỗi hoặc làm gì đó ...
        printf("Exceeded maximum number of errors\n");
    }
}

void readFile() {
    printf("Read File..\n");
    THROW(FILE_ERROR, "Error reading file: File does not exist!");
}

void networkOperation() {
    printf("Network Operation..\n");
    THROW(NETWORK_ERROR, "Network connection error: Unable to connect to the server!");
}

void calculateData() {
   printf("Calculate Data..\n");
   THROW(CALCULATION_ERROR, "Calculation error: Invalid input data!");
}

int main() {
    
    TRY {
        readFile();
        networkOperation();
        calculateData();
    } CATCH(FILE_ERROR) {
        printf("Error 1: %s\n", exceptions[current_error].message);
    } CATCH(NETWORK_ERROR) {
        printf("Network Error: %s\n", exceptions[current_error].message);
    } CATCH(CALCULATION_ERROR) {
        printf("Calculation Error: %s\n", exceptions[current_error].message);
    }
    printf("Program completed successfully\n");
}