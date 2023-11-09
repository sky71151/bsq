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
	
	if (settings->empty < 32 || settings->empty > 126)
		return (0);
	if (settings->obstacle < 32 || settings->obstacle > 126)
		return (0);
	if (settings->fill < 32 || settings->fill > 126)
		return (0);
	if (settings->empty == settings->fill || settings->empty == settings->obstacle
		|| settings->fill == settings->obstacle)
		return (0);
	return (1);
}
