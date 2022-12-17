#include "get_next_line.h"


int main(void)
{
    int fd;
    //size_t rd;
    // if(ac > 1)
    fd = open("file1.txt",O_RDONLY);
    char *str;
    while (true)
    {
        str = get_next_line(fd);
        if (!str)
            break;
        printf("%s",str);
    }
    // str = malloc((BUFFER_SIZE + 1) * sizeof(char));
    // rd = read(fd,str,BUFFER_SIZE);
    // printf("num of read is : %d\n",(int)rd);
    close(fd);
    return 0;
}
