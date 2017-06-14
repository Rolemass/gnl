/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 23:40:33 by rolemass          #+#    #+#             */
/*   Updated: 2016/12/28 01:07:40 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

# define BUF_SIZE 32

struct	s_slist
{
	char			*str;
	int				fd;
	struct s_slist	*next;
};

typedef struct s_slist	t_slist;

int		get_next_line(int fd, char **line);

#endif
