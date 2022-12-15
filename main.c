#include "get_next_line.h"


int main(void)
{
     int fd;
    // if(ac > 1)
    fd = open("file1.txt",O_RDONLY);
    char *str;
    // // int i = strlen("98765432109876543210987654321098765432109");
    // printf("%d\n",i);
    while (true)
    {
        str = get_next_line(fd);
        if (!str)
            break;
        printf("%s",str);
    }
    // char *ptr = calloc(60,1);
    // ptr[0] = 'a';
    // ptr[1] = 'b';
    // ptr[2] = 'c';
    // ptr[3] = 'd';

    // printf("length is : %lu\n",strlen(ptr));
    return 0;
}
