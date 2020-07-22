/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 15:33:35 by gpaul             #+#    #+#             */
/*   Updated: 2020/07/22 11:06:59 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int					ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int					check_char(char **map, t_map_param *param)
{
	int y;
	int x;

	y = 1;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] != param->obs || map[y][x] != param->c_pot)
				return (-1);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int					check_size_str(char **map, t_map_param *param)
{
	int		i;
	int		n;

	i = 1;
	n = 1;
	while (i <= param->size_y)
	{
		if (ft_strlen(map[i]) != ft_strlen(map[n]))
			return (-1);
		if (n == param->size_y)
		{
			i++;
			n = 0;
		}
		n++;
	}
	param->len = ft_strlen(map[1]);
	return (0);
}

int					check_map(char **map, t_map_param *param)
{
	int y;

	y = 1;
	while (map[y])
		y++;
	printf("CACA0\n");				/////////////////////////
	if (param->size_y != y - 1)
		return (-1);
	printf("CACA1\n");				////////////////////////////////
	if (check_size_str(map, param) != 0)
		return (-1);
	printf("CACA2\n");				/////////////////////////
	if (check_char(map, param) != 0)
		return (-1);
	printf("CACA3\n");				/////////////////////////
	return (0);
}
