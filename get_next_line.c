#include "get_next_line.h"
/**
 * hello world.$
 * Goodbye.
*/
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*b;
	size_t			i;

	i = 0;
	b = (unsigned char *)s;
	while (i < n)
	{
		b[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;

	p = (char *)malloc(size * count);
	if (!p)
		return (NULL);
	ft_bzero (p, count * size);
	return (p);
}

char    *get_rest(node *head)
{
    int total_length;
    char *str;
    int i;
    node *temp;

    total_length = 0;
    temp = head;
    i = 0;
    
    if (!head)
        return (NULL);
    while (temp != NULL)
    {
        total_length += strlen(temp->content);
        temp = temp->next;
    }
    str = calloc(total_length + 1,sizeof(char));
    if (!str)
        return (NULL);
    while (head != NULL)
    {
        while (*(head->content) != '\0')
        {
            *(str + i) = *(head->content);
            (head->content)++;
            i++;
        }
        head = head->next;
    }
    if (!i)
        return (NULL);
    *(str + i) = '\0';
    return (str);
}

void	free_list(node **head)
{
	node	*temp;
	node	*next;

	if (!head)
		return ;
	temp = *head;
	while (temp != NULL)
	{
		next = temp->next;
        free(temp->reference);
		free(temp);
		temp = next;
	}
	*head = NULL;
}

char    *get_next_line(int fd)
{
    char *buffer;
    size_t nb_read;
    static node *head;
    char *res;

    buffer = calloc(BUFFER_SIZE + 1,sizeof(char));
    if (!buffer)
        return (NULL);
    if (fd < 0 ||  BUFFER_SIZE < 0)
        return (NULL);
    res = NULL;
    while (true)
    {
        nb_read = read(fd,buffer,BUFFER_SIZE);
        if (nb_read > 0)
        {
            buffer[strlen(buffer)] = '\0';
            ft_add_back(&head,buffer);
            res = ft_sanitize(&head);
            // printf("res  == %s\n", res);
            if (res != NULL)
                return (res);
        }
        else
        {
            res = get_rest(head);
            free(buffer);
            free_list(&head);
            return (res);
        }
    }
    free(buffer);
}
