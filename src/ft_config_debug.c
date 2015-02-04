/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 22:38:29 by olivier           #+#    #+#             */
/*   Updated: 2015/02/03 22:43:38 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_config.h>

void	ft_config_print(t_config *config)
{
	ft_printf("filename:%s\n", config->filename);
	ft_config_print_section(config->sections);
}

void	ft_config_print_section(t_section *sections)
{
	while (sections)
	{
		ft_printf("%s\n", sections->section_name);
		ft_config_print_data(sections->data);
		sections = sections->next;
	}
}

void	ft_config_print_data(t_data *data)
{
	while (data)
	{
		ft_printf("\t%s:%s\n", data->data_name, data->data);
		data = data->next;
	}
}