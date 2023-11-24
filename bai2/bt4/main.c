#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd, wr;
    char buf[20] = "hi Luan\n";
    fd = open("test.txt",  O_APPEND | O_RDWR, 0666);
    if (fd == -1) {
        printf("Khong mo duoc  test.txt\n");
    }
    lseek(fd, 0, SEEK_SET);
    wr = write(fd, buf, strlen(buf));
    if (wr == -1)
    {
        printf("kkhong ghi duoc thong tin vao test.txt \n");
    }
    close(fd);
    return 0;
}
