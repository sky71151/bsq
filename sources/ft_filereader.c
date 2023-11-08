/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filereader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:30:43 by rperez-t          #+#    #+#             */
/*   Updated: 2023/11/08 18:37:48 by rvan-bae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
}

int	get_line_size(char *file, int size, int line_number)
{
	int		elements;
	int		i;
	int		skipped;
	char	c;

	i = 0;
	skipped = 0;
	elements = 0;
	while (skipped < line_number)
	{
		while (file[i] != '\n')
			i++;
		skipped++;
	}
	if (0 < line_number)
		i++;
	while (i < size)
	{
		c = file[i];
		i++;
		elements++;
		if (c == '\n')
			break ;
	}
	return (elements);
}
