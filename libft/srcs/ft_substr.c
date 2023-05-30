/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:05:06 by adi-nata          #+#    #+#             */
/*   Updated: 2023/05/29 19:00:58 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	i;
	size_t	n;

	i = 0;
	n = ft_strlen(s);
	d = ft_calloc(sizeof(char), (len + 1));
	if (!d)
		return (NULL);
	while (i < len && i + start < n)
	{
		d[i] = s[start + i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
