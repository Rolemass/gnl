/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:53:28 by mlinhard          #+#    #+#             */
/*   Updated: 2017/06/08 18:58:19 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>


int main(int argc, char const **argv)
{
	char *line;
	int fd;
	int fd2;
	char	*buf;
	int ret;
	int i;

	i = 0;
	fd = 0;
	fd2 = 0;
	line = NULL;
	if (!(buf = (char*)malloc(sizeof(char) * BUF_SIZE + 1)))
		return (-1);
	if (argc == 1)
	{
		if ((fd = open("../truc", O_RDONLY)) >= 0 && (fd2 = open("../truc2", O_RDONLY)) >= 0)
		{
			while ((ret = get_next_line(fd, &line)) > 0)
			{
				printf("line truc : %s\n", line);
				// if (line)
					// free(line);
				if ((ret = get_next_line(fd2, &line)) > 0)
				{
					printf("ret2: %d\n", ret);
					printf("line truc 2: %s\n", line);
				}
				// printf("line:\n..........\n%s\n............\n", line);
				// printf("ret: %d\n", ret);
				// if (line)
					// free(line);
				i++;
				if (i > 50)
					break;
				// printf("%d\n", i);
			}
			while ((ret = get_next_line(fd2, &line)) > 0)
			{
				// ret = get_next_line(fd2, &line);
				printf("ret :%d\n", ret);
				printf("line truc 2: %s\n", line);
				// ft_memdel((void**)&line);
			}
			if (ret == -1 && argv[0])
				exit(1);
			// // printf("weeeeesh\n");
			ret = get_next_line(fd2, &line);
			printf("ret EOF2:%d\n", ret);
			// ft_memdel((void**)&line);
			close(fd);
		}
	}
	printf("fd = %d fd2 = %d\n", fd, fd2);
	ft_memdel((void**)&buf);
	return (0);
}


// int		main(int argc, char **argv)
// {
// 	char	*line;
// 	int		ret;
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	int		fd4;
// 	int		fd5;

// 	ret = 0; fd1 = 0; fd2 = 0; fd3= 0; fd4 = 0; fd5 = 0;

// 	if (argc && argv)
// 		;

// 	// READ FROM STDIN
// 	//while ((ret = get_next_line(fd1, &line)) == 1)
// 	//	printf("STDIN i, %d:%s\n", ret, line), ft_strdel(&line);

// 	printf("\n# define BUF_SIZE %d\n", BUF_SIZE);

// 	// TEST MULTI FD
// 	printf("\n===== TESt MULTI FD, OUVERT ET LU DE MANIERE ALTERNE =====\n");
// 	printf("* (null) = termine & maillon free\n");
// 	printf("si MAP = 1, on constate leffet du strtoupper ici\n\n");

// 	fd1 = open("./files/1lignes", O_RDONLY);
// 	ret = get_next_line(fd1, &line);
// 	printf("1lignes?, 1/1, %d: %s\n", ret, line); ft_strdel(&line);

// 	fd2 = open("./files/3lignes", O_RDONLY);
// 	printf("open and ....\n");
// 	ret = get_next_line(fd2, &line);
// 	printf("FAIL\n");
// 	printf("3lignes, 1/3, %d: %s\n", ret, line); ft_strdel(&line);

// 	fd3 = open("./files/5lignes", O_RDONLY);
// 	ret = get_next_line(fd3, &line);
// 	printf("5lignes, 1/5, %d: %s\n", ret, line); ft_strdel(&line);
// 	ret = get_next_line(fd3, &line);
// 	printf("5lignes, 2/5, %d: %s\n", ret, line); ft_strdel(&line);

// 	ret = get_next_line(fd2, &line);
// 	printf("3lignes, 2/3, %d: %s\n", ret, line); ft_strdel(&line);

// 	ret = get_next_line(fd3, &line);
// 	printf("5lignes, 3/5, %d: %s\n", ret, line); ft_strdel(&line);

// 	// CETTE LIGNE VA FREE LES DONNEE DE CE FD CAR IL EST TERMINé
// 	ret = get_next_line(fd1, &line);
// 	printf("1lignes, 2/1, %d: %s\n", ret, line); ft_strdel(&line);

// 	ret = get_next_line(fd3, &line);
// 	printf("5lignes, 4/5, %d: %s\n", ret, line); ft_strdel(&line);

// 	ret = get_next_line(fd2, &line);
// 	printf("3lignes, 3/3, %d: %s\n", ret, line); ft_strdel(&line);

// 	ret = get_next_line(fd2, &line);
// 	printf("3lignes, 4/3, %d: %s\n", ret, line); ft_strdel(&line);

// 	ret = get_next_line(fd3, &line);
// 	printf("5lignes, 5/5, %d: %s\n", ret, line); ft_strdel(&line);

// 	// CETTE LIGNE VA FORCER UN FREE AUTO ET TOTAL CAR
// 	// C'EST LE DERNIER FD QUI ETAIT OUVERT
// 	ret = get_next_line(fd3, &line);
// 	printf("5lignes, 6/5, %d: %s\n", ret, line); ft_strdel(&line);

// 	// LE PROGRAMME A FREE TOUS DE MANIERE AUTO CAR
// 	// AUCUN FD N'ETAIS OUVERT
// 	// PUIS ON ROUVRE UN NOUVEAU FD
// 	printf("\n===== TESt FD APRES FREE TOTAL AUTO, LECTURE SUR WHILE =====\n");
// 	printf("open('./test_maps/10-2.fdf')\n");
// 	printf("si MAP = 1, on constate leffet du trim en fin de ligne\n\n");
// 	fd5 = open("./test_maps/10-2.fdf", O_RDONLY);
// 	printf("FD: %d\n", fd5);
// 	while ((ret = get_next_line(fd5, &line)) == 1)
// 		printf("10-2.fdf i, %d:%s\n", ret, line), ft_strdel(&line);

// 	printf("\n===== TESt FD -99 et LINE = VOID =====\n");
// 	printf("open('./test_maps/10-2.fdf')\n");
// 	printf("si MAP = 1, on constate leffet du trim en fin de ligne\n\n");
// 	ret = get_next_line(-99, (void*)0);
// 	printf("return = %d\n", ret);

// 	// LE PROGRAMME A FREE TOUS DE MANIERE AUTO CAR
// 	// AUCUN FD N'ETAIS OUVERT
// 	// PUIS ON ROUVRE UN NOUVEAU FD
// 	printf("\n===== CAS DERREUR REPORTER PAR 42FC =====\n");
// 	printf("open('./42fc/gnl1_2.txt')\n");
// 	fd5 = open("./42fc/gnl1_2.txt", O_RDONLY);
// 	printf("FD: %d\n", fd5);
// 	while ((ret = get_next_line(fd5, &line)) == 1)
// 		printf("test i, %d:%s\n", ret, line), ft_strdel(&line);

// 	printf("\n===== TESt SUR FICHIER TEST =====\n");
// 	fd5 = open("./files/test", O_RDONLY);
// 	printf("FD: %d\n", fd5);
// 	while ((ret = get_next_line(fd5, &line)) == 1)
// 		printf("test i, %d:%s\n", fd5, line), ft_strdel(&line);

// /*
// 	// OUVERTURE DUN GROS FICHIER
// 	printf("\n===== TESt GROS FICHIER =====\n");
// 	printf("open('./files/1mo')\n");
// 	printf("fichier texte de 1 mo\n\n");
// 	fd5 = open("./files/1mo", O_RDONLY);
// 	while ((ret = get_next_line(fd5, &line)) == 1)
// 		printf("2mo i, %d:%s\n", ret, line), ft_strdel(&line);
// */
// 	// ON DEMANDE UN FREE TOTAL PLUSIEURS FOIS, PAS D'ERREUR
// 	get_next_line(-10, &line);
// 	get_next_line(-10, &line);

// 	return (0);
// }
