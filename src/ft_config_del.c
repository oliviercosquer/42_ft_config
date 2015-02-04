/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 02:52:47 by anonymous         #+#    #+#             */
/*   Updated: 2015/02/04 22:49:13 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_config.h>

static	void	ft_config_del_data(t_data *list)
{
	t_data	*tmp;

	while (list)
	{
		tmp = list;
		ft_strdel(&tmp->data_name);
		ft_strdel(&tmp->data);
		list = list->next;
		free(tmp);
		tmp = NULL;
	}
}

static	void	ft_config_del_section(t_section *list)
{
	t_section	*tmp;

	while (list)
	{
		ft_config_del_data(list->data);
		tmp = list;
		list = list->next;
		ft_strdel(&tmp->section_name);
		free(tmp);
		tmp = NULL;
	}
}

void			ft_config_del_config(t_config **config)
{
	t_config	*tmp;

	tmp = *config;
	ft_config_del_section(tmp->sections);
	ft_strdel(&tmp->filename);
	free(tmp);
	*config = NULL;
}