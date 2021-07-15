#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <netinet/in.h>


int main(int argc, char** argv) {
    uint32_t buf, buf2;
    FILE* fd = NULL;
    FILE* fd2 = NULL;

    // argc check
    if (argc < 2) {
        printf("%s", "[!] ./main file.bin file2.bin\n");
        return 0;
    }

    // file open, check 
    fd = fopen(argv[1], "r");
    fd2 = fopen(argv[2], "r");

    if (fd == NULL || fd2 == NULL) {
        printf("%s", "[!] nooooo... file\n");
        return 0;
    }

    fread(&buf, 1, 4, fd);
    fread(&buf2, 1, 4, fd2);

    uint32_t num = ntohl(buf);
    uint32_t num2 = ntohl(buf2);

    uint32_t add = num + num2;

    // TODO : 입력 포맷 맞추기
    printf("0x%x\n", num);
    printf("0x%x\n", num2);
    printf("0x%x\n", add);

    return 0;
}