/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 21:23:41 by olivier           #+#    #+#             */
/*   Updated: 2015/02/03 22:56:33 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_config.h>

static	t_section	*ft_config_new_section(char *section_name)
{
	t_section	*section;

	section = NULL;
	section = (t_section *)malloc(sizeof(t_section));
	if (section)
	{
		section->section_name = ft_strdup(section_name);
		section->data = NULL;
		section->next = NULL;
	}
	return (section);
}

static	t_data		*ft_config_new_data(char *data_name, char *data)
{
	t_data	*n_data;

	n_data = (t_data *)malloc(sizeof(t_data));
	if (n_data)
	{
		n_data->data_name = ft_strdup(data_name);
		n_data->data = ft_strdup(data);
		n_data->next = NULL;
	}
	return (n_data);
}

t_section		*ft_config_add_section(t_config *config, char *section_name)
{
	t_section	*tmp;
	int			section_exist;

	section_exist = 0;
	if (config->sections == NULL)
	{
		config->sections = ft_config_new_section(section_name);
		return (config->sections);
	}
	tmp = config->sections;
	while (tmp && section_exist == 0)
	{
		if (ft_strcmp(section_name, tmp->section_name) == 0)
			section_exist = 0;
		tmp = tmp->next;
	}
	if (config->sections && !section_exist)
	{
		tmp = config->sections;
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = ft_config_new_section(section_name);
		tmp = tmp->next;
	}
	return (tmp);
}

t_data			*ft_config_add_data(t_section *section, char *data_name, char *data)
{
	t_data		*tmp;
	int			data_exist;

	data_exist = 0;
	if (section->data == NULL)
	{
		section->data = ft_config_new_data(data_name, data);
		return(section->data);
	}
	tmp = section->data;
	while (tmp && data_exist == 0)
	{
		if (ft_strcmp(data_name, tmp->data_name) == 0)
			data_exist = 0;
		tmp = tmp->next;
	}
	if (section->data && !data_exist)
	{
		tmp = section->data;
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = ft_config_new_data(data_name, data);
		tmp = tmp->next;
	}
	return (tmp);
}