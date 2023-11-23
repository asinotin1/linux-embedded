#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>


int main()
{
    struct stat filestat;
    
    if (stat("test.txt", &filestat) != 0) 
    {
        printf("loi khong lay duoc tep tin .\n");
        return 1;
    }
    printf("File type: ");
    if (S_ISREG(filestat.st_mode)) {
        printf("Loại file: Regular file\n");
    } else if (S_ISDIR(filestat.st_mode)) {
        printf("Loai file:Directory file \n");
    } else {
        printf("Loai file: Không tim duoc\n");
    }
    printf("name file :test.txt\n" );
    printf("size of file: %ld bytes\n", filestat.st_size);
    printf("thoi gian chinh sua lan cuoi : %s", ctime(&filestat.st_mtime));
    
    return 0;
}