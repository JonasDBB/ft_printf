/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbennink <jbennink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 17:26:59 by jbennink       #+#    #+#                */
/*   Updated: 2019/11/01 17:29:20 by jbennink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	temp = NULL;
	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst);
		(*lst) = (*lst)->next;
		ft_lstdelone(temp, del);
	}
}
