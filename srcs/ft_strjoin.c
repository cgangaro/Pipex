/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:41:31 by cgangaro          #+#    #+#             */
/*   Updated: 2021/09/22 11:58:32 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*ft_strjoin_2(char *s1, char *s2, int taille)
{
	int		i;
	int		y;
	char	*retour;

	retour = malloc(sizeof(char) * (taille + 1));
	if (!retour)
		return (NULL);
	i = 0;
	y = 0;
	while (s1[i])
	{
		retour[i] = s1[i];
		i++;
	}
	while (s2[y])
	{
		retour[i] = s2[y];
		i++;
		y++;
	}
	retour[i] = '\0';
	return (retour);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*retour;
	int		taille;

	if (!s1 || !s2)
		return (0);
	taille = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	retour = ft_strjoin_2(s1, s2, taille);
	if (retour == NULL)
		return (NULL);
	free (s1);
	return (retour);
}
