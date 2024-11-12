/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:35:12 by dberreby          #+#    #+#             */
/*   Updated: 2022/12/12 16:52:19 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strchr(char *s, char c);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_line(char *full_line);
char	*reserve(char *full_line);
char	*get_full_line(int fd, char *full_line);
char	*get_next_line(int fd);

#endif