#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// egjewgjhkewghk
char *get_next_line(int fd)
{
    char *res = malloc(4096);
    int i = 0;
    char c;
    int ret_red = 0;

    if(fd < 0 || !res)
        return NULL;
    while((ret_red = read(fd, &c, 1)))
    {
        res[i] = c;
        i++;
        if(c == '\n')
            break;
    }
}