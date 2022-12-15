/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserghin <mserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 04:07:56 by mserghin          #+#    #+#             */
/*   Updated: 2022/12/15 04:07:56 by mserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_line
{
	char		*content;
	char		*reference;
	struct s_line	*next;
}	t_line;
char	*get_next_line(int fd);
void	ft_add_back(t_line **head, char *buffer);
size_t	ft_count(t_line *head);
char	*ft_sanitize(t_line **head);
char	*get_rest(t_line **head);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);

#endif