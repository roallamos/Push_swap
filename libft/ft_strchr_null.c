/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:47:13 by rodralva          #+#    #+#             */
/*   Updated: 2024/02/19 18:47:52 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*t;

	i = 0;
	t = (char *) s;
	if (!s)
		return (NULL);
	while (t[i])
	{
		if (t[i] == (char) c)
			return (&t[i]);
		i++;
	}
	if (!(char) c)
		return (&t[i]);
	return (0);
}
