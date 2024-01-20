#include <stdio.h>
#include <stdint.h>

/*
- Vì hệ điều hành 64 bit, nên mỗi lần đọc 1 WORD sẽ là 8 byte, còn 32 bit thì 1 WORD bằng 4 byte
- Kiểu dữ liệu chỉ có thể đặt ở ô nhớ có vị trí chia hết cho chính nó
- Ví dụ kiểu int (4 byte) thì đặt tại địa chỉ chia hết cho 4 là: 4, 8, 12,...
- Còn kiểu char (1 byte) thì đặt ở bất kì ô nhớ nào, thường sẽ đặt liền kề với địa chỉ của biến trước đó
*/

struct test1
{   
    uint64_t arr1[6];       // 8 byte x 6 = 48    --> [48] (48 % 1 == 0)
    uint8_t arr2[11];       // 1 byte x 11 = 11   --> 11 + 48 = 59    --> 59 + 1 = [60] (60 % 4 ==0)
    uint32_t arr3[19];      // 4 byte x 19 = 76   --> 76 + 60 = 136   --> [136] (136 % 2 == 0)
    uint16_t arr4[11];      // 2 byte x 11 = 22   --> 22 + 136 = 158  --> 158 + 2 = [160] (160 % 8 == 0)
};

struct test2
{
    double i;   // 8 byte x 1 = [8]
    char c;     // 1 byte x 1 = 1     --> 1 + 8 = 9   --> 9 + 1 = [10] (10 % 2 == 0)
    short s;    // 2 byte x 1 = [2]   --> 2 + 10 = [12] (12 % 4 == 0)
};

struct test3
{
    int i1;     // 4 byte
    int i2;     // 4 byte + 4 = 8
    char c;     // 1 byte + 8 = 9 --> 9 + 1 = 10
    short s;    // 2 byte + 10 = 12
};

struct test4
{
    long double *p;            //8 byte
    // int i;
    // char c[2];
};


int main() {
    printf("Size of test 1: %d byte\n", sizeof(struct test1));
    printf("Size of test 2: %d byte\n", sizeof(struct test2));
    printf("Size of test 3: %d byte\n", sizeof(struct test3));
    printf("Size of test 4: %d byte\n", sizeof(struct test4));
    printf("Size of test 4: %d byte\n", sizeof(long double));
}
