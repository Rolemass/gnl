/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolemass <rolemass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 20:52:39 by rolemass          #+#    #+#             */
/*   Updated: 2017/06/09 16:24:04 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_slist	*ft_init_head_gnl(int fd)
{
	t_slist	*head;

	head = NULL;
	if (!(head = (t_slist*)malloc(sizeof(t_slist))))
		return (NULL);
	head->fd = fd;
	head->next = (t_slist *)NULL;
	if (!(head->str = ft_strnew(0)))
		return (NULL);
	return (head);
}

static int		ft_check_line(char **line, char *buf, t_slist *list)
{
	int		i;
	char	*tmp;
	char	*freex;

	freex = NULL;
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	tmp = ft_strdup(*line);
	ft_memdel((void**)line);
	if (!(freex = ft_strsub(buf, 0, i)))
		return (-1);
	if (!(*line = ft_strjoin(tmp, freex)))
	{
		free(tmp);
		free(freex);
		return (-1);
	}
	free(tmp);
	free(freex);
	if (buf[i] == '\0')
		return (0);
	tmp = ft_strdup(buf + i + 1);
	ft_memdel((void**)&list->str);
	if (!(list->str = ft_strdup(tmp)))
		return (-1);
	free(tmp);
	return (1);
}

static int		ft_gnl_parsing(int fd, char **line, t_slist *list)
{
	int		ret;
	int		done;
	char	*buf;
	int		count;

	done = 0;
	count = 0;
	if (!(buf = ft_strnew(BUF_SIZE + 1)))
		return (-1);
	while (done == 0 && (ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (ret != 0 && (done = ft_check_line(line, buf, list)) == -1)
			return (-1);
		count++;
	}
	free(buf);
	if (ret == 0 && (count > 0 || (list->str && ft_strlen(list->str) > 0)))
	{
		ft_memdel((void**)&list->str);
		return (1);
	}
	if (ret <= 0)
		return (ret);
	return (1);
}

static t_slist	*ft_check_fd(t_slist *list, int fd)
{
	if (list)
	{
		while (list->next && list->fd != fd)
			list = list->next;
		if (list && list->fd == fd)
			return (list);
		if (list->next == NULL)
		{
			if ((list->next = (t_slist*)malloc(sizeof(t_slist))) == NULL)
				return (NULL);
			list = list->next;
			list->next = NULL;
			list->str = NULL;
			list->fd = fd;
		}
	}
	return (list);
}

int				get_next_line(int fd, char **line)
{
	static t_slist	*head = NULL;
	t_slist			*list;
	int				ret;

	if (fd < 0 || !(line) || BUF_SIZE < 1)
		return (-1);
	if (!head && !(head = ft_init_head_gnl(fd)))
		return (-1);
	list = head;
	ret = 0;
	if (!(*line = ft_strnew(0)))
		return (-1);
	if ((list = ft_check_fd(list, fd)) == NULL)
		return (-1);
	if (list->str != NULL && ft_strlen(list->str) > 0)
		if ((ret = ft_check_line(line, list->str, list)) == -1)
			return (-1);
	if (ret == 0)
		if ((ret = ft_gnl_parsing(fd, line, list)) == -1)
			return (-1);
	if (ret == 0)
		ft_memdel((void**)&list->str);
	return (ret);
}
