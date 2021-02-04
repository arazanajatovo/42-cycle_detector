/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cycle_detector.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/26 15:13:43 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/26 16:20:02 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "list.h"

int		check_list(const t_list *begin, t_list *check, int size)
{
	if (size == 0)
		return (0);
	if (begin == check)
		return (1);
	if (begin->next)
		return (check_list(begin->next, check, size - 1));
	return (0);
}

int		cycle_detector(const t_list *list)
{
	int		size = 0;
	const t_list	**begin;
	t_list	*check;

	begin = &list;
	check = (t_list*)list;
	while (check)
	{
		if (check_list(*begin, check, size))
			return (1);
		check = check->next;
		size++;
	}
	return (0);
}
