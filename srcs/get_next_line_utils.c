/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:50:56 by cgangaro          #+#    #+#             */
/*   Updated: 2021/09/22 13:26:16 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*ft_strncpy(char *s1, char c)
{
	int		i;
	char	*retour;

	i = 0;
	while (s1[i] != c && s1[i])
		i++;
	retour = malloc(sizeof(char) * (i + 1));
	if (!retour)
		return (NULL);
	i = 0;
	while (s1[i] != c && s1[i])
	{
		retour[i] = s1[i];
		i++;
	}
	retour[i] = '\0';
	return (retour);
}

char	*ft_zero(char *s, int n)
{
	int		i;
	char	*retour;

	i = 0;
	if (s == NULL)
	{
		retour = malloc(sizeof(char) * n);
		if (!retour)
			return (NULL);
		while (i < n)
		{
			retour[i] = '\0';
			i++;
		}
		return (retour);
	}
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}

char	*ft_substr_gnl(char *s1, char c)
{
	int		i;
	int		y;
	char	*retour;

	i = 0;
	y = 0;
	while (s1[i] != c && s1[i])
		i++;
	if (s1[i] == c && s1[i])
		i++;
	retour = malloc(sizeof(char) * (ft_strlen(s1 + i) + 1));
	if (!retour)
		return (NULL);
	while (s1[i])
	{
		retour[y] = s1[i];
		i++;
		y++;
	}
	retour[y] = '\0';
	free(s1);
	return (retour);
}
