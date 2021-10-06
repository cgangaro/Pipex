/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:22:02 by cgangaro          #+#    #+#             */
/*   Updated: 2021/09/22 11:52:11 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*retour;

	retour = malloc(size * count);
	if (!retour)
		return (0);
	ft_bzero(retour, count * size);
	return (retour);
}
