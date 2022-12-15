#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 4
#endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <string.h>


typedef struct node
{
    char *content;
    char *reference;
    struct node *next;
} node;
char    *get_next_line(int fd);
void    ft_add_back(node **head,char *buffer);
size_t	ft_count(node *head);
char *ft_sanitize(node **head);
char    *get_rest(node **head);
void	*ft_calloc(size_t count, size_t size);
char *  ft_strchr(const char *s, int c);

#endif