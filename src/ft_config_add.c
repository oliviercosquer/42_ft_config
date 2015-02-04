/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 22:20:13 by olivier           #+#    #+#             */
/*   Updated: 2014/11/12 23:09:25 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_config.h>

void			ft_config_add_int(t_config *config, char *path, int nbr)
{
	char	*section_name;
	char	*data_name;
	char	*data;

	(void)config;
	(void)path;
	(void)nbr;
	(void)section_name;
	(void)data_name;
	(void)data;
}

void			ft_config_add_string(t_config *config, char *path, char *str)
{
	(void)config;
	(void)path;
	(void)str;
}