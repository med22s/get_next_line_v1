#include "get_next_line.h"

char	*ft_strcpy(char *dst, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void   ft_add_back(node **head,char *buffer)
{
    node *line;
    node *temp;
	if (!buffer)
		return ;
    line = malloc(sizeof(node));
    if (!line)
        return ;
    line->content = ft_calloc(strlen(buffer) + 1,sizeof(char));
	if (!line->content)
		return ;
	line->content = ft_strcpy(line->content,buffer);
	line->reference = line->content;
    line->next = NULL;
    if (*head)
    {
        temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = line;
    }
    else
        *head = line;
}

// [...] [..\n...][.....][....][]

char *  ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return (char*)s;
        s++;
    }
    if (*s == (char)c)
        return (char*)s;
    else
        return (NULL);
}

size_t	ft_count(node *head)
{
	size_t counter;
	//static size_t tmp;
	// int	no_nl;
	size_t i;

	counter = 1;
	// no_nl = 0;
	while (head != NULL)
	{
		// if (ft_strchr(head->content,'\n'))
		// 	no_nl += 1;
		i = 0;
		while (*((head->content) + i) != '\0')
		{
			if (*((head->content) + i) == '\n')
				return (counter);
			counter++;
			i++;
		}
		head = head->next;
	}
	return (0);
}

char *ft_sanitize(node **head)
{
	size_t count;
	char *line;
	node *n;
	int i;
	node *temp;

	n = *head;
	count = ft_count(n);
	i = 0;
	if (!count)
		return (NULL);
	line = ft_calloc(count + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (n != NULL)
	{
		while (*(n->content))
		{
			if (*(n->content) == '\n')
			{
				*(line + (i++)) = '\n';
				*(line + i) = '\0';
				(n->content)++;
				*head = n;
				return (line);
			}
			else
				*(line + (i++)) = *(n->content);
			(n->content)++;
		}
		temp = n->next;
		free(n->reference);
		free(n);
		n = temp;
	}
	return (NULL);
}



























// static int	get_number_substrings(char const *s, char c)
// {
// 	int	counter;
// 	int	i;

// 	counter = 0;
// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] != c)
// 		{
// 			counter++;
// 			while (s[i] && s[i] != c)
// 				i++;
// 		}
// 		else
// 			i++;
// 	}
// 	return (counter);
// }

// static char	**free_tab(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	while (tab[i])
// 	{
// 		free(tab[i]);
// 		i++;
// 	}
// 	free(tab);
// 	return (NULL);
// }

// static int	get_len(char const *str, char c, size_t *i)
// {
// 	int	len;

// 	len = 0;
// 	while (str[*i] && str[*i] != c)
// 	{
// 		len++;
// 		(*i)++;
// 	}
// 	return (len);
// }

// static char	**split(char const *s, char c, char **sub_strings)
// {
// 	size_t	i;
// 	size_t	start;
// 	int		len;
// 	int		index;

// 	i = 0;
// 	index = 0;
// 	while (s[i])
// 	{
// 		while (s[i] && s[i] == c)
// 			i++;
// 		start = i;
// 		len = get_len(s, c, &i);
// 		if (i > start)
// 		{
// 			sub_strings[index] = ft_substr ((s + start), 0, len);
// 			if (!sub_strings[index])
// 				return (free_tab (sub_strings));
// 			index++;
// 		}
// 		len = 0;
// 	}
// 	sub_strings[index] = 0;
// 	return (sub_strings);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**sub_strings;
// 	if (!s)
// 		return (NULL);
// 	sub_strings = (char **)
// 		malloc ((get_number_substrings (s, c) + 1) * sizeof (char *));
// 	if (!sub_strings)
// 		return (NULL);
// 	return (split(s, c, sub_strings));
// }

