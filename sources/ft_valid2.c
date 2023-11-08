/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-bae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:28:27 by rvan-bae          #+#    #+#             */
/*   Updated: 2023/11/08 18:30:34 by rvan-bae         ###   ########.fr       */
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

int	check_printable(board_settings *settings)
{
	board_settings	set;

	set = *settings;
	if (set.empty < 32 || set.empty > 126)
		return (-1);
	if (set.obstacle < 32 || set.obstacle > 126)
		return (-1);
	if (set.fill < 32 || set.fill > 126)
		return (-1);
	if (set.empty == set.fill || set.empty == set.obstacle
		|| set.fill == set.obstacle)
		return (-1);
	return (1);
}
