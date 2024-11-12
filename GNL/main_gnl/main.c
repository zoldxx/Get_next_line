/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:09:02 by dberreby          #+#    #+#             */
/*   Updated: 2022/12/13 17:13:16 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		a;
	char	*b;

	a = 0;
	a = open("test.txt", O_RDONLY);
	b = get_next_line(a);
	printf("%s", b);
	free(b);
	b = get_next_line(a);
	printf("%s", b);
	free(b);
	b = get_next_line(a);
	printf("%s", b);
	free(b);
	close(a);
	return (0);
}
