/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:05:06 by adi-nata          #+#    #+#             */
/*   Updated: 2022/10/11 17:05:07 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>
#include "libft.h"

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		c = c - 32;
	return (c);
}

/*int main()
{
	char c = 'c';
	
	printf("%c", ft_toupper(c));
}*/
