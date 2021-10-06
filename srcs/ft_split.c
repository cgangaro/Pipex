/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:54:51 by cgangaro          #+#    #+#             */
/*   Updated: 2021/09/22 11:53:21 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	ft_cpt_string(char const *s, char c)
{
	int	i;
	int	cpt;

	i = 0;
	if (!s[i])
		return (0);
	if (s[i] == c && s[i])
		cpt = 0;
	else
		cpt = 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] && s[i + 1] != c)
			cpt++;
		i++;
	}
	return (cpt);
}

int	ft_cpt_l(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_string(char const *s, char c)
{
	char	*retour;
	int		i;

	i = 0;
	retour = ft_calloc(ft_cpt_l(s, c) + 1, sizeof(char));
	retour = ft_memcpy(retour, s, ft_cpt_l(s, c));
	return (retour);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		z;
	char	**tab;
	int		nb_string;

	z = 0;
	i = 0;
	if (!s)
		return (0);
	nb_string = ft_cpt_string(s, c);
	tab = malloc(sizeof(char *) * (nb_string + 1));
	if (!tab)
		return (0);
	while (z < nb_string)
	{
		if (ft_cpt_l(s + i, c) > 0)
		{
			tab[z] = ft_string(s + i, c);
			z++;
		}
		i = i + ft_cpt_l(s + i, c) + 1;
	}
	tab[z] = NULL;
	return (tab);
}
