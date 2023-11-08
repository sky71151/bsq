/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filehandeling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:14:27 by rperez-t          #+#    #+#             */
/*   Updated: 2023/11/08 09:35:54 by rperez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	ft_attempt(char *filename)
{
	int	file;

	file = open(filename, 0);
	close(file);
	if (file == -1)
	{
		write(1, "File error\n", 11);
		return (-1);
	}
	return (1);
}

int	file_size(char *filename)
{
	int		file;
	int		len;
	char	buffer;

	len = 0;
	file = open(filename, 0);
	if (file == -1)
	{
		close(file);
		return (-1);
	}
	while (read(file, &buffer, 1))
		len++;
	close(file);
	return (len);
}

char	*ft_return_file(char *filename)
{
	int		file;
	int		size;
	char	*loading;

	size = file_size(filename);
	if (size == -1)
		return (0);
	loading = malloc(sizeof(char) * (size + 2));
	if (!loading)
		return (0);
	file = open(filename, 0);
	read(file, loading, size);
	loading[size] = '\0';
	close(file);
	return (loading);
}
/*
char	*copy_line(char *file, char *p, int index)
{
	int	i;

	i = 0;
	while (file[index] != '\n')
		p[i++] = file[index++];
	p[i] = '\0';
	return (p);
}

char	*readline(char *file, int linenumber)
{
	int		index;
	int		line_index;
	char	*p;

	index = 0;
	line_index = 0;
	while (line_index < (linenumber - 1))
	{
		while (file[index] != '\n')
			index++;
		index++;
		line_index++;
	}
	line_index = 0;
	while (file[index + line_index] != '\n')
		line_index++;
	p = malloc(sizeof(char) * (line_index + 1));
	p = copy_line(file, p, index);
	return (p);
}*/	
