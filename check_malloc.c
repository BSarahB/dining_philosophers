/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 06:43:05 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/28 06:43:08 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ft_check_malloc_ptr(t_utils *ptr)
{
	if (!ptr)
	{
		ft_error("Error during ptr malloc allocation\n");
		return (1);
	}
	return (0);
}

int	ft_check_malloc_philos(t_philo *philos, t_utils *ptr)
{
	if (!philos)
	{
		ft_error("Error during ptr malloc allocation\n");
		ft_free_struct_t_ptr(&ptr);
		return (1);
	}
	return (0);
}
