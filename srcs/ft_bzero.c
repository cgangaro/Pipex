/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:57:26 by cgangaro          #+#    #+#             */
/*   Updated: 2021/09/22 11:51:13 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	ft_bzero(char *s, size_t n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		s[i] = 0;
		n--;
		i++;
	}
}