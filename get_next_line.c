/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserghin <mserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 04:03:03 by mserghin          #+#    #+#             */
/*   Updated: 2022/12/15 04:03:03 by mserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_rest_helper(t_line *h, int total_length)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc((total_length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (h != NULL)
	{
		while (*((h)->content) != '\0')
		{
			*(str + i) = *((h)->content);
			((h)->content)++;
			i++;
		}
		(h) = (h)->next;
	}
	if (!i)
	{
		free(str);
		return (NULL);
	}
	*(str + i) = '\0';
	return (str);
}

char	*get_rest(t_line **head)
{
	int		total_length;
	char	*str;
	int		i;
	t_line	*temp;

	total_length = 0;
	temp = *head;
	i = 0;
	if (!(*head))
		return (NULL);
	if (ft_count(temp) > 0)
		return (ft_sanitize(head));
	while (temp != NULL)
	{
		while (temp->content[i])
			i++;
		total_length += i;
		temp = temp->next;
		i = 0;
	}
	str = get_rest_helper(*head, total_length);
	if (!str)
		return (NULL);
	return (str);
}

void	free_list(t_line **head)
{
	t_line	*temp;
	t_line	*next;

	if (!head || !(*head))
		return ;
	temp = *head;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp->reference);
		temp->content = NULL;
		temp->reference = NULL;
		free(temp);
		temp = next;
	}
	*head = NULL;
}

static	char	*readen(char *buffer, int nb_read, t_line **head, int fd)
{
	char		*res;

	res = NULL;
	while (true)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if ((int)nb_read > 0)
		{
			buffer[nb_read] = '\0';
			ft_add_back(head, buffer,nb_read);
			res = ft_sanitize(head);
			if (res != NULL)
				return (free(buffer), res);
		}
		else if ((int)nb_read == 0)
		{
			res = get_rest(head);
			free(buffer);
			if (!res)
				free_list(head);
			return (res);
		}
		else
			return (free_list(head), free(buffer), NULL);
	}
}
char	*get_next_line(int fd)
{
	char		*buffer;
	ssize_t		nb_read;
	static t_line	*head;

	nb_read = 0;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (free(buffer), free_list(&head), NULL);
	return (readen(buffer, nb_read, &head, fd));
}
