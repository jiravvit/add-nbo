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

    // 1000(0x3e8) + 500(0x1f4) = 1500(0x5dc)
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num, num, num2, num2, add, add );


    return 0;
}