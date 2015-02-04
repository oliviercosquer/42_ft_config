/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 22:38:29 by olivier           #+#    #+#             */
/*   Updated: 2015/02/04 22:49:00 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_config.h>

//printf à remplacer!
void	ft_config_print_data(t_data *data)
{
	while (data)
	{
		printf("\t%s:%s\n", data->data_name, data->data);
		data = data->next;
	}
}

void	ft_config_print_section(t_section *sections)
{
	while (sections)
	{
		printf("%s\n", sections->section_name);
		ft_config_print_data(sections->data);
		sections = sections->next;
	}
}

void	ft_config_print(t_config *config)
{
	printf("filename:%s\n", config->filename);
	ft_config_print_section(config->sections);
}