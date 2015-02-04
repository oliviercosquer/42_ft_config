/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 21:20:13 by olivier           #+#    #+#             */
/*   Updated: 2014/11/17 02:53:10 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_config.h>

t_config		*ft_config_new(char *filename)
{
	t_config	*config;

	config = NULL;
	config = (t_config *)malloc(sizeof(t_config));
	if (config)
	{
		config->sections = NULL;
		config->filename = ft_strdup(filename);
	}
	return (config);
}

void			ft_config_write(t_config *config, char *filename)
{
	(void)config;
	(void)filename;
	//@TODO
}

void			ft_config_update(t_config *config, char *data_path, char *data)
{
	(void)config;
	(void)data_path;
	(void)data;
	//@TODO
}