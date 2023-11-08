/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-bae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 07:47:12 by rvan-bae          #+#    #+#             */
/*   Updated: 2023/11/08 18:34:46 by rvan-bae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_h.h"
#include "ft_filehandeling.h"
#include "ft_filereader.h"
#include "ft_valid.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	check_map_valid(char *filename, board_settings *settings)
{
	char	*file;

	file = ft_return_file(filename);
	if (!file)
	{
		free(file);
		return (-1);
	}
	if (!check_first_line(file, settings))
	{
		free(file);
		return (-1);
	}
	if (!check_printable(settings))
	{	
		free(file);
		return (-1);
	}
	if (!check_all_lines_lenght (file, settings))
	{	
		free(file);
		return (-1);
	}
	free(file);
	return (1);
}

int	get_rows(char *line, int size)
{
	int	rows;
	int	i;

	rows = 0;
	i = 0;
	while (i < (size - 3))
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			rows *= 10;
			rows += line[i++] - 48 ;
		}
		else
			return (-1);
	}
	return (rows);
}

int	check_first_line(char *file, board_settings *settings)
{
	int		index;
	char	*line;
	board_settings	set;

	index = 0;
	line = readline(file, 1);
	while (line[index] != '\0')
		index++;
	if (index >= 4)
	{
		set.rows = get_rows(line, index);
		set.empty = line[index - 3];
		set.obstacle = line[index - 2];
		set.fill = line[index -1];
		set.line_lenght = get_line_lenght(file, 2);
	}
	else
	{
		free(line);
		return (0);
	}
	free(line);
	*settings = set;
	return (1);
}

int	get_line_lenght(char *file, int line_number)
{
	int		line_lenght;
	char	*line;

	line_lenght = 0;
	line = readline(file, line_number);
	while (line[line_lenght] != '\0' )
		line_lenght++;
	free(line);
	return (line_lenght);
}

int	check_all_lines_lenght(char *file, board_settings *settings)
{
	board_settings	setup;
	//int			index_lines;
	int			index_rows;

	index_lines = 0;
	index_rows = 2;
	setup = *settings;
	while (index_rows < (setup.rows + 1))
	{	
		if (get_line_lenght (file, index_rows) != setup.line_lenght)
		{	
			return (-1);
		}
		index_rows++;
	}	
	return (1);
}
