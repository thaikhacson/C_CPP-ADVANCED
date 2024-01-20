#include <stdio.h>
#include <stdint.h>


union test1
{
    uint64_t arr1[6];       
    uint8_t arr2[11];       
    uint32_t arr3[19];   // 4 byte x 19 = 76 byte   --> 76 (76 % 8 != 0)  --> 76 + 4 = 80 byte (80 % 8 == 0)
    uint16_t arr4[11];      
};

union test2
{
    double i;   
    char c;     
    short s;    
};

union test3
{
    char *ptr;
    int id;
    char name[7];    
};

union test4
{
    char *ptr;
    int id;
    char name[9];    
};

int main() {
    printf("Size of test 1: %d byte\n", sizeof(union test1));
    printf("Size of test 2: %d byte\n", sizeof(union test2));
    printf("Size of test 3: %d byte\n", sizeof(union test3));
    printf("Size of test 4: %d byte\n", sizeof(union test4));
}
