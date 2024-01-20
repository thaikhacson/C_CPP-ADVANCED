#include <stdio.h>
#include <stdint.h>

void tong (int a, int b) {
    printf("Tong a va b: %d\n", a + b);
}

int main() {
    char *string = "Hello World";
    void *array[] = {tong, string};
    printf("%s\n", (char*)array[1]);
}
