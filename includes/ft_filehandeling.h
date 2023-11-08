/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filehandeling.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-bae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:03:35 by rvan-bae          #+#    #+#             */
/*   Updated: 2023/11/08 09:27:48 by rperez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILEHANDELING_H
# define FT_FILEHANDELING_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

int		ft_attempt(char *filename);
int		file_size(char *filename);
char	*ft_return_file(char *filename);
//char	*readline(char *filename, int linenumber);

#endif
