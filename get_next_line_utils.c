/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserghin <mserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 04:13:03 by mserghin          #+#    #+#             */
/*   Updated: 2022/12/15 04:13:03 by mserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	ft_add_back(t_line **head, char *buffer, int nb_read)
{
	t_line	*line;
	t_line	*temp;

	if (!buffer)
		return ;
	line = malloc(sizeof(t_line));
	if (!line)
		return ;
	line->content = malloc((nb_read + 1) * sizeof(char));
	if (!line->content)
		return ;
	line->content = ft_strcpy(line->content, buffer);
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

size_t	ft_count(t_line *head)
{
	size_t	counter;
	size_t	i;

	counter = 1;
	if (*(head->content) == '\0')
		head = head->next;
	while (head != NULL)
	{
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

static	char	*line_is(char *line, t_line **head, t_line *n)
{
	t_line	*temp;
	int		i;

	i = 0;
	while (n != NULL)
	{
		while (*(n->content))
		{
			if (*(n->content) == '\n')
			{
				*(line + (i++)) = '\n';
				*(line + i) = '\0';
				(n->content)++;
				return (*head = n, line);
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

char	*ft_sanitize(t_line **head)
{
	size_t	count;
	char	*line;
	t_line	*n;

	n = *head;
	count = ft_count(n);
	if (!count)
		return (NULL);
	line = malloc((count + 1) * sizeof(char));
	if (!line)
		return (NULL);
	return (line_is(line, head, n));
}