/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:15:01 by rodralva          #+#    #+#             */
/*   Updated: 2024/01/22 15:15:01 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *) malloc(sizeof(t_list));
	if (!lst)
		return (0);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
