#include "get_next_line.h"


int main(void)
{
     int fd;
    // if(ac > 1)
    fd = open("file1.txt",O_RDONLY);
    char *str;
    str = get_next_line(fd);
    while (true)
    {
        printf("%s",str);
        free(str);
        str = get_next_line(fd);
    }
    return 0;
}
