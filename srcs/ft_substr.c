/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:45:05 by cgangaro          #+#    #+#             */
/*   Updated: 2021/09/22 12:00:36 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*ft_emptystring(void)
{
	char	*retour;

	retour = malloc(sizeof(char) * 1);
	if (!retour)
		return (NULL);
	retour[0] = '\0';
	return (retour);
}

char	*ft_annexe(void)
{
	char	*retour;

	retour = malloc(sizeof(char));
	if (!retour)
		return (NULL);
	retour[0] = 0;
	return (retour);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	unsigned int		y;
	char				*retour;

	if (!s)
		return (0);
	y = 0;
	i = 0;
	if (len == 0)
		return (ft_annexe());
	if (start >= ft_strlen((char *)s))
		return (ft_emptystring());
	while (i < start)
		i++;
	retour = malloc(sizeof(char) * (len + 1));
	if (!retour)
		return (NULL);
	while (y < len)
	{
		retour[y] = s[i];
		i++;
		y++;
	}
	retour[y] = '\0';
	return (retour);
}
