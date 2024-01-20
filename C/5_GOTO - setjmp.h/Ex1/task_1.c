#include <stdio.h>
#include <setjmp.h>
#include <string.h>

#define MAX_ERRORS 100
#define TRY if (setjmp(buf) == 0)
#define CATCH(x) else if (current_error >= 0 && exceptions[current_error].code == (x))

jmp_buf buf;

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

// Hàm thử nghiệm mới ném ra một loại lỗi khác nhau
void test1() {
    THROW(2, "Error test1");
}

void test2() {
    THROW(3, "Error test2");
}

double divide(int a, int b) {
    if (b == 0) {
        THROW(1, "Divide by 0 error");
    }
    return (double) a / b;
}

int main() {
    int a = 10;
    int b = 0;
    double result = 0.0;

    TRY {
        result = divide(a, b);
        printf("Result: %f\n", result);
    } CATCH(1) {
        printf("Error 1: %s\n", exceptions[current_error].message);
    }

    // Thử nghiệm các hàm thử nghiệm mới
    TRY {
        test1();
    } CATCH(2) {
        printf("Error 2: %s\n", exceptions[current_error].message);
    }

    TRY {
        test2();
    } CATCH(3) {
        printf("Error 3: %s\n", exceptions[current_error].message);
    }

    return 0;
}
