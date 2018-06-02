/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:20:07 by pdavid            #+#    #+#             */
/*   Updated: 2017/12/05 13:14:09 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *alst, t_list *(*f)(t_list *elem))
{
	t_list *i;

	if (alst)
	{
		i = f(alst);
		i->next = ft_lstmap(alst->next, f);
		return (i);
	}
	return (NULL);
}
