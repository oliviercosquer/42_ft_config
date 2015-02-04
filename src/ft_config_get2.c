/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_get2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 22:57:30 by olivier           #+#    #+#             */
/*   Updated: 2015/02/03 22:58:33 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_config.h>

static	t_data		*ft_config_get_data(t_data *data, char *data_name)
{
	t_data		*ret_data;

	ret_data = NULL;
	while (data && ret_data == NULL)
	{
		if (ft_strcmp(data->data_name, data_name) == 0)
			ret_data = data;
		data = data->next;
	}
	return (ret_data);
}

static	t_section	*ft_config_get_section(t_section *sections, char *section_name)
{
	t_section	*ret_section;

	ret_section = NULL;
	while (sections && !ret_section)
	{
		if (ft_strcmp(sections->section_name, section_name) == 0)
		{
			ret_section = sections;
		}
		else
		{
			sections = sections->next;
		}
	}
	return (ret_section);
}

t_data				*ft_config_get(t_config *config, char *path)
{
	char		*section_name;
	char		*data_name;
	t_section	*section;
	t_data		*data;

	printf("segv\n");
	section_name = ft_config_parse_section_name(path);
	printf("segv\n");
	data_name = ft_config_parse_data_name(path);
	printf("segv\n");
	section = ft_config_get_section(config->sections, section_name);
	printf("segv\n");
	ft_config_print_section(section);
	data = NULL;
	if (section)
	{
		data = ft_config_get_data(section->data, data_name);
	}
	if (section_name)
		ft_strdel(&section_name);
	if (data_name)
		ft_strdel(&data_name);
	return (data);
}