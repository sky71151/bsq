/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filereader.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:07:19 by rperez-t          #+#    #+#             */
/*   Updated: 2023/11/08 09:20:59 by rperez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILEREADER_H
# define FT_FILEREADER_H
#include <stdlib.h>

char	*copy_line(char *file, char *p, int index);
char	*readline(char *file, int linenumber);
int	get_line_size(char *file, int size, int line_number);

#endif
